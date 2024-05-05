/********************************************************************************
** Form generated from reading UI file 'soundeffectselectform.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SOUNDEFFECTSELECTFORM_H
#define UI_SOUNDEFFECTSELECTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SoundEffectSelectForm
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *image;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *SoundEffectSelectForm)
    {
        if (SoundEffectSelectForm->objectName().isEmpty())
            SoundEffectSelectForm->setObjectName("SoundEffectSelectForm");
        SoundEffectSelectForm->resize(250, 45);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SoundEffectSelectForm->sizePolicy().hasHeightForWidth());
        SoundEffectSelectForm->setSizePolicy(sizePolicy);
        SoundEffectSelectForm->setMinimumSize(QSize(0, 30));
        layoutWidget = new QWidget(SoundEffectSelectForm);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 10, 231, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        image = new QLabel(layoutWidget);
        image->setObjectName("image");

        horizontalLayout->addWidget(image);

        label = new QLabel(layoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);


        retranslateUi(SoundEffectSelectForm);

        QMetaObject::connectSlotsByName(SoundEffectSelectForm);
    } // setupUi

    void retranslateUi(QWidget *SoundEffectSelectForm)
    {
        SoundEffectSelectForm->setWindowTitle(QCoreApplication::translate("SoundEffectSelectForm", "Form", nullptr));
        image->setText(QCoreApplication::translate("SoundEffectSelectForm", "Image", nullptr));
        label->setText(QCoreApplication::translate("SoundEffectSelectForm", "Label", nullptr));
        pushButton->setText(QCoreApplication::translate("SoundEffectSelectForm", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SoundEffectSelectForm: public Ui_SoundEffectSelectForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SOUNDEFFECTSELECTFORM_H
