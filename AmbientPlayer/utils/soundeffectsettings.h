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

    void setInterval(const double& interval) { _interval = interval; }
    void setShouldPlayOnce(const bool& playOnce) { _playOnce = playOnce; }

private:
    double _interval;
    bool _playOnce;
};

#endif // SOUNDEFFECTSETTINGS_H
