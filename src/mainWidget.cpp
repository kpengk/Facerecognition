#include "mainWidget.hpp"
#include "./ui_mainWidget.h"
#include "readerdll.h"
#include "WltRS.h"

#include <fstream>
#include <QKeyEvent>
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget{ parent }
    , ui{ new Ui::MainWidget }
    , video_label_{ new QLabel(this) }
    , base_info_layer_{ new BasicInfoLayer(this) }
    , aperture_layer_{ new ApertureLayer(this) }
    , detection_result_layer_{ new DetectionResultLayer(this) }
{
    ui->setupUi(this);

    //this->setWindowFlag(Qt::FramelessWindowHint);

    const QSize full_size{800, 1280};
    video_label_->setFixedSize(full_size);
    base_info_layer_->setFixedSize(full_size);
    aperture_layer_->setFixedSize(full_size);
    detection_result_layer_->setFixedSize(full_size);

    set_detect_mode(DetectMode::ID_card);

    video_label_->setPixmap(QPixmap("D:/Project/Facerecognition/Facerecognition2.0/src/images/video.png"));
    video_label_->setScaledContents(true);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::set_detect_mode(DetectMode mode)
{
    mode_ = mode;
}

void MainWidget::set_state(int state)
{
    qDebug() << "state:" << state;
    switch (state)
    {
    case 11:
        aperture_layer_->set_controls_visible(ApertureLayer::tip);
        aperture_layer_->set_tip("请靠近屏幕");
        detection_result_layer_->set_detect_state(DetectState::none);
        break;
    case 12:
        aperture_layer_->set_mask_color(ApertureColor::blue);
        aperture_layer_->set_controls_visible(ApertureLayer::ring | ApertureLayer::info_text);
        aperture_layer_->set_text("正在识别...");
        detection_result_layer_->set_detect_state(DetectState::none);
        break;
    case 13:
        aperture_layer_->set_mask_color(ApertureColor::green);
        aperture_layer_->set_controls_visible(ApertureLayer::ring | ApertureLayer::info);
        aperture_layer_->set_name("李*六");
        aperture_layer_->set_temperature(36.9);
        detection_result_layer_->set_detect_state(DetectState::none);
        break;
    case 14:
        aperture_layer_->set_mask_color(ApertureColor::yellow);
        aperture_layer_->set_controls_visible(ApertureLayer::ring | ApertureLayer::info);
        aperture_layer_->set_name("李*六");
        aperture_layer_->set_temperature(39.8);
        detection_result_layer_->set_detect_state(DetectState::none);
        break;
    case 15:
        aperture_layer_->set_mask_color(ApertureColor::red);
        aperture_layer_->set_controls_visible(ApertureLayer::ring | ApertureLayer::info_text | ApertureLayer::tip);
        aperture_layer_->set_text("陌生人");
        aperture_layer_->set_tip("请联系管理员");
        detection_result_layer_->set_detect_state(DetectState::none);
        break;
    case 21:
        aperture_layer_->set_controls_visible(ApertureLayer::tip);
        aperture_layer_->set_tip("扫码完成，请靠近屏幕测温");
        detection_result_layer_->set_detect_state(DetectState::none);
        break;
    case 22:
        aperture_layer_->set_mask_color(ApertureColor::green);
        aperture_layer_->set_controls_visible(ApertureLayer::info_pic | ApertureLayer::info_temp);
        aperture_layer_->set_name({});
        aperture_layer_->set_temperature(36.9);
        detection_result_layer_->set_detect_state(DetectState::finish);
        detection_result_layer_->set_health_code(HealthCode::green);
        detection_result_layer_->set_nucleic_acid(NucleicAcid::feminine, QDateTime(QDate(2022,06,14), QTime(14,33)));
        detection_result_layer_->set_vaccination(3);
        break;
    case 23:
        aperture_layer_->set_mask_color(ApertureColor::green);
        aperture_layer_->set_controls_visible(ApertureLayer::info_pic | ApertureLayer::info_temp);
        aperture_layer_->set_name({});
        aperture_layer_->set_temperature(36.9);
        detection_result_layer_->set_detect_state(DetectState::finish);
        detection_result_layer_->set_health_code(HealthCode::red);
        detection_result_layer_->set_nucleic_acid(NucleicAcid::positive, QDateTime(QDate(2022,06,14), QTime(14,33)));
        detection_result_layer_->set_vaccination(0);
        break;
    case 24:
        aperture_layer_->set_mask_color(ApertureColor::green);
        aperture_layer_->set_controls_visible(ApertureLayer::info_pic | ApertureLayer::info_temp);
        aperture_layer_->set_name({});
        aperture_layer_->set_temperature(36.9);
        detection_result_layer_->set_detect_state(DetectState::not_reply);
        break;
    case 25:
        aperture_layer_->set_mask_color(ApertureColor::green);
        aperture_layer_->set_controls_visible(ApertureLayer::info_pic | ApertureLayer::info_temp);
        aperture_layer_->set_name({});
        aperture_layer_->set_temperature(36.9);
        detection_result_layer_->set_detect_state(DetectState::not_link);
        break;
    case 26:
        aperture_layer_->set_mask_color(ApertureColor::green);
        aperture_layer_->set_controls_visible(ApertureLayer::info_pic | ApertureLayer::info_temp);
        aperture_layer_->set_name({});
        aperture_layer_->set_temperature(36.9);
        detection_result_layer_->set_detect_state(DetectState::unregister);
        break;
    case 31:
        aperture_layer_->set_mask_color(ApertureColor::blue);
        aperture_layer_->set_controls_visible(ApertureLayer::ring | ApertureLayer::info_text | ApertureLayer::tip);
        aperture_layer_->set_text("正在人证比对...");
        aperture_layer_->set_tip("扫码完成，请靠近屏幕测温");
        detection_result_layer_->set_detect_state(DetectState::none);
        break;
    case 32:
        aperture_layer_->set_mask_color(ApertureColor::green);
        aperture_layer_->set_controls_visible(ApertureLayer::info);
        aperture_layer_->set_name("李*六");
        aperture_layer_->set_temperature(36.9);
        detection_result_layer_->set_detect_state(DetectState::finish);
        detection_result_layer_->set_health_code(HealthCode::green);
        detection_result_layer_->set_nucleic_acid(NucleicAcid::feminine, QDateTime(QDate(2022,06,14), QTime(14,33)));
        detection_result_layer_->set_vaccination(3);
        break;
    case 33:
        aperture_layer_->set_mask_color(ApertureColor::yellow);
        aperture_layer_->set_controls_visible(ApertureLayer::info);
        aperture_layer_->set_name("李*六");
        aperture_layer_->set_temperature(39.9);
        detection_result_layer_->set_detect_state(DetectState::finish);
        detection_result_layer_->set_health_code(HealthCode::green);
        detection_result_layer_->set_nucleic_acid(NucleicAcid::feminine, QDateTime(QDate(2022,06,14), QTime(14,33)));
        detection_result_layer_->set_vaccination(3);
        break;
    case 34:
        aperture_layer_->set_controls_visible(ApertureLayer::none);
        detection_result_layer_->set_detect_state(DetectState::compare_fail);
        break;
    case 41:
        aperture_layer_->set_controls_visible(ApertureLayer::none);
        detection_result_layer_->set_detect_state(DetectState::requesting);
        break;
    case 42:
        aperture_layer_->set_mask_color(ApertureColor::green);
        aperture_layer_->set_controls_visible(ApertureLayer::info);
        aperture_layer_->set_name("李*六");
        aperture_layer_->set_temperature(36.9);
        detection_result_layer_->set_detect_state(DetectState::finish);
        detection_result_layer_->set_health_code(HealthCode::green);
        detection_result_layer_->set_nucleic_acid(NucleicAcid::feminine, QDateTime(QDate(2022,06,14), QTime(14,33)));
        detection_result_layer_->set_vaccination(3);
        break;
    case 43:
        aperture_layer_->set_controls_visible(ApertureLayer::none);
        detection_result_layer_->set_detect_state(DetectState::idcard_not_exist);
        break;
    default:
        break;
    }
}

void MainWidget::keyPressEvent(QKeyEvent *event)
{
    static const std::vector<int> state{11,12,13,14,15,21,22,23,24,25,26,31,32,33,34,41,42,43};
    static int n{};

    switch (event->key()) {
    case Qt::Key_Left:
        --n;
        break;
    case Qt::Key_Right:
        ++n;
        break;
    default:
        break;
    }

    if (n >= static_cast<int>(state.size()))
    {
        n = 0;
    }
    else if (n < 0)
    {
        n = state.size() - 1;
    }
    set_state(state[n]);
}

bool MainWidget::read_id_card(std::string& name, std::string& id)
{
#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    std::string port = R"(\\.\COM3)";
#else
    std::string port = "/dev/ttyC1";
#endif

    if (!OpenReader(port.c_str(), 115200))
        return false;
    if (!FindCard(port.c_str()))
        return false;
    if (!SelectCard(port.c_str()))
        return false;

    unsigned char WZbuffer[256]{};
    unsigned char ZPbuffer[1024]{};
    unsigned char FPbuffer[1024]{};
    if (!ReadBaseFPMsg(port.c_str(), WZbuffer, 256, ZPbuffer, 1024, FPbuffer, 1024))
        return false;
    CloseReader(port.c_str());

    //decode WZbuffer
    IDCardInfo id_info;
    DecodeWZu8(&id_info, WZbuffer, 256);
    name = id_info.name;
    id = id_info.id;
    //save ZPbuffer and decode
    std::ofstream zp_ofs("ZP.wlt", std::ios::binary);
    zp_ofs.write(reinterpret_cast<const char*>(ZPbuffer), 1024);
    zp_ofs.close();
    const int result = WltRS("ZP.wlt", "ZP.bmp");
    printf("Bitmap:%d\n", result);
    return result == 1;
}
