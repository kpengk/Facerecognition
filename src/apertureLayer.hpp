#ifndef APERTURELAYER_HPP
#define APERTURELAYER_HPP

#include <QWidget>

namespace Ui {
class ApertureLayer;
}

enum class MaskColor
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
    explicit ApertureLayer(QWidget *parent = nullptr);
    ~ApertureLayer();
    void set_aperture_visible(bool visible);// ring & info
    void set_ring_visible(bool visible);
    void set_tip_visble(bool visible);
    void set_mask_color(MaskColor color);// show aperture + hide tip

    void set_name(const QString& text);
    void set_temperature(float value);
    void set_tip_text(const QString& tip);

private:
    Ui::ApertureLayer *ui;
    MaskColor color_mode_;
    QString name_;
    float temperature_;
};

#endif // APERTURELAYER_HPP
