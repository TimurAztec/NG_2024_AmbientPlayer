#include "widgetlistview.h"
#include "qboxlayout.h"

WidgetListView::WidgetListView(QWidget *parent)
    : QListView{parent}
{
    model = new QStandardItemModel(this);
    setModel(model);
}

void WidgetListView::addWidget(QWidget *widget)
{
    QWidget *container = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout(container);
    layout->addWidget(widget);
    layout->setContentsMargins(0, 0, 0, 0);
    container->setLayout(layout);

    QSize size = widget->sizeHint();
    container->setFixedSize(size);

    QStandardItem *item = new QStandardItem();
    model->appendRow(item);
    setIndexWidget(model->index(model->rowCount() - 1, 0), container);
}
