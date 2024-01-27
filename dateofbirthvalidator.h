#ifndef DATEOFBIRTHVALIDATOR_H
#define DATEOFBIRTHVALIDATOR_H

#include <QObject>

class dateofBirthValidator : public QObject
{
    Q_OBJECT
public:
    explicit dateofBirthValidator(QObject *parent = nullptr);

signals:
};

#endif // DATEOFBIRTHVALIDATOR_H
