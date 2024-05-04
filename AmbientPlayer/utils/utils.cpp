#include "utils.h"
#include "qwidget.h"
#include <QDir>
#include <QString>
#include <QVector>

Utils::Utils() {}

QVector<QString> Utils::lsFolder(const QString &folderPath, const QDir::Filters filters = QDir::NoFilter)
{
    QVector<QString> fileList;
    QDir directory(folderPath);

    if (!directory.exists()) {
        qDebug() << "Folder does not exist: " << folderPath;
        return fileList;
    }

    directory.setFilter(filters);
    QFileInfoList fileInfoList = directory.entryInfoList();

    foreach (QFileInfo fileInfo, fileInfoList) {
        fileList.push_back(fileInfo.baseName());
    }

    return fileList;
}

void Utils::removeAllChildWidgets(QWidget *parentWidget)
{
    if (!parentWidget) return;

    QList<QWidget *> widgets = parentWidget->findChildren<QWidget *>();
    if (widgets.isEmpty()) return;
    for (QWidget *widget : widgets) {
        widget->deleteLater();
    }
}
