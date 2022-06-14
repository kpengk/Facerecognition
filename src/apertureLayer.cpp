#include "apertureLayer.hpp"
#include "ui_apertureLayer.h"

#include <QTimer>

ApertureLayer::ApertureLayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ApertureLayer)
{
    ui->setupUi(this);

    set_mask_color(MaskColor::green);
    set_tip_visble(false);
}

ApertureLayer::~ApertureLayer()
{
    delete ui;
}

void ApertureLayer::set_aperture_visible(bool visible)
{
    ui->aperture_widget->setVisible(visible);
}

void ApertureLayer::set_ring_visible(bool visible)
{
    if (visible)
        set_mask_color(color_mode_);
    else
        ui->aperture_widget->setStyleSheet({});
}

void ApertureLayer::set_tip_visble(bool visible)
{
    ui->label_tip->setVisible(visible);
}

void ApertureLayer::set_mask_color(MaskColor color)
{
    color_mode_ = color;

    switch (color)
    {
    case MaskColor::blue:
        ui->aperture_widget->setStyleSheet("background-image: url(:/images/1x/Property_1_blue.png);");
        ui->info_widget->setStyleSheet("QWidget#info_widget{background-image: url(:/images/1x/mainInfo_blue.png);}");
        ui->label_head_photo->setVisible(false);
        ui->label_name->setText("正在识别...");
        ui->temperature_widget->setVisible(false);
        break;
    case MaskColor::green:
        ui->aperture_widget->setStyleSheet("background-image: url(:/images/1x/Property_1_green.png);");
        ui->info_widget->setStyleSheet("QWidget#info_widget{background-image: url(:/images/1x/mainInfo_green.png);}");
        ui->label_head_photo->setVisible(true);
        ui->label_name->setText("李*六");
        ui->temperature_widget->setVisible(true);
        ui->label_temperature_icon->setPixmap(QPixmap(":/images/1x/temperature_green.png"));
        ui->label_temperature_val->setStyleSheet(R"(color: rgba(39, 149, 15, 1);
                                                 font-family: Noto Sans SC; font-weight: bold; font-size: 32px;)");
        break;
    case MaskColor::yellow:
        ui->aperture_widget->setStyleSheet("background-image: url(:/images/1x/Property_1_yellow.png);");
        ui->info_widget->setStyleSheet("QWidget#info_widget{background-image: url(:/images/1x/mainInfo_yellow.png);}");
        ui->label_head_photo->setVisible(true);
        ui->label_name->setText("李*六");
        ui->temperature_widget->setVisible(true);
        ui->label_temperature_icon->setPixmap(QPixmap(":/images/1x/temperature_yellow.png"));
        ui->label_temperature_val->setStyleSheet(R"(color: rgba(211, 137, 19, 1);
                                                 font-family: Noto Sans SC; font-weight: bold; font-size: 32px;)");
        break;
    case MaskColor::red:
        ui->aperture_widget->setStyleSheet("background-image: url(:/images/1x/Property_1_red.png);");
        ui->info_widget->setStyleSheet("QWidget#info_widget{background-image: url(:/images/1x/mainInfo_red.png);}");
        ui->label_head_photo->setVisible(false);
        ui->label_name->setText("陌生人");
        ui->temperature_widget->setVisible(false);
        break;
    default:
        break;
    }
}

void ApertureLayer::set_tip(const QString &tip)
{
    ui->label_tip->setText(tip);
    ui->label_tip->setVisible(true);
}
