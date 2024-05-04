#ifndef FILEUPLOADWINDOW_H
#define FILEUPLOADWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>

namespace Ui {
class FileUploadWindow;
}

class FileUploadWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FileUploadWindow(QWidget *parent = nullptr);
    ~FileUploadWindow();

private:
    Ui::FileUploadWindow *ui;
    QString fileName;
    QString imageName;

signals:
    void widgetClosed();

private slots:
    void selectFile();
    void selectImage();
    void uploadFile();
    void updateVolume(float volume);
};

#endif // FILEUPLOADWINDOW_H
