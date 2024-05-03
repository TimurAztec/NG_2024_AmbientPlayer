#ifndef NAMEDQWIDGET_H
#define NAMEDQWIDGET_H

#include "qwidget.h"
#include <QString>

class NamedQWidget : QWidget
{
    Q_OBJECT

public:
    explicit NamedQWidget(QWidget *parent = nullptr, QString name = "");
    ~NamedQWidget();
    virtual QString name() const = 0;
    QWidget* getQWidget() {
        return this;
    }
};

#endif // NAMEDQWIDGET_H
