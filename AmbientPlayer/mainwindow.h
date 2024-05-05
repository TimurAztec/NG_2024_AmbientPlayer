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
#include <QSystemTrayIcon>
#include <QCloseEvent>

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
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    void closeEvent(QCloseEvent *event) override;

private slots:
    void playPause();
    void checkPause();
    void setAmbient();
    void updateVolume(float volume);
    void addSoundEffect(SoundEffectData *data);
    void addAmbient();
    void removeSoundEffect(SoundEffectData *data);
    void updateSoundEffectList();
    void updateAmbientList();
    void fade();
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
};
#endif // MAINWINDOW_H
