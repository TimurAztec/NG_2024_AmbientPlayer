#ifndef SEARCHSCROLLAREA_H
#define SEARCHSCROLLAREA_H

#include "qboxlayout.h"
#include "qlineedit.h"
#include <QWidget>

namespace Ui {
class SearchScrollArea;
}

class SearchScrollArea : public QWidget
{
    Q_OBJECT

public:
    explicit SearchScrollArea(QWidget *parent = nullptr);
    ~SearchScrollArea();
    void setWidgets(const QList<QWidget*>& widgets);
    void addWidget(QWidget* widget);
    void removeWidget(QWidget* widget);
    void clearList();

signals:
    void widgetSelected(const QString& name);

private slots:
    void filterWidgets();

private:
    Ui::SearchScrollArea *ui;
    QList<QWidget*> widgets;
    QTimer* filterTimer;

    void connectWidgetSignals(QWidget* widget);
};

#endif // SEARCHSCROLLAREA_H
