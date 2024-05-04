#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fileuploadwindow.h"
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
    QTimer *fadeTimer;
    FileUploadWindow *fileUploadWidget;
    bool pause;
    QUrl fadeInUrl;
    int fadeDirection = 1; // 1 fade in -1 fade out
    double fadeStep = 0.05;

private slots:
    void playPause();
    void checkPause();
    void setAmbient();
    void updateVolume(float volume);
    void addSoundEffect(SoundEffectData *data);
    void removeSoundEffect(SoundEffectData *data);
    void playSoundEffect();
    void updateSoundEffectList();
    void fade();
};
#endif // MAINWINDOW_H
