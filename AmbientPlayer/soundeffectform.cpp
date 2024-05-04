#include "soundeffectform.h"
#include "qaudiooutput.h"
#include "qvalidator.h"
#include "ui_soundeffectform.h"

SoundEffectForm::SoundEffectForm(QWidget *parent, SoundEffectData *data)
    : QWidget(parent)
    , ui(new Ui::SoundEffectForm)
{
    ui->setupUi(this);
    this->data = data;
    setProperty("name", data->name());
    ui->labelSoundEffectName->setText(data->name());
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    intervalTimer = new QTimer(this);
    mediaPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(0);
    fadeTimer = new QTimer(this);
    fadeTimer->setInterval(250);
    ui->sliderVolume->setValue(50);
    connect (ui->sliderVolume, &QSlider::valueChanged, this, &SoundEffectForm::updateVolume);
    connect (ui->buttonPlayPause, &QPushButton::clicked, this, &SoundEffectForm::playPause);
    connect (ui->buttonRemove, &QPushButton::clicked, this, &SoundEffectForm::remove);
    connect (ui->inputVolume, &QLineEdit::textEdited, this, [this](const QString &text) { ui->sliderVolume->setValue(text.toInt()); });
    connect (fadeTimer, &QTimer::timeout, this, &SoundEffectForm::fade);

    QIntValidator *volumeValidator = new QIntValidator(ui->inputVolume);
    volumeValidator->setBottom(0);
    volumeValidator->setTop(100);
    ui->inputVolume->setValidator(volumeValidator);

    // QDoubleValidator *intervalValidator = new QDoubleValidator(ui->inputInterval);
    // intervalValidator->setBottom(0);
    // ui->inputInterval->setValidator(intervalValidator);

    mediaPlayer->setSource(QUrl("./sounds/effects/" + data->name() + ".mp3"));
    mediaPlayer->play();
    fadeTimer->start();
    ui->buttonPlayPause->setText("||");
    checkRepeat((data->settings().shouldPlayOnce()) ? Qt::Checked : Qt::Unchecked);
    if (data->settings().interval()) {
        updateInterval(data->settings().interval());
    }

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
    ui->inputVolume->setText(QString::number(volume));
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

void SoundEffectForm::updateInterval(double interval)
{
    intervalTimer->setInterval(interval*1000);
}

void SoundEffectForm::remove()
{
    emit removeWidget(data);
    fadeDirection = -1;
    fadeTimer->start();
    setEnabled(false);
    setVisible(false);
}

void SoundEffectForm::fade() {
    double newVolume = audioOutput->volume() + fadeDirection * fadeStep;
    if (newVolume >= 0 && newVolume <= ui->inputVolume->text().toDouble()/100) {
        audioOutput->setVolume(newVolume);
    } else {
        fadeTimer->stop();
        if (fadeDirection == -1) {
            deleteLater();
        }
    }
}
