#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include <QObject>
#include <QString>
#include <QCryptographicHash>
#include "errorhandler.h"

class PasswordValidator : public QObject
{
    Q_OBJECT
public:
    explicit PasswordValidator(QObject *parent = nullptr, ErrorHandler* errorHandler = nullptr);
    ErrorCode validate(const QString& password) const;
    // Validate password
    bool isValidPassword(const QString &password);
    // Add any additional validation functions as needed
    bool isStrongEnough(const QString &password);
    // Validate password and hash it
    QByteArray hashAndValidatePassword(const QString &password, ErrorCode &error);

signals:
    // Signal for password validation result
    void passwordValidationResult(bool isValid);

private:
    ErrorHandler* errorHandler;
};

#endif // PASSWORDVALIDATOR_H
