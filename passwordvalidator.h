#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QObject>

class passwordValidator : public QObject
{
    Q_OBJECT
public:
    explicit passwordValidator(QObject *parent = nullptr);

signals:
};

#endif // PASSWORDVALIDATOR_H
