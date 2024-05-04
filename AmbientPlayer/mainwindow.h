#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qboxlayout.h"
#include "searchcombobox.h"
#include "searchscrollarea.h"
#include "utils/soundeffectdata.h"
#include "widgetlistview.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSlider>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *mediaPlayer;
    QAudioOutput *audioOutput;
    SearchComboBox *ambientComboBox;
    SearchScrollArea *soundEffectList;
    SearchScrollArea *activeSoundEffectList;

private slots:
    void playPause();
    void setAmbient();
    void updateVolume(float volume);
    void addSoundEffect(SoundEffectData *data);
    void removeSoundEffect(SoundEffectData *data);
    void playSoundEffect();
};
#endif // MAINWINDOW_H
