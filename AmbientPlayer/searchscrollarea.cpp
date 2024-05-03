#include "searchscrollarea.h"
#include "qtimer.h"
#include "ui_searchscrollarea.h"

SearchScrollArea::SearchScrollArea(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SearchScrollArea)
{
    ui->setupUi(this);

    QWidget* scrollWidget = new QWidget(this);
    QVBoxLayout* scrollLayout = new QVBoxLayout(scrollWidget);
    scrollLayout->setAlignment(Qt::AlignTop);
    scrollWidget->setLayout(scrollLayout);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(scrollWidget);
    ui->scrollArea->widget()->layout()->setSizeConstraint(QLayout::SetMinAndMaxSize);

    filterTimer = new QTimer(this);
    filterTimer->setInterval(300);

    connect(ui->lineEdit, &QLineEdit::textChanged, this, &SearchScrollArea::filterWidgets);
    connect(filterTimer, &QTimer::timeout, this, &SearchScrollArea::filterWidgets);
}

SearchScrollArea::~SearchScrollArea()
{
    delete ui;
}

void SearchScrollArea::setWidgets(const QList<QWidget*>& widgets)
{
    for (QWidget* widget : this->widgets)
    {
        ui->scrollArea->widget()->layout()->removeWidget(widget);
        delete widget;
    }
    this->widgets = widgets;

    for (QWidget* widget : widgets)
    {
        connectWidgetSignals(widget);
        ui->scrollArea->widget()->layout()->addWidget(widget);
    }
}

void SearchScrollArea::addWidget(QWidget* widget)
{
    widgets.append(widget);
    connectWidgetSignals(widget);
    ui->scrollArea->widget()->layout()->addWidget(widget);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->widget()->resize(ui->scrollArea->sizeHint());
}

void SearchScrollArea::removeWidget(QWidget* widget)
{
    widgets.removeAll(widget);
    ui->scrollArea->widget()->layout()->removeWidget(widget);
    delete widget;
}

void SearchScrollArea::connectWidgetSignals(QWidget* widget)
{
    QObject::connect(widget, &QWidget::customContextMenuRequested, [=]() {
        emit widgetSelected(widget->property("name").toString());
    });
}

void SearchScrollArea::filterWidgets()
{
    QString searchText = ui->lineEdit->text().trimmed().toLower();

    for (QWidget* widget : widgets)
    {
        QString widgetName = widget->property("name").toString().toLower();
        widget->setVisible(widgetName.contains(searchText));
    }
}
