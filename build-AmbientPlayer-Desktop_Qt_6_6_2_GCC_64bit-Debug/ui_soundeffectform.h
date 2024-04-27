/********************************************************************************
** Form generated from reading UI file 'soundeffectform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDEFFECTFORM_H
#define UI_SOUNDEFFECTFORM_H

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

class Ui_SoundEffectForm
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBoxRepeat;
    QLineEdit *inputInterval;
    QLabel *labelSeconds;
    QPushButton *buttonRemove;
    QLabel *labelSoundEffectName;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonPlayPause;
    QSlider *sliderVolume;
    QLineEdit *inputVolume;

    void setupUi(QWidget *SoundEffectForm)
    {
        if (SoundEffectForm->objectName().isEmpty())
            SoundEffectForm->setObjectName("SoundEffectForm");
        SoundEffectForm->resize(421, 113);
        layoutWidget = new QWidget(SoundEffectForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(0, 0, 411, 101));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        checkBoxRepeat = new QCheckBox(layoutWidget);
        checkBoxRepeat->setObjectName("checkBoxRepeat");
        checkBoxRepeat->setChecked(true);

        horizontalLayout_2->addWidget(checkBoxRepeat);

        inputInterval = new QLineEdit(layoutWidget);
        inputInterval->setObjectName("inputInterval");

        horizontalLayout_2->addWidget(inputInterval);

        labelSeconds = new QLabel(layoutWidget);
        labelSeconds->setObjectName("labelSeconds");

        horizontalLayout_2->addWidget(labelSeconds);

        buttonRemove = new QPushButton(layoutWidget);
        buttonRemove->setObjectName("buttonRemove");

        horizontalLayout_2->addWidget(buttonRemove);

        labelSoundEffectName = new QLabel(layoutWidget);
        labelSoundEffectName->setObjectName("labelSoundEffectName");

        horizontalLayout_2->addWidget(labelSoundEffectName);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        buttonPlayPause = new QPushButton(layoutWidget);
        buttonPlayPause->setObjectName("buttonPlayPause");

        horizontalLayout->addWidget(buttonPlayPause);

        sliderVolume = new QSlider(layoutWidget);
        sliderVolume->setObjectName("sliderVolume");
        sliderVolume->setValue(50);
        sliderVolume->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(sliderVolume);

        inputVolume = new QLineEdit(layoutWidget);
        inputVolume->setObjectName("inputVolume");

        horizontalLayout->addWidget(inputVolume);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(SoundEffectForm);

        QMetaObject::connectSlotsByName(SoundEffectForm);
    } // setupUi

    void retranslateUi(QWidget *SoundEffectForm)
    {
        SoundEffectForm->setWindowTitle(QCoreApplication::translate("SoundEffectForm", "Form", nullptr));
        checkBoxRepeat->setText(QCoreApplication::translate("SoundEffectForm", "Repeat every", nullptr));
        inputInterval->setText(QCoreApplication::translate("SoundEffectForm", "10", nullptr));
        labelSeconds->setText(QCoreApplication::translate("SoundEffectForm", "seconds", nullptr));
        buttonRemove->setText(QCoreApplication::translate("SoundEffectForm", "Remove", nullptr));
        labelSoundEffectName->setText(QCoreApplication::translate("SoundEffectForm", "sound effect", nullptr));
        buttonPlayPause->setText(QCoreApplication::translate("SoundEffectForm", "II", nullptr));
        inputVolume->setText(QCoreApplication::translate("SoundEffectForm", "50", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SoundEffectForm: public Ui_SoundEffectForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDEFFECTFORM_H
