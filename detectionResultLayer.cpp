#include "detectionResultLayer.hpp"
#include "ui_detectionResultLayer.h"

DetectionResultLayer::DetectionResultLayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectionResultLayer)
{
    ui->setupUi(this);
    set_detect_state(DetectState::none);
}

DetectionResultLayer::~DetectionResultLayer()
{
    delete ui;
}

void DetectionResultLayer::set_detect_state(DetectState state)
{
    if (state == DetectState::none)
    {
        this->setVisible(false);
    }
    else
    {
        this->setVisible(true);
        ui->stackedWidget->setCurrentIndex(static_cast<int>(state));
    }
}

void DetectionResultLayer::set_result_normal(bool normal)
{
    if (normal)
    {
        ui->big_data_card_widget->setStyleSheet(
                    "QWidget#big_data_card_widget { border-radius: 14px; background-image: url(:/images/1x/BigDataCard_green.png); }"
                    "QLabel { font-family: Noto Sans SC; }");
        ui->label_qrcode->setPixmap(QPixmap(":/images/1x/pic_qrcode_green.png"));
        ui->label_result_icon->setPixmap(QPixmap(":/images/1x/icon_done.png"));
        ui->label_result_text->setText("正常");
        ui->label_travel_card_icon->setPixmap(QPixmap(":/images/1x/picTongxing_green.png"));
    }
    else
    {
        ui->big_data_card_widget->setStyleSheet(
                    "QWidget#big_data_card_widget { border-radius: 14px; background-image: url(:/images/1x/BigDataCard_red.png); }"
                    "QLabel { font-family: Noto Sans SC; }");
        ui->label_qrcode->setPixmap(QPixmap(":/images/1x/pic_qrcode_red.png"));
        ui->label_result_icon->setPixmap(QPixmap(":/images/1x/icon_alert.png"));
        ui->label_result_text->setText("异常");
        ui->label_travel_card_icon->setPixmap(QPixmap(":/images/1x/picTongxing_red.png"));
    }
}

void DetectionResultLayer::set_nucleic_acid(NucleicAcid state, const QString &datetime)
{
    QString name;
    QString color;

    switch (state)
    {
    case NucleicAcid::feminine:
        name = "阴性";
        color = "rgba(52, 168, 107, 1)";
        break;
    case NucleicAcid::positive:
        name = "阳性";
        color = "rgba(255, 66, 45, 1)";
        break;
    case NucleicAcid::suspected_positive:
        name = "疑似阳性";
        color = "rgba(255, 66, 45, 1);";
        break;
    case NucleicAcid::not_detected:
        name = "未检出";
        color = "rgba(128, 137, 147, 1)";
        break;
    case NucleicAcid::to_be_detected:
        name = "待检测";
        color = "rgba(128, 137, 147, 1)";
        break;
    case NucleicAcid::none:
        name = "**";
        color = "rgba(128, 137, 147, 1)";
        break;
    default:
        break;
    }

    ui->label_nucleic_result->setText(name);
    ui->label_nucleic_48h->setVisible(state == NucleicAcid::feminine);
    ui->label_nucleic_result->setStyleSheet(QString("color: %1; font-weight: bold; font-size: 40px;").arg(color));
    if (state == NucleicAcid::feminine || state == NucleicAcid::positive || state == NucleicAcid::suspected_positive)
    {
        ui->label_nucleic_datetime->setText(datetime);
    }
    else
    {
        ui->label_nucleic_datetime->clear();
    }
}

void DetectionResultLayer::set_vaccination(int num)
{
    if (num < 0)
    {
        ui->label_vaccination_result->setText("**");
        ui->label_vaccination_state->clear();
    }
    else if (num == 0)
    {
        ui->label_vaccination_result->setText("未接种");
        ui->label_vaccination_state->clear();
    }
    else
    {
        ui->label_vaccination_result->setText(QString("%1针").arg(num));
        ui->label_vaccination_state->setText("已接种");
    }
}
