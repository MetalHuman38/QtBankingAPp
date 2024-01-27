#ifndef EMAILVALIDATOR_H
#define EMAILVALIDATOR_H

#include <QObject>

class emailValidator : public QObject
{
    Q_OBJECT
public:
    explicit emailValidator(QObject *parent = nullptr);

signals:
};

#endif // EMAILVALIDATOR_H
