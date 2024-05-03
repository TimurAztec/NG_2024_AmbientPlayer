#include "soundeffectform.h"
#include "qaudiooutput.h"
#include "qvalidator.h"
#include "ui_soundeffectform.h"

SoundEffectForm::SoundEffectForm(QWidget *parent, QString name)
    : QWidget(parent)
    , ui(new Ui::SoundEffectForm)
{
    ui->setupUi(this);
    setProperty("name", name);
    ui->labelSoundEffectName->setText(name);
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    intervalTimer = new QTimer(this);
    mediaPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(ui->sliderVolume->value());

    connect (ui->sliderVolume, &QSlider::valueChanged, this, &SoundEffectForm::updateVolume);
    connect (ui->buttonPlayPause, &QPushButton::clicked, this, &SoundEffectForm::playPause);
    connect (ui->buttonRemove, &QPushButton::clicked, this, &SoundEffectForm::remove);
    connect (ui->inputVolume, &QLineEdit::textEdited, this, [this](const QString &text) { ui->sliderVolume->setValue(text.toInt()); });
    connect (ui->inputInterval, &QLineEdit::textEdited, this, &SoundEffectForm::updateInterval);
    connect (ui->checkBoxRepeat, &QCheckBox::stateChanged, this, &SoundEffectForm::checkRepeat);

    QIntValidator *volumeValidator = new QIntValidator(ui->inputVolume);
    volumeValidator->setBottom(0);
    volumeValidator->setTop(100);
    ui->inputVolume->setValidator(volumeValidator);

    QDoubleValidator *intervalValidator = new QDoubleValidator(ui->inputInterval);
    intervalValidator->setBottom(0);
    ui->inputInterval->setValidator(intervalValidator);

    mediaPlayer->setSource(QUrl("./sounds/effects/" + name + ".mp3"));
    mediaPlayer->play();
    ui->buttonPlayPause->setText("||");
    checkRepeat(Qt::CheckState::Checked);

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

SoundEffectForm::~SoundEffectForm()
{
    delete ui;
}

void SoundEffectForm::playPause()
{
    if (mediaPlayer->isPlaying()) {
        mediaPlayer->pause();
        ui->buttonPlayPause->setText(">");
    } else {
        mediaPlayer->play();
        ui->buttonPlayPause->setText("||");
    }
}

void SoundEffectForm::updateVolume(float volume)
{
    audioOutput->setVolume(volume/100);
}

void SoundEffectForm::checkRepeat(int state)
{
    if (state == Qt::CheckState::Checked) {
        QObject::connect(intervalTimer, &QTimer::timeout, [=]() {
            mediaPlayer->setPosition(0);
        });
        intervalTimer->start();
    }

    if (state == Qt::CheckState::Unchecked) {
        intervalTimer->stop();
    }
}

void SoundEffectForm::updateInterval(QString interval)
{
    intervalTimer->setInterval(interval.toDouble()*1000);
}

void SoundEffectForm::remove()
{
    deleteLater();
}
