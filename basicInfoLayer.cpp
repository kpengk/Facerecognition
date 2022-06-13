#include "basicInfoLayer.hpp"
#include "ui_basicInfoLayer.h"

#include <QTimer>
#include <QDateTime>

BasicInfoLayer::BasicInfoLayer(QWidget *parent)
    : QWidget{ parent }
    , ui{ new Ui::BasicInfoLayer }
{
    ui->setupUi(this);

    auto timer{ new QTimer(this) };
    connect(timer, &QTimer::timeout, this, &BasicInfoLayer::on_timeout);
    timer->start(1000);
    on_timeout();
}

BasicInfoLayer::~BasicInfoLayer()
{
    delete ui;
}

void BasicInfoLayer::set_serial_number(const QString &sn)
{
    ui->serial_number_label->setText(sn);
}

void BasicInfoLayer::set_location(const QString &name)
{
    ui->location_name_label->setText(name);
}

void BasicInfoLayer::set_link_state(int state)
{
    switch (state) {
    case 1:
        ui->link_icon_label->setPixmap(QPixmap(":/images/1x/FixedPoint_1.png"));
        ui->link_text_label->setText("连接成功");
        break;
    case 2:
        ui->link_icon_label->setPixmap(QPixmap(":/images/1x/FixedPoint.png"));
        ui->link_text_label->setText("连接失败");
        break;
    default:
        break;
    }
}

void BasicInfoLayer::on_timeout()
{
    const auto date_time{ QDateTime::currentDateTime() };
    ui->time_label->setText(date_time.time().toString("HH:mm"));
    ui->date_label->setText(date_time.date().toString("yyyy-MM-dd dddd"));
}
