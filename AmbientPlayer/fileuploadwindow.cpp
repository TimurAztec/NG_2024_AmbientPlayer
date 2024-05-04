#include "fileuploadwindow.h"
#include "qvalidator.h"
#include "ui_fileuploadwindow.h"

struct FileInfo {
    QString mp3FileName;
    QString imageFileName;
    double interval;
    bool shouldPlayOnce;
    int defaultVolume;
};

FileUploadWindow::FileUploadWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileUploadWindow)
{
    ui->setupUi(this);

    QIntValidator *volumeValidator = new QIntValidator(ui->volumeLineEdit);
    volumeValidator->setBottom(0);
    volumeValidator->setTop(100);
    ui->volumeLineEdit->setValidator(volumeValidator);

    QDoubleValidator *intervalValidator = new QDoubleValidator(ui->intervalLineEdit);
    intervalValidator->setBottom(0);
    ui->intervalLineEdit->setValidator(intervalValidator);

    connect (ui->selectFilePushButton, &QPushButton::clicked, this, &FileUploadWindow::selectFile);
    connect (ui->selectImagePushButton, &QPushButton::clicked, this, &FileUploadWindow::selectImage);
    connect (ui->uploadButton, &QPushButton::clicked, this, &FileUploadWindow::uploadFile);
    connect (ui->volumeHorizontalSlider, &QSlider::valueChanged, this, &FileUploadWindow::updateVolume);
    connect (ui->volumeLineEdit, &QLineEdit::textEdited, this, [this](const QString &text) { ui->volumeHorizontalSlider->setValue(text.toInt()); });
}

FileUploadWindow::~FileUploadWindow()
{
    delete ui;
}

void FileUploadWindow::updateVolume(float volume)
{
    ui->volumeLineEdit->setText(QString::number(volume));
}

void FileUploadWindow::selectFile()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Select MP3 File"), QDir::homePath(), tr("MP3 Files (*.mp3)"));
    ui->fileNameLabel->setText(fileName);
}

void FileUploadWindow::selectImage()
{
    imageName = QFileDialog::getOpenFileName(this, tr("Select image file"), QDir::homePath(), tr("Files (*.jpg *.jpeg *.png *.gif *.bmp *.ico)"));
    ui->imageNameLabel->setText(imageName);
}

void FileUploadWindow::uploadFile()
{
    if (!fileName.isEmpty() && !imageName.isEmpty()) {
        QFileInfo mp3FileInfo(fileName);
        QString mp3FileName = mp3FileInfo.fileName();
        QString mp3Extension = mp3FileInfo.suffix();

        QFileInfo imageFileInfo(imageName);
        QString imageFileName = imageFileInfo.fileName();
        QString imageExtension = imageFileInfo.suffix();

        QString destinationFolder = "./sounds/effects";
        QString destinationMP3FilePath = destinationFolder + "/" + mp3FileName;
        QFile::copy(fileName, destinationMP3FilePath);

        QString renamedImageFileName = mp3FileName.replace("." + mp3Extension, "") + "." + imageExtension;
        QString destinationImageFilePath = destinationFolder + "/" + renamedImageFileName;

        QFile::copy(imageName, destinationImageFilePath);

        FileInfo fileInfo;
        fileInfo.mp3FileName = mp3FileName;
        fileInfo.imageFileName = renamedImageFileName;
        fileInfo.interval = ui->intervalLineEdit->text().toDouble();
        fileInfo.shouldPlayOnce = ui->playOnceCheckBox->checkState();
        fileInfo.defaultVolume = ui->volumeLineEdit->text().toInt();

        QJsonObject jsonObject;
        jsonObject["mp3FileName"] = fileInfo.mp3FileName;
        jsonObject["imageFileName"] = fileInfo.imageFileName;
        jsonObject["interval"] = fileInfo.interval;
        jsonObject["shouldPlayOnce"] = fileInfo.shouldPlayOnce;
        jsonObject["defaultVolume"] = fileInfo.defaultVolume;

        QJsonDocument jsonDoc(jsonObject);
        QByteArray jsonData = jsonDoc.toJson();

        QString jsonFilePath = destinationFolder + "/" + mp3FileName.replace("." + mp3Extension, "") + ".json";
        QFile jsonFile(jsonFilePath);
        jsonFile.open(QFile::WriteOnly | QFile::Text);
        jsonFile.write(jsonData);
        jsonFile.close();

        emit widgetClosed();
        close();
    }
}
