#include "mainwindow.h"
#include "fileuploadwindow.h"
#include "soundeffectform.h"
#include "soundeffectselectform.h"
#include "ui_mainwindow.h"
#include "utils/soundeffectdata.h"
#include "utils/utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    trayIcon = new QSystemTrayIcon(this);
    QIcon icon(":/images/jukebox.png");
    trayIcon->setIcon(icon);
    setWindowIcon(icon);
    setWindowTitle("Ambient player");
    trayIcon->setToolTip("Ambient player");

    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    ambientComboBox = new SearchComboBox(this);
    soundEffectList = new SearchScrollArea(this);
    activeSoundEffectList = new SearchScrollArea(this);
    ui->horizontalLayout_2->addWidget(soundEffectList);
    ui->horizontalLayout_2->addWidget(activeSoundEffectList);
    ui->verticalLayout->addWidget(ambientComboBox);
    mediaPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(0);
    fileUploadWidget = new FileUploadWindow();
    fadeTimer = new QTimer(this);
    fadeTimer->setInterval(128);
    pause = true;

    trayMenu = new QMenu(this);
    QAction *openAction = new QAction("Open", this);
    QAction *quitAction = new QAction("Quit", this);
    connect(openAction, &QAction::triggered, this, &MainWindow::showNormal);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    trayMenu->addAction(openAction);
    trayMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayMenu);

    connect (ui->sliderVolume, &QSlider::valueChanged, this, &MainWindow::updateVolume);
    connect (ambientComboBox, &SearchComboBox::currentTextChanged, this, &MainWindow::setAmbient);
    connect (ui->buttonPlayPause, &QPushButton::clicked, this, &MainWindow::playPause);
    connect (ui->inputVolume, &QLineEdit::textEdited, this, [this](const QString &text) { ui->sliderVolume->setValue(text.toInt()); });
    connect (fadeTimer, &QTimer::timeout, this, &MainWindow::fade);
    connect (ui->actionAdd_sound, &QAction::triggered, this, [this]() { fileUploadWidget->show(); });
    connect (ui->actionAdd_ambient, &QAction::triggered, this, &MainWindow::addAmbient);
    connect (fileUploadWidget, &FileUploadWindow::widgetClosed, this, &MainWindow::updateSoundEffectList);
    connect (trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::trayIconActivated);

    QIntValidator *validator = new QIntValidator(ui->inputVolume);
    validator->setBottom(0);
    validator->setTop(100);
    ui->inputVolume->setValidator(validator);

    trayIcon->show();

    updateAmbientList();
    updateSoundEffectList();
    mediaPlayer->play();
    checkPause();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playPause()
{
    pause = !pause;
    checkPause();
}

void MainWindow::checkPause() {
    if (pause) {
        if (fadeTimer->isActive()) {
            fadeTimer->stop();
        }
        audioOutput->setVolume(0);
        ui->buttonPlayPause->setText("▶️");
    } else {
        fadeDirection = 1;
        fadeTimer->start();
        ui->buttonPlayPause->setText("⏸️");
    }
}

void MainWindow::updateSoundEffectList()
{
    soundEffectList->clearList();
    const QVector<QString> soundEffectFileList = Utils::lsFolder("./sounds/effects/",  QStringList() << "json", QDir::Files);
    foreach (const QString &str, soundEffectFileList) {
        if (str.isEmpty())
            break;
        auto data = new SoundEffectData();
        data->readFromJsonFile("./sounds/effects/" + str + ".json");
        auto soundEffect = new SoundEffectSelectForm(this, data);
        soundEffect->setMinimumHeight(30);
        soundEffectList->addWidget(soundEffect);
        connect(soundEffect, &SoundEffectSelectForm::widgetSelected, this, &MainWindow::addSoundEffect);
    }
}

void MainWindow::updateAmbientList()
{
    ambientComboBox->clear();
    const QVector<QString> ambientFileList = Utils::lsFolder("./sounds/ambient/",  QStringList() << "mp3", QDir::Files);
    foreach (const QString &str, ambientFileList) {
        if (str.isEmpty())
            break;
        ambientComboBox->addItem(str);
    }
}

void MainWindow::updateVolume(float volume)
{
    ui->inputVolume->setText(QString::number(volume));
    audioOutput->setVolume(volume/100);
}

void MainWindow::setAmbient()
{
    fadeInUrl = QUrl("./sounds/ambient/" + ambientComboBox->currentText() + ".mp3");
    if (fadeTimer->isActive()) {
        audioOutput->setVolume(0);
        fadeTimer->stop();
    }
    fadeDirection = -1;
    fadeTimer->start();
}

void MainWindow::addSoundEffect(SoundEffectData *data)
{
    auto soundEffect = new SoundEffectForm(this, data);
    soundEffect->setMinimumHeight(125);
    activeSoundEffectList->addWidget(soundEffect);
    connect(soundEffect, &SoundEffectForm::removeWidget, this, &MainWindow::removeSoundEffect);
    // activeSoundEffectList->setWidgetResizable(true);
    // activeSoundEffectList->widget()->resize(ui->scrollArea->sizeHint());
}

void MainWindow::addAmbient()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select MP3 File"), QDir::homePath(), tr("MP3 Files (*.mp3)"));
    if (!fileName.isEmpty()) {
        QFileInfo mp3FileInfo(fileName);
        QString mp3FileName = mp3FileInfo.fileName();

        QString destinationFolder = "./sounds/ambient";
        QString destinationMP3FilePath = destinationFolder + "/" + mp3FileName;
        QFile::copy(fileName, destinationMP3FilePath);

        updateAmbientList();
    }
}

void MainWindow::removeSoundEffect(SoundEffectData *data)
{
    auto soundEffect = new SoundEffectSelectForm(this, data);
    soundEffect->setMinimumHeight(30);
    soundEffectList->addWidget(soundEffect);
    connect(soundEffect, &SoundEffectSelectForm::widgetSelected, this, &MainWindow::addSoundEffect);
}

void MainWindow::fade() {
    double newVolume = audioOutput->volume() + fadeDirection * fadeStep;
    if (newVolume >= 0 && newVolume <= ui->inputVolume->text().toDouble()/100) {
        audioOutput->setVolume(newVolume);
    } else {
        fadeTimer->stop();
        if (!fadeInUrl.isEmpty()) {
            mediaPlayer->setSource(fadeInUrl);
            mediaPlayer->play();
            fadeDirection = 1;
            fadeInUrl = QUrl();
            fadeTimer->start();
            checkPause();
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    if (isVisible()) {
        hide();
        event->ignore();
    }
}

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason) {
    if (reason == QSystemTrayIcon::Trigger) {
        showNormal();
    }
}

// void MainWindow::playSoundEffect()
// {
    // QMediaPlayer *mediaPlayer = new QMediaPlayer(this);
    // QAudioOutput *audioOutput = new QAudioOutput(this);

    // mediaPlayer->setAudioOutput(audioOutput);
    // mediaPlayer->setSource(QUrl("./sounds/effects/" + ui->comboBoxSoundEffect->currentText() + ".mp3"));
    // mediaPlayer->play();

    // connect(mediaPlayer, &QMediaPlayer::playbackStateChanged, this, [mediaPlayer, audioOutput](QMediaPlayer::PlaybackState state) {
    //     if (state == QMediaPlayer::StoppedState) {
    //         mediaPlayer->deleteLater();
    //         audioOutput->deleteLater();
    //     }
    // });
// }
