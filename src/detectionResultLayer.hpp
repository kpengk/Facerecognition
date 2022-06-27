#pragma once

#include <QWidget>
#include <QDateTime>

namespace Ui {
class DetectionResultLayer;
}

enum class DetectState
{
    none = -1,      /* 该图层为空 */
    finish = 0,     /* 检测完成，显示健康码、核酸、疫苗 */
    not_reply,      /* 服务端为响应 */
    not_link,       /* 网络未连接 */
    unregister,     /* 未注册一码通 */
    compare_fail,   /* 人证比对失败 */
    requesting,     /* 请求数据中 */
    idcard_not_exist/* 身份证号码不存在 */
};

enum class HealthCode
{
    green,  /* 绿码 */
    red,    /* 红码 */
};

enum class NucleicAcid
{
    none,               /* **    */
    feminine,           /* 阴性   */
    positive,           /* 阳性   */
    suspected_positive, /* 疑似阳性 */
    not_detected,       /* 未检出  */
    to_be_detected      /* 待检测  */
};

class DetectionResultLayer : public QWidget
{
    Q_OBJECT

public:
    explicit DetectionResultLayer(QWidget *parent = nullptr);
    ~DetectionResultLayer();
    void set_detect_state(DetectState state);

    void set_health_code(HealthCode state);
    void set_nucleic_acid(NucleicAcid state, const QDateTime& datetime={});
    // -1:**  0:未接种  1/2/3:针数
    void set_vaccination(int num);

private:
    Ui::DetectionResultLayer *ui;
};
