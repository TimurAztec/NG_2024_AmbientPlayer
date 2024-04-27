/********************************************************************************
** Form generated from reading UI file 'searchablecombobox.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHABLECOMBOBOX_H
#define UI_SEARCHABLECOMBOBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchableComboBox
{
public:
    QLineEdit *lineEdit;
    QComboBox *comboBox;

    void setupUi(QWidget *SearchableComboBox)
    {
        if (SearchableComboBox->objectName().isEmpty())
            SearchableComboBox->setObjectName("SearchableComboBox");
        SearchableComboBox->resize(400, 50);
        lineEdit = new QLineEdit(SearchableComboBox);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(0, 0, 391, 21));
        comboBox = new QComboBox(SearchableComboBox);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(0, 20, 391, 24));

        retranslateUi(SearchableComboBox);

        QMetaObject::connectSlotsByName(SearchableComboBox);
    } // setupUi

    void retranslateUi(QWidget *SearchableComboBox)
    {
        SearchableComboBox->setWindowTitle(QCoreApplication::translate("SearchableComboBox", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchableComboBox: public Ui_SearchableComboBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHABLECOMBOBOX_H
