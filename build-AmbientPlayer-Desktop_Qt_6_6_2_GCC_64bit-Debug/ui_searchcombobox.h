/********************************************************************************
** Form generated from reading UI file 'searchcombobox.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHCOMBOBOX_H
#define UI_SEARCHCOMBOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchComboBox
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QComboBox *comboBox;

    void setupUi(QWidget *SearchComboBox)
    {
        if (SearchComboBox->objectName().isEmpty())
            SearchComboBox->setObjectName("SearchComboBox");
        SearchComboBox->resize(425, 71);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SearchComboBox->sizePolicy().hasHeightForWidth());
        SearchComboBox->setSizePolicy(sizePolicy);
        SearchComboBox->setMinimumSize(QSize(0, 70));
        widget = new QWidget(SearchComboBox);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(11, 1, 401, 55));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName("comboBox");

        gridLayout->addWidget(comboBox, 1, 0, 1, 1);


        retranslateUi(SearchComboBox);

        QMetaObject::connectSlotsByName(SearchComboBox);
    } // setupUi

    void retranslateUi(QWidget *SearchComboBox)
    {
        SearchComboBox->setWindowTitle(QCoreApplication::translate("SearchComboBox", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("SearchComboBox", "Search \360\237\224\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchComboBox: public Ui_SearchComboBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHCOMBOBOX_H
