#include "searchcombobox.h"
#include "qboxlayout.h"
#include "ui_searchcombobox.h"

SearchComboBox::SearchComboBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchComboBox)
{
    ui->setupUi(this);

    ui->lineEdit = new QLineEdit(this);
    ui->lineEdit->setPlaceholderText("Search 🔍");

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &SearchComboBox::filterItems);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &SearchComboBox::itemSelected);
}

SearchComboBox::~SearchComboBox()
{
    delete ui;
}

void SearchComboBox::setItems(const QStringList& items) {
    this->items = items;
    QStringListModel *model = new QStringListModel(items, this);
    ui->comboBox->setModel(model);
}

void SearchComboBox::addItem(const QString& item) {
    items.append(item);
    QStringListModel *model = qobject_cast<QStringListModel*>(ui->comboBox->model());
    if (model) {
        model->setStringList(items);
    }
    ui->comboBox->addItem(item);
}

void SearchComboBox::removeItem(const QString& item) {
    items.removeAll(item);
    QStringListModel *model = qobject_cast<QStringListModel*>(ui->comboBox->model());
    if (model) {
        model->setStringList(items);
    }
}

void SearchComboBox::itemSelected() {
    emit currentTextChanged();
}

QString SearchComboBox::currentText() const {
    return ui->comboBox->currentText();
}

void SearchComboBox::filterItems(const QString& text)
{
    QStringList filteredItems;
    for (const QString& item : items) {
        if (item.contains(text, Qt::CaseInsensitive))
            filteredItems.append(item);
    }
    ui->comboBox->clear();
    ui->comboBox->addItems(filteredItems);
}
