#include "mainWidget.hpp"
#include "./ui_mainWidget.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget{ parent }
    , ui{ new Ui::MainWidget }
    , video_label_{ new QLabel(this) }
    , mask_label_{ new QLabel(this) }
    , base_info_layer_{ new BasicInfoLayer(this) }
    , aperture_layer_{ new ApertureLayer(this) }
    , detection_result_layer_{ new DetectionResultLayer(this) }
{
    ui->setupUi(this);

    const QSize full_size{800, 1280};
    video_label_->setFixedSize(full_size);
    mask_label_->setFixedSize(full_size);
    base_info_layer_->setFixedSize(full_size);
    detection_result_layer_->setFixedSize(full_size);

    video_label_->setPixmap(QPixmap("D:/Project/Facerecognition/Facerecognition2.0/images/video.png"));
    video_label_->setScaledContents(true);

    //QString pic = "PHN2ZyB3aWR0aD0iODAwIiBoZWlnaHQ9IjEyODAiIHZpZXdCb3g9IjAgMCA4MDAgMTI4MCIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHJlY3Qgb3BhY2l0eT0iMC44IiB3aWR0aD0iODAwIiBoZWlnaHQ9IjI1MCIgZmlsbD0idXJsKCNwYWludDBfbGluZWFyXzE0N185NDMzKSIvPgo8cmVjdCBvcGFjaXR5PSIwLjgiIHdpZHRoPSI4MDAiIGhlaWdodD0iMjUwIiB0cmFuc2Zvcm09Im1hdHJpeCgxIDAgMCAtMSAwIDEyODApIiBmaWxsPSJ1cmwoI3BhaW50MV9saW5lYXJfMTQ3Xzk0MzMpIi8+CjxkZWZzPgo8bGluZWFyR3JhZGllbnQgaWQ9InBhaW50MF9saW5lYXJfMTQ3Xzk0MzMiIHgxPSIwIiB5MT0iMCIgeDI9IjAiIHkyPSIyNTAiIGdyYWRpZW50VW5pdHM9InVzZXJTcGFjZU9uVXNlIj4KPHN0b3Agc3RvcC1jb2xvcj0iI0ZGODIxMyIgc3RvcC1vcGFjaXR5PSIwLjkiLz4KPHN0b3Agb2Zmc2V0PSIxIiBzdG9wLWNvbG9yPSIjMkMyQzJDIiBzdG9wLW9wYWNpdHk9IjAuMDEiLz4KPC9saW5lYXJHcmFkaWVudD4KPGxpbmVhckdyYWRpZW50IGlkPSJwYWludDFfbGluZWFyXzE0N185NDMzIiB4MT0iMCIgeTE9IjAiIHgyPSIwIiB5Mj0iMjUwIiBncmFkaWVudFVuaXRzPSJ1c2VyU3BhY2VPblVzZSI+CjxzdG9wIHN0b3AtY29sb3I9IiNGRjgyMTMiIHN0b3Atb3BhY2l0eT0iMC45Ii8+CjxzdG9wIG9mZnNldD0iMSIgc3RvcC1jb2xvcj0iIzJDMkMyQyIgc3RvcC1vcGFjaXR5PSIwLjAxIi8+CjwvbGluZWFyR3JhZGllbnQ+CjwvZGVmcz4KPC9zdmc+Cg==";
    //QPixmap image;
    //image.loadFromData(QByteArray::fromBase64(pic.toLocal8Bit()));
    mask_label_->setPixmap(QPixmap(":/images/1x/yellow_mask.png"));
    mask_label_->setScaledContents(true);
}

MainWidget::~MainWidget()
{
    delete ui;
}

