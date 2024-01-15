#include "custombackground.h"
#include "customcolormanager.h"
#include <QPainter>


customBackGround::customBackGround(QWidget *parent)
    : QWidget{parent}
{}

void customBackGround::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter paint(this);

    QGradient gradient = CustomColorManager::getInstance().getGradientColor("TextGradient");
}
