#include "utils/soundeffectdata.h"
#include "qjsondocument.h"
#include "qjsonobject.h"
#include <QDir>
#include <QString>
#include <QVector>

void SoundEffectData::readFromJsonFile(const QString &filePath)
{
    QFile jsonFile(filePath);
    if (!jsonFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open JSON file:" << jsonFile.errorString();
        return;
    }

    QByteArray jsonData = jsonFile.readAll();
    jsonFile.close();

    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData, &error);
    if (jsonDoc.isNull()) {
        qDebug() << "Failed to parse JSON data:" << error.errorString();
        return;
    }

    if (!jsonDoc.isObject()) {
        qDebug() << "JSON data is not an object";
        return;
    }

    QJsonObject jsonObject = jsonDoc.object();
    setName(jsonObject["mp3FileName"].toString());
    setImagePath("./sounds/effects/" + jsonObject["imageFileName"].toString());
    SoundEffectSettings settings;
    settings.setInterval(jsonObject["interval"].toInt());
    settings.setShouldPlayOnce(jsonObject["shouldPlayOnce"].toBool());
    settings.setDefaultVolume(jsonObject["defaultVolume"].toDouble());
    setSettings(settings);
}
