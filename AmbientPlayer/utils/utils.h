#ifndef UTILS_H
#define UTILS_H

#include <QDir>
#include <QString>


class Utils
{
public:
    Utils();
    static QVector<QString> lsFolder(const QString &folderPath, const QStringList &fileExtensions, const QDir::Filters &filters);
    static void removeAllChildWidgets(QWidget *parentWidget);
};

#endif // UTILS_H
