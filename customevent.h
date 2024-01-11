#ifndef CUSTOMEVENT_H
#define CUSTOMEVENT_H


#include <QtWidgets/QWidget>
#include <QtGui>
#include <QtCore>
#include <QLabel>


class CustomEvent : public QLabel
{
    Q_OBJECT
public:
    CustomEvent(QWidget *parent = nullptr);
public:
    void paintEvent(QPaintEvent *) override;

    using QLabel::QLabel;
};

#endif // CUSTOMEVENT_H
