#pragma once

#include <QWidget>

namespace Ui {
class BasicInfoLayer;
}

class BasicInfoLayer : public QWidget
{
    Q_OBJECT

public:
    explicit BasicInfoLayer(QWidget *parent = nullptr);
    ~BasicInfoLayer();
    void set_serial_number(const QString& sn);
    void set_location(const QString& name);
    void set_link_state(bool connected);

private slots:
    void on_timeout();

private:
    Ui::BasicInfoLayer *ui;
};
