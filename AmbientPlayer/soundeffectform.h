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

signals:
    void removeWidget(SoundEffectData *data);

private slots:
    void playPause();
    void updateVolume(float volume);
    void checkRepeat(int state);
    void updateInterval(double interval);
    void remove();
};

#endif // SOUNDEFFECTFORM_H
