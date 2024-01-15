#ifndef CUSTOMBACKGROUND_H
#define CUSTOMBACKGROUND_H

#include <QWidget>
#include <QPaintEvent>
#include <QtWidgets>
#include <QLabel>
#include <QFont>


class customBackGround : public QWidget
{
    Q_OBJECT
public:
    explicit customBackGround(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
};

#endif // CUSTOMBACKGROUND_H
