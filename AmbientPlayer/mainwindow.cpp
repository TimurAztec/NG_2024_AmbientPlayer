#include "mainwindow.h"
#include "soundeffectform.h"
#include "ui_mainwindow.h"
#include "utils/utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint);
    // setAttribute(Qt::WA_TranslucentBackground);
    // QPixmap pixmap(":/images/jukebox.png");
    // setMask(pixmap.mask());
    // ui->centralwidget->setStyleSheet("background-image: url(:/images/jukebox.png);");

    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    ambientComboBox = new SearchComboBox(this);
    soundEffectList = new SearchScrollArea(this);
    activeSoundEffectList = new SearchScrollArea(this);
    ui->horizontalLayout_2->addWidget(soundEffectList);
    ui->horizontalLayout_2->addWidget(activeSoundEffectList);
    ui->verticalLayout->addWidget(ambientComboBox);
    mediaPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(ui->sliderVolume->value());
    // ui->scrollAreaWidgetContents->setLayout(new QVBoxLayout(ui->scrollAreaWidgetContents));
    // ui->scrollAreaWidgetContents->layout()->setSizeConstraint(QLayout::SetMinAndMaxSize);

    connect (ui->sliderVolume, &QSlider::valueChanged, this, &MainWindow::updateVolume);
    connect (ambientComboBox, &SearchComboBox::currentTextChanged, this, &MainWindow::setAmbient);
    connect (ui->buttonPlayPause, &QPushButton::clicked, this, &MainWindow::playPause);
    connect (ui->buttonPlaySoundEffect, &QPushButton::clicked, this, &MainWindow::playSoundEffect);
    connect (ui->buttonAddSoundEffect, &QPushButton::clicked, this, &MainWindow::addSoundEffect);
    connect (ui->inputVolume, &QLineEdit::textEdited, this, [this](const QString &text) { ui->sliderVolume->setValue(text.toInt()); });

    QIntValidator *validator = new QIntValidator(ui->inputVolume);
    validator->setBottom(0);
    validator->setTop(100);
    ui->inputVolume->setValidator(validator);

    const QVector<QString> ambientFileList = Utils::lsFolder("./sounds/ambient/", QDir::Files);
    foreach (const QString &str, ambientFileList) {
        if (str.isEmpty())
            break;
        ambientComboBox->addItem(str);
    }

    const QVector<QString> soundEffectFileList = Utils::lsFolder("./sounds/effects/", QDir::Files);
    foreach (const QString &str, soundEffectFileList) {
        if (str.isEmpty())
            break;
        ui->comboBoxSoundEffect->addItem(str, QVariant(str));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playPause()
{
    if (mediaPlayer->isPlaying()) {
        mediaPlayer->pause();
        ui->buttonPlayPause->setText(">");
    } else {
        mediaPlayer->play();
        ui->buttonPlayPause->setText("||");
    }
}

void MainWindow::updateVolume(float volume)
{
    ui->inputVolume->setText(QString::number(volume));
    audioOutput->setVolume(volume/100);
}

void MainWindow::setAmbient()
{
    mediaPlayer->setSource(QUrl("./sounds/ambient/" + ambientComboBox->currentText() + ".mp3"));
    audioOutput->setVolume(ui->sliderVolume->value());
    ui->buttonPlayPause->setText(">");
}

void MainWindow::addSoundEffect()
{
    auto soundEffect = new SoundEffectForm(this, ui->comboBoxSoundEffect->currentText());
    soundEffect->setMinimumHeight(125);
    activeSoundEffectList->addWidget(soundEffect);
    // activeSoundEffectList->setWidgetResizable(true);
    // activeSoundEffectList->widget()->resize(ui->scrollArea->sizeHint());
}

void MainWindow::playSoundEffect()
{
    QMediaPlayer *mediaPlayer = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);

    mediaPlayer->setAudioOutput(audioOutput);
    mediaPlayer->setSource(QUrl("./sounds/effects/" + ui->comboBoxSoundEffect->currentText() + ".mp3"));
    mediaPlayer->play();

    connect(mediaPlayer, &QMediaPlayer::playbackStateChanged, this, [mediaPlayer, audioOutput](QMediaPlayer::PlaybackState state) {
        if (state == QMediaPlayer::StoppedState) {
            mediaPlayer->deleteLater();
            audioOutput->deleteLater();
        }
    });
}
