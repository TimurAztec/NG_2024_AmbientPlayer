/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *main_ambient_label;
    QComboBox *comboBoxAmbient;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonPlayPause;
    QSlider *sliderVolume;
    QLineEdit *inputVolume;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBoxSoundEffect;
    QPushButton *buttonAddSoundEffect;
    QPushButton *buttonPlaySoundEffect;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(551, 507);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        main_ambient_label = new QLabel(centralwidget);
        main_ambient_label->setObjectName("main_ambient_label");
        main_ambient_label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(main_ambient_label);

        comboBoxAmbient = new QComboBox(centralwidget);
        comboBoxAmbient->setObjectName("comboBoxAmbient");

        verticalLayout->addWidget(comboBoxAmbient);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonPlayPause = new QPushButton(centralwidget);
        buttonPlayPause->setObjectName("buttonPlayPause");

        horizontalLayout->addWidget(buttonPlayPause);

        sliderVolume = new QSlider(centralwidget);
        sliderVolume->setObjectName("sliderVolume");
        sliderVolume->setValue(50);
        sliderVolume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderVolume);

        inputVolume = new QLineEdit(centralwidget);
        inputVolume->setObjectName("inputVolume");

        horizontalLayout->addWidget(inputVolume);


        verticalLayout_2->addLayout(horizontalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        comboBoxSoundEffect = new QComboBox(centralwidget);
        comboBoxSoundEffect->setObjectName("comboBoxSoundEffect");

        verticalLayout_4->addWidget(comboBoxSoundEffect);

        buttonAddSoundEffect = new QPushButton(centralwidget);
        buttonAddSoundEffect->setObjectName("buttonAddSoundEffect");

        verticalLayout_4->addWidget(buttonAddSoundEffect);

        buttonPlaySoundEffect = new QPushButton(centralwidget);
        buttonPlaySoundEffect->setObjectName("buttonPlaySoundEffect");

        verticalLayout_4->addWidget(buttonPlaySoundEffect);


        verticalLayout_3->addLayout(verticalLayout_4);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 531, 264));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 551, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        main_ambient_label->setText(QCoreApplication::translate("MainWindow", "Main ambient theme", nullptr));
        buttonPlayPause->setText(QCoreApplication::translate("MainWindow", "II", nullptr));
        inputVolume->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        buttonAddSoundEffect->setText(QCoreApplication::translate("MainWindow", "Add sound effect", nullptr));
        buttonPlaySoundEffect->setText(QCoreApplication::translate("MainWindow", "Play sound effect once", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
