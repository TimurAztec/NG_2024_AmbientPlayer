#ifndef WIDGETLISTVIEW_H
#define WIDGETLISTVIEW_H

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>
#include <QStandardItem>

class WidgetListView : public QListView
{
    Q_OBJECT
public:
    explicit WidgetListView(QWidget *parent = nullptr);
    void addWidget(QWidget *widget);
protected:
    QStandardItemModel *model;
signals:
};

#endif // WIDGETLISTVIEW_H
