#ifndef SEARCHCOMBOBOX_H
#define SEARCHCOMBOBOX_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class SearchComboBox;
}

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
    Ui::SearchComboBox *ui;
    QStringList items;

private slots:
    void filterItems(const QString& text);
    void itemSelected();
};

#endif // SEARCHCOMBOBOX_H
