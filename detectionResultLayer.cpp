#include "detectionResultLayer.hpp"
#include "ui_detectionResultLayer.h"

DetectionResultLayer::DetectionResultLayer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetectionResultLayer)
{
    ui->setupUi(this);
}

DetectionResultLayer::~DetectionResultLayer()
{
    delete ui;
}
