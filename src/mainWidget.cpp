#include "mainWidget.hpp"
#include "./ui_mainWidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{ parent }
    , ui{ new Ui::MainWidget }
    , video_label_{ new QLabel(this) }
    , base_info_layer_{ new BasicInfoLayer(this) }
    , aperture_layer_{ new ApertureLayer(this) }
    , detection_result_layer_{ new DetectionResultLayer(this) }
{
    ui->setupUi(this);

    const QSize full_size{800, 1280};
    video_label_->setFixedSize(full_size);
    base_info_layer_->setFixedSize(full_size);
    aperture_layer_->setFixedSize(full_size);
    detection_result_layer_->setFixedSize(full_size);

    video_label_->setPixmap(QPixmap("D:/Project/Facerecognition/Facerecognition2.0/src/images/video.png"));
    video_label_->setScaledContents(true);
}

MainWidget::~MainWidget()
{
    delete ui;
}

