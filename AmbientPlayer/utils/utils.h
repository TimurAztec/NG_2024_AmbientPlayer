#ifndef UTILS_H
#define UTILS_H

#include <QDir>
#include <QString>


class Utils
{
public:
    Utils();
    static QVector<QString> lsFolder(const QString &folderPath, const QDir::Filters filters);
};

#endif // UTILS_H
