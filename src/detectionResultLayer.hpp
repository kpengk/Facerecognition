#pragma once

#include <QWidget>

namespace Ui {
class DetectionResultLayer;
}

enum class DetectState
{
    finish,
    not_reply,
    not_link,
    unregister,
    compare_fail,
    requesting,
    idcard_not_exist,
    none
};

enum NucleicAcid
{
    feminine,           /*阴性*/
    positive,           /*阳性*/
    suspected_positive, /*疑似阳性*/
    not_detected,       /*未检出*/
    to_be_detected,     /*待检测*/
    none
};

class DetectionResultLayer : public QWidget
{
    Q_OBJECT

public:
    explicit DetectionResultLayer(QWidget *parent = nullptr);
    ~DetectionResultLayer();
    void set_detect_state(DetectState state);

    void set_result_normal(bool normal);
    void set_nucleic_acid(NucleicAcid state, const QString& datetime={});
    // -1:**  0:未接种  1/2/3:针数
    void set_vaccination(int num);

private:
    Ui::DetectionResultLayer *ui;
};
