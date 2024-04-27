#ifndef SEARCHABLECOMBOBOX_H
#define SEARCHABLECOMBOBOX_H

#include <QWidget>

namespace Ui {
class SearchableComboBox;
}

class SearchableComboBox : public QWidget
{
    Q_OBJECT

public:
    explicit SearchableComboBox(QWidget *parent = nullptr);
    setItems(QStringList items);

    ~SearchableComboBox();

private:
    Ui::SearchableComboBox *ui;
};

#endif // SEARCHABLECOMBOBOX_H
