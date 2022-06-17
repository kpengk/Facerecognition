#include "apertureLayer.hpp"
#include "ui_apertureLayer.h"

ApertureLayer::ApertureLayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApertureLayer)
{
    ui->setupUi(this);
    ui->info_widget->setParent(this);// The default parent in UI files is ring_widget.
    ui->info_widget->move(115, 978);
}

ApertureLayer::~ApertureLayer()
{
    delete ui;
}

void ApertureLayer::set_controls_visible(ApertureLayer::Controls flag)
{
    const bool visible_pic{ flag.testFlag(ApertureLayer::info_pic) };
    const bool visible_name{ flag.testFlag(ApertureLayer::info_name) };
    const bool visible_temp{ flag.testFlag(ApertureLayer::info_temp) };

    ui->label_head_photo->setVisible(visible_pic);
    ui->label_name->setVisible(visible_name);
    ui->temperature_widget->setVisible(visible_temp);
    ui->info_widget->setVisible(visible_pic || visible_name || visible_temp);

    ui->ring_widget->setVisible(flag.testFlag(ApertureLayer::ring));
    ui->label_tip->setVisible(flag.testFlag(ApertureLayer::tip));
}

void ApertureLayer::set_mask_color(ApertureColor color)
{
    color_ = color;

    switch (color)
    {
    case ApertureColor::blue:
        ui->ring_widget->setStyleSheet("background-image: url(:/images/1x/Property_1_blue.png);");
        ui->info_widget->setStyleSheet("QWidget#info_widget{background-image: url(:/images/1x/mainInfo_blue.png);}");
        break;
    case ApertureColor::green:
        ui->ring_widget->setStyleSheet("background-image: url(:/images/1x/Property_1_green.png);");
        ui->info_widget->setStyleSheet("QWidget#info_widget{background-image: url(:/images/1x/mainInfo_green.png);}");
        ui->label_temperature_icon->setPixmap(QPixmap(":/images/1x/temperature_green.png"));
        ui->label_temperature_val->setStyleSheet(R"(color: rgba(39, 149, 15, 1);
                                                 font-family: Noto Sans SC; font-weight: bold; font-size: 32px;)");
        break;
    case ApertureColor::yellow:
        ui->ring_widget->setStyleSheet("background-image: url(:/images/1x/Property_1_yellow.png);");
        ui->info_widget->setStyleSheet("QWidget#info_widget{background-image: url(:/images/1x/mainInfo_yellow.png);}");
        ui->label_temperature_icon->setPixmap(QPixmap(":/images/1x/temperature_yellow.png"));
        ui->label_temperature_val->setStyleSheet(R"(color: rgba(211, 137, 19, 1);
                                                 font-family: Noto Sans SC; font-weight: bold; font-size: 32px;)");
        break;
    case ApertureColor::red:
        ui->ring_widget->setStyleSheet("background-image: url(:/images/1x/Property_1_red.png);");
        ui->info_widget->setStyleSheet("QWidget#info_widget{background-image: url(:/images/1x/mainInfo_red.png);}");
        break;
    default:
        break;
    }
}

void ApertureLayer::set_name(const QString &text)
{
    ui->label_name->setText(text);
}

void ApertureLayer::set_text(const QString &text)
{
    ui->label_name->setText(text);
}

void ApertureLayer::set_temperature(float value)
{
    ui->label_temperature_val->setText(QString("%1℃").arg(value, 0, 'f', 1));
}

void ApertureLayer::set_tip(const QString &tip)
{
    ui->label_tip->setText(tip);
}
