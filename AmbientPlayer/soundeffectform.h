#ifndef SOUNDEFFECTFORM_H
#define SOUNDEFFECTFORM_H

#include "qmediaplayer.h"
#include <QWidget>
#include <QTimer>

namespace Ui {
class SoundEffectForm;
}

class SoundEffectForm : public QWidget
{
    Q_OBJECT

public:
    explicit SoundEffectForm(QWidget *parent = nullptr, QString name = "");
    ~SoundEffectForm();

private:
    Ui::SoundEffectForm *ui;
    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;
    QTimer *intervalTimer;

private slots:
    void playPause();
    void updateVolume(float volume);
    void checkRepeat(int state);
    void updateInterval(QString interval);
    void remove();
};

#endif // SOUNDEFFECTFORM_H
