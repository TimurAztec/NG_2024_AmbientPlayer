#ifndef SOUNDEFFECTFORM_H
#define SOUNDEFFECTFORM_H

#include "qmediaplayer.h"
#include "utils/soundeffectdata.h"
#include <QWidget>
#include <QTimer>

namespace Ui {
class SoundEffectForm;
}

class SoundEffectForm : public QWidget
{
    Q_OBJECT

public:
    explicit SoundEffectForm(QWidget *parent = nullptr, SoundEffectData *data = new SoundEffectData("", "", ""));
    ~SoundEffectForm();

private:
    Ui::SoundEffectForm *ui;
    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;
    QTimer *intervalTimer;
    SoundEffectData *data;
    QTimer *fadeTimer;
    int fadeDirection = 1; // 1 fade in -1 fade out
    double fadeStep = 0.05;

signals:
    void removeWidget(SoundEffectData *data);

private slots:
    void playPause();
    void updateVolume(float volume);
    void setInterval(double interval);
    void remove();
    void fade();
    void onPlaybackStateChanged(QMediaPlayer::PlaybackState state);
};

#endif // SOUNDEFFECTFORM_H
