#ifndef PHONENUMBERVALIDATOR_H
#define PHONENUMBERVALIDATOR_H

#include <QObject>

class phoneNumberValidator : public QObject
{
    Q_OBJECT
public:
    explicit phoneNumberValidator(QObject *parent = nullptr);

signals:
};

#endif // PHONENUMBERVALIDATOR_H
