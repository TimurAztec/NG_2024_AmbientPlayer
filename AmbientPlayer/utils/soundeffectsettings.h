#ifndef SOUNDEFFECTSETTINGS_H
#define SOUNDEFFECTSETTINGS_H

#include <QString>

class SoundEffectSettings {
public:
    SoundEffectSettings() {}

    SoundEffectSettings(const double& interval, const bool& playOnce)
        : _interval(interval), _playOnce(playOnce) {}

    double interval() const { return _interval; }
    bool shouldPlayOnce() const { return _playOnce; }
    int defaultVolume() const { return _defaultVolume; }

    void setInterval(const double& interval) { _interval = interval; }
    void setShouldPlayOnce(const bool& playOnce) { _playOnce = playOnce; }
    void setDefaultVolume(const int& defaultVolume) { _defaultVolume = defaultVolume; }

private:
    double _interval;
    bool _playOnce;
    int _defaultVolume;
};

#endif // SOUNDEFFECTSETTINGS_H
