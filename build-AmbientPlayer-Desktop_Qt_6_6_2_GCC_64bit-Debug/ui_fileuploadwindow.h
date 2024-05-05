/********************************************************************************
** Form generated from reading UI file 'fileuploadwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEUPLOADWINDOW_H
#define UI_FILEUPLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileUploadWindow
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *selectFilePushButton;
    QLabel *fileNameLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPushButton *selectImagePushButton;
    QLabel *imageNameLabel;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *intervalLineEdit;
    QLabel *label_4;
    QCheckBox *playOnceCheckBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QSlider *volumeHorizontalSlider;
    QLineEdit *volumeLineEdit;
    QPushButton *uploadButton;

    void setupUi(QWidget *FileUploadWindow)
    {
        if (FileUploadWindow->objectName().isEmpty())
            FileUploadWindow->setObjectName("FileUploadWindow");
        FileUploadWindow->resize(400, 189);
        widget = new QWidget(FileUploadWindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 0, 376, 181));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        selectFilePushButton = new QPushButton(widget);
        selectFilePushButton->setObjectName("selectFilePushButton");

        horizontalLayout->addWidget(selectFilePushButton);

        fileNameLabel = new QLabel(widget);
        fileNameLabel->setObjectName("fileNameLabel");

        horizontalLayout->addWidget(fileNameLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        selectImagePushButton = new QPushButton(widget);
        selectImagePushButton->setObjectName("selectImagePushButton");

        horizontalLayout_2->addWidget(selectImagePushButton);

        imageNameLabel = new QLabel(widget);
        imageNameLabel->setObjectName("imageNameLabel");

        horizontalLayout_2->addWidget(imageNameLabel);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        intervalLineEdit = new QLineEdit(widget);
        intervalLineEdit->setObjectName("intervalLineEdit");

        horizontalLayout_3->addWidget(intervalLineEdit);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        playOnceCheckBox = new QCheckBox(widget);
        playOnceCheckBox->setObjectName("playOnceCheckBox");

        horizontalLayout_3->addWidget(playOnceCheckBox);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        horizontalLayout_4->addWidget(label_5);

        volumeHorizontalSlider = new QSlider(widget);
        volumeHorizontalSlider->setObjectName("volumeHorizontalSlider");
        volumeHorizontalSlider->setValue(50);
        volumeHorizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(volumeHorizontalSlider);

        volumeLineEdit = new QLineEdit(widget);
        volumeLineEdit->setObjectName("volumeLineEdit");

        horizontalLayout_4->addWidget(volumeLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        uploadButton = new QPushButton(widget);
        uploadButton->setObjectName("uploadButton");

        verticalLayout_3->addWidget(uploadButton);


        retranslateUi(FileUploadWindow);

        QMetaObject::connectSlotsByName(FileUploadWindow);
    } // setupUi

    void retranslateUi(QWidget *FileUploadWindow)
    {
        FileUploadWindow->setWindowTitle(QCoreApplication::translate("FileUploadWindow", "Form", nullptr));
        label->setText(QCoreApplication::translate("FileUploadWindow", "File", nullptr));
        selectFilePushButton->setText(QCoreApplication::translate("FileUploadWindow", "Select", nullptr));
        fileNameLabel->setText(QCoreApplication::translate("FileUploadWindow", "File name", nullptr));
        label_2->setText(QCoreApplication::translate("FileUploadWindow", "Image", nullptr));
        selectImagePushButton->setText(QCoreApplication::translate("FileUploadWindow", "Select", nullptr));
        imageNameLabel->setText(QCoreApplication::translate("FileUploadWindow", "Image name", nullptr));
        label_3->setText(QCoreApplication::translate("FileUploadWindow", "Play interval", nullptr));
        intervalLineEdit->setText(QCoreApplication::translate("FileUploadWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("FileUploadWindow", "S", nullptr));
        playOnceCheckBox->setText(QCoreApplication::translate("FileUploadWindow", "Play only once", nullptr));
        label_5->setText(QCoreApplication::translate("FileUploadWindow", "Default volume", nullptr));
        volumeLineEdit->setText(QCoreApplication::translate("FileUploadWindow", "50", nullptr));
        uploadButton->setText(QCoreApplication::translate("FileUploadWindow", "Upload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileUploadWindow: public Ui_FileUploadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEUPLOADWINDOW_H
