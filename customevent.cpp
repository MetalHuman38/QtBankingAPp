#include "customevent.h"
#include <QtWidgets>
#include <QLabel>
#include <QFont>


CustomEvent::CustomEvent(QWidget *parent) : QLabel(parent) {}

void CustomEvent::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QLinearGradient Liner(QPointF(this->rect().x(), this->rect().y()),QPointF(this->rect().width(), this->rect().height()));
    Liner.setColorAt(0, Qt::blue);
    Liner.setColorAt(1, Qt::darkBlue);
    QRect RectLiner(this->rect());
    painter.fillRect(RectLiner, Liner);

}
