#include "searchablecombobox.h"
#include "ui_searchablecombobox.h"

SearchableComboBox::SearchableComboBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchableComboBox)
{
    ui->setupUi(this);

    connect(ui->lineEdit, QLineEdit::textChanged, this, ui->comboBox.fil)
}

SearchableComboBox::~SearchableComboBox()
{
    delete ui;
}
