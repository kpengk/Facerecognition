#pragma once

#include "basicInfoLayer.hpp"
#include "apertureLayer.hpp"
#include "detectionResultLayer.hpp"

#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    Ui::MainWidget *ui;
    QLabel* video_label_;
    BasicInfoLayer* base_info_layer_;
    ApertureLayer* aperture_layer_;
    DetectionResultLayer* detection_result_layer_;
};
