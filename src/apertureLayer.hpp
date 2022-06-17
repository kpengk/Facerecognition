#ifndef APERTURELAYER_HPP
#define APERTURELAYER_HPP

#include <QWidget>
#include <QFlags>

namespace Ui {
class ApertureLayer;
}

enum class ApertureColor
{
    blue,
    green,
    yellow,
    red
};

class ApertureLayer : public QWidget
{
    Q_OBJECT
public:
    enum Control
    {
        none = 0x00,
        ring = 0x01,
        info_text = 0x04,
        info_pic = 0x02,
        info_name = info_text,
        info_temp = 0x08,
        info = info_pic | info_name | info_temp,
        tip = 0x10,
    };
    Q_DECLARE_FLAGS(Controls, Control)

    explicit ApertureLayer(QWidget *parent = nullptr);
    ~ApertureLayer();
    void set_controls_visible(ApertureLayer::Controls flag);
    void set_mask_color(ApertureColor color);

    void set_name(const QString& text);
    void set_text(const QString& text);
    void set_temperature(float value);
    void set_tip(const QString& tip);

private:
    Ui::ApertureLayer *ui;
    ApertureColor color_;
};
Q_DECLARE_OPERATORS_FOR_FLAGS(ApertureLayer::Controls)

#endif // APERTURELAYER_HPP
