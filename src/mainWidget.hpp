#pragma once

#include "basicInfoLayer.hpp"
#include "apertureLayer.hpp"
#include "detectionResultLayer.hpp"

#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

enum DetectMode
{
    base,       /* 基础测温 */
    scan_code,  /* 扫码测温 */
    ID_card,    /* 识别身份证测温 */
    face        /* 人脸识别请求 */
};

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void set_detect_mode(DetectMode mode);
    void set_state(int state);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    bool read_id_card(std::string& name, std::string& id);

private slots:

private:
    Ui::MainWidget *ui;
    QLabel* video_label_;
    BasicInfoLayer* base_info_layer_;
    ApertureLayer* aperture_layer_;
    DetectionResultLayer* detection_result_layer_;
    DetectMode mode_;
};
