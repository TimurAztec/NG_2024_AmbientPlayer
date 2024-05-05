#include "soundeffectselectform.h"
#include "ui_soundeffectselectform.h"

SoundEffectSelectForm::SoundEffectSelectForm(QWidget *parent, SoundEffectData *data)
    : QWidget(parent)
    , ui(new Ui::SoundEffectSelectForm)
{
    ui->setupUi(this);
    this->data = data;
    setProperty("name", data->name());

    qDebug() << data->imagePath();
    QPixmap pm(data->imagePath());
    ui->image->setPixmap(pm);
    ui->image->setScaledContents(true);
    ui->label->setText(data->name());

    connect(ui->pushButton, &QPushButton::clicked, this, &SoundEffectSelectForm::selectWidget);
}

SoundEffectData SoundEffectSelectForm::getData()
{
    return *data;
}

SoundEffectSelectForm::~SoundEffectSelectForm()
{
    delete ui;
}

void SoundEffectSelectForm::selectWidget() {
    emit widgetSelected(data);
    deleteLater();
}
