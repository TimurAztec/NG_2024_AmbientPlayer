/********************************************************************************
** Form generated from reading UI file 'searchscrollarea.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHSCROLLAREA_H
#define UI_SEARCHSCROLLAREA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SearchScrollArea
{
public:
    QLineEdit *lineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *SearchScrollArea)
    {
        if (SearchScrollArea->objectName().isEmpty())
            SearchScrollArea->setObjectName("SearchScrollArea");
        SearchScrollArea->resize(400, 300);
        lineEdit = new QLineEdit(SearchScrollArea);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(0, 0, 391, 21));
        scrollArea = new QScrollArea(SearchScrollArea);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 20, 391, 261));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 389, 259));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(SearchScrollArea);

        QMetaObject::connectSlotsByName(SearchScrollArea);
    } // setupUi

    void retranslateUi(QWidget *SearchScrollArea)
    {
        SearchScrollArea->setWindowTitle(QCoreApplication::translate("SearchScrollArea", "Form", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("SearchScrollArea", "Search \360\237\224\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SearchScrollArea: public Ui_SearchScrollArea {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHSCROLLAREA_H
