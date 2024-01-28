#include "passwordvalidator.h"
#include "errorhandler.h"

PasswordValidator::PasswordValidator(QObject *parent, ErrorHandler* errorHandler)
    : QObject{parent}, errorHandler(errorHandler)
{}


QByteArray PasswordValidator::hashAndValidatePassword(const QString &password, ErrorCode &error)
{

    error = validate(password);

    if (error != ErrorCode::NoError) {
        // Emit the signal with the validation result
        emit passwordValidationResult(false);
        return QByteArray();
    }

    // Hash the password using SHA-256 (you can choose a different algorithm)
    QByteArray hashedPassword = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);

    // Emit the signal with the validation result
    emit passwordValidationResult(true);

    return hashedPassword;
}


ErrorCode PasswordValidator::validate(const QString &password) const {
    // Implement your password strength criteria here
    // For example, minimum length, presence of uppercase, lowercase, digits, and special characters
    // Return true if the password meets the criteria, false otherwise
    // ...

    if(password.trimmed().isEmpty()){
        return ErrorCode::InvalidPassword;
    }

    if(password.length() < 2 || password.length() > 15){
        return ErrorCode::PasswordTooshort;
    }

    if (password.contains(QRegExp("\\s\\s+"))) {
        return ErrorCode::ExcessiveWhitespace;
    }

    // Check if password contains integer, special characters and Uppercase
    if (password.toInt() != 0 || !password.contains(QRegExp("[!@#$%^&*(),.?\":{}|<>]"))) {
        return ErrorCode::PasswordMustContainSpecialChar;
    }

    // Check if password contains at least one uppercase letter, one digit, and one special character
    bool hasUppercase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    for (const QChar &ch : password) {
        if (ch.isDigit()) {
            hasDigit = true;
        } else if (ch.isUpper()) {
            hasUppercase = true;
        } else if (ch.isPunct() || ch.isSymbol()) {
            hasSpecialChar = true;
        }
    }

    if (!hasUppercase || !hasDigit || !hasSpecialChar) {
        return ErrorCode::PasswordMustContainUppercaseDigitSpecialChar;
    }


    return ErrorCode::NoError;
}


bool PasswordValidator::isValidPassword(const QString &password)
{
    bool isValid = isStrongEnough(password);

    // Emit the signal with the validation result
    emit passwordValidationResult(isValid);

    return isValid;
}

bool PasswordValidator::isStrongEnough(const QString &password){

    return true;
}



