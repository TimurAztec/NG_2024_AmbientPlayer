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
    connect (ui->sliderVolume, &QSlider::valueChanged, this, &SoundEffectForm::updateVolume);
    connect (ui->buttonPlayPause, &QPushButton::clicked, this, &SoundEffectForm::playPause);
    connect (ui->buttonRemove, &QPushButton::clicked, this, &SoundEffectForm::remove);
    connect (ui->inputVolume, &QLineEdit::textEdited, this, [this](const QString &text) { ui->sliderVolume->setValue(text.toInt()); });
    setProperty("name", data->name());
    ui->labelSoundEffectName->setText(data->name());
    QPixmap pm(data->imagePath());
    ui->image->setPixmap(pm);
    ui->image->setScaledContents(true);
    mediaPlayer = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    intervalTimer = new QTimer(this);
    mediaPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(0);
    fadeTimer = new QTimer(this);
    fadeTimer->setInterval(250);

    connect (fadeTimer, &QTimer::timeout, this, &SoundEffectForm::fade);
    connect (mediaPlayer, &QMediaPlayer::playbackStateChanged, this, &SoundEffectForm::onPlaybackStateChanged);

    QIntValidator *volumeValidator = new QIntValidator(ui->inputVolume);
    volumeValidator->setBottom(0);
    volumeValidator->setTop(100);
    ui->inputVolume->setValidator(volumeValidator);

    mediaPlayer->setSource(QUrl("./sounds/effects/" + data->name() + ".mp3"));
    mediaPlayer->play();
    fadeTimer->start();
    ui->sliderVolume->setValue(data->settings().defaultVolume());
    if (data->settings().shouldPlayOnce()) {
        ui->buttonPlayPause->hide();
    }
    if (data->settings().interval() && !data->settings().shouldPlayOnce()) {
        setInterval(data->settings().interval());
    }

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
}

SoundEffectForm::~SoundEffectForm()
{
    delete ui;
}

void SoundEffectForm::playPause()
{
    if (intervalTimer->isActive()) {
        intervalTimer->stop();
        ui->buttonPlayPause->setText("▶️");
    } else {
        intervalTimer->start();
        ui->buttonPlayPause->setText("⏸️");
    }
}

void SoundEffectForm::updateVolume(float volume)
{
    audioOutput->setVolume(volume/100);
    ui->inputVolume->setText(QString::number(volume));
}

void SoundEffectForm::setInterval(double interval)
{
    intervalTimer->setInterval(interval*1000);
    QObject::connect(intervalTimer, &QTimer::timeout, [=]() {
        mediaPlayer->setPosition(0);
        mediaPlayer->play();
    });
    intervalTimer->start();
}

void SoundEffectForm::remove()
{
    emit removeWidget(data);
    fadeDirection = -1;
    fadeTimer->start();
    setEnabled(false);
    setVisible(false);
    if (intervalTimer->isActive()) {
        intervalTimer->stop();
    }
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

void SoundEffectForm::onPlaybackStateChanged(QMediaPlayer::PlaybackState state) {
    qDebug() << state << "|" << data->settings().shouldPlayOnce();
    if (state == QMediaPlayer::StoppedState && data->settings().shouldPlayOnce()) {
        remove();
    }
}
