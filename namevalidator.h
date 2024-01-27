#ifndef NAMEVALIDATOR_H
#define NAMEVALIDATOR_H


#include <QObject>
#include <QString>
#include "errorhandler.h"//

class NameValidator
{
public:
    NameValidator(ErrorHandler* errorHandler);
    ErrorCode validate(const QString& firstName, const QString& lastName) const;
    bool isValid(const QString &firstName, const QString &lastName) const;

private:
    ErrorHandler* errorHandler;

};


#endif // NAMEVALIDATOR_H
