#ifndef SOUNDEFFECTSELECTFORM_H
#define SOUNDEFFECTSELECTFORM_H

#include "utils/soundeffectdata.h"
#include <QWidget>

namespace Ui {
class SoundEffectSelectForm;
}

class SoundEffectSelectForm : public QWidget
{
    Q_OBJECT

public:
    explicit SoundEffectSelectForm(QWidget *parent = nullptr, SoundEffectData *data = new SoundEffectData("", "", ""));
    ~SoundEffectSelectForm();
    SoundEffectData getData();

signals:
    void widgetSelected(SoundEffectData *data);

private slots:
    void selectWidget();

private:
    Ui::SoundEffectSelectForm *ui;
    SoundEffectData *data;

};

#endif // SOUNDEFFECTSELECTFORM_H
