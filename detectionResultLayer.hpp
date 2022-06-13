#pragma once

#include <QWidget>

namespace Ui {
class DetectionResultLayer;
}

class DetectionResultLayer : public QWidget
{
    Q_OBJECT

public:
    explicit DetectionResultLayer(QWidget *parent = nullptr);
    ~DetectionResultLayer();

private:
    Ui::DetectionResultLayer *ui;
};
