#ifndef SEARCHCOMBOBOX_H
#define SEARCHCOMBOBOX_H

#include "qcombobox.h"
#include "qlineedit.h"
#include <QWidget>
#include <QStringListModel>

class SearchComboBox : public QWidget
{
    Q_OBJECT

public:
    SearchComboBox(QWidget *parent = nullptr);
    ~SearchComboBox();
    void setItems(const QStringList& items);
    void addItem(const QString& item);
    void removeItem(const QString& item);
    QString currentText() const;

signals:
    void currentTextChanged();

private:
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QStringList items;

private slots:
    void filterItems(const QString& text);
    void itemSelected();
};

#endif // SEARCHCOMBOBOX_H
