#ifndef SOUNDEFFECTDATA_H
#define SOUNDEFFECTDATA_H

#include "utils/soundeffectsettings.h"
#include <QString>

struct FileInfo {
    QString mp3FileName;
    QString imageFileName;
    double interval;
    bool shouldPlayOnce;
    int defaultVolume;
};

class SoundEffectData {
public:
    SoundEffectData() {}

    SoundEffectData(const QString& imagePath, const QString& filePath, const QString& name)
        : _imagePath(imagePath), _filePath(filePath), _name(name) {}

    QString imagePath() const { return _imagePath; }
    QString soundFilePath() const { return _filePath; }
    QString name() const { return _name; }
    SoundEffectSettings settings() const { return _settings; }

    void setImagePath(const QString& imagePath) { _imagePath = imagePath; }
    void setSoundFilePath(const QString& filePath) { _filePath = filePath; }
    void setName(const QString& name) { _name = name; }
    void setSettings(const SoundEffectSettings& settings) { _settings = settings; }
    void readFromJsonFile(const QString &filePath);


private:
    QString _imagePath;
    QString _filePath;
    QString _name;
    SoundEffectSettings _settings;
};

#endif // SOUNDEFFECTDATA_H
