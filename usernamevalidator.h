#ifndef USERNAMEVALIDATOR_H
#define USERNAMEVALIDATOR_H

#include <QObject>
#include <QString>
#include "errorhandler.h"//

class usernameValidator
{
public:
    usernameValidator(ErrorHandler* errorHandler);
    ErrorCode validate(const QString& username) const;
    bool isValid(const QString &username) const;
    bool isUsernameExists(const QString& username) const;

private:
    ErrorHandler* errorHandler;
};

#endif // USERNAMEVALIDATOR_H




