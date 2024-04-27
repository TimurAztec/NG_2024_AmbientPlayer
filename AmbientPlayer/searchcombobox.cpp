#include "searchcombobox.h"
#include "qboxlayout.h"

SearchComboBox::SearchComboBox(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Search 🔍");
    comboBox = new QComboBox(this);

    layout->addWidget(lineEdit);
    layout->addWidget(comboBox);

    connect(lineEdit, &QLineEdit::textChanged, this, &SearchComboBox::filterItems);
    connect(comboBox, &QComboBox::currentTextChanged, this, &SearchComboBox::itemSelected);

    setLayout(layout);
}

SearchComboBox::~SearchComboBox()
{

}

void SearchComboBox::setItems(const QStringList& items) {
    this->items = items;
    QStringListModel *model = new QStringListModel(items, this);
    comboBox->setModel(model);
}

void SearchComboBox::addItem(const QString& item) {
    items.append(item);
    QStringListModel *model = qobject_cast<QStringListModel*>(comboBox->model());
    if (model) {
        model->setStringList(items);
    }
    comboBox->addItem(item);
}

void SearchComboBox::removeItem(const QString& item) {
    items.removeAll(item);
    QStringListModel *model = qobject_cast<QStringListModel*>(comboBox->model());
    if (model) {
        model->setStringList(items);
    }
}

void SearchComboBox::itemSelected() {
    emit currentTextChanged();
}

QString SearchComboBox::currentText() const {
    return comboBox->currentText();
}

void SearchComboBox::filterItems(const QString& text)
{
    QStringList filteredItems;
    for (const QString& item : items) {
        if (item.contains(text, Qt::CaseInsensitive))
            filteredItems.append(item);
    }
    comboBox->clear();
    comboBox->addItems(filteredItems);
}
