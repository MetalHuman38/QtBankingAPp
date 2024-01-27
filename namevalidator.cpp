#include "errorhandler.h"

#include "namevalidator.h"
#include <QString>

NameValidator::NameValidator(ErrorHandler* errorHandler)
    : errorHandler(errorHandler)
{

}


ErrorCode NameValidator::validate(const QString& firstName, const QString& lastName) const {

    if(firstName.trimmed().isEmpty()){
        return ErrorCode::InvalidFirstName;
    }

    if(lastName.trimmed().isEmpty()){
        return ErrorCode::InvalidLastName;
    }

    if(firstName.length() < 2 || firstName.length() > 10){
        return ErrorCode::TooShort;
    }

    if(lastName.length() < 2 || lastName.length() > 10){
        return ErrorCode::TooLong;
    }

    // Check for numbers or special characters in first name
    if (firstName.contains(QRegExp("[0-9!@#$%^&*(),.?\":{}|<>]"))) {
        return ErrorCode::NameCannotContainCharacter;
    }

    // Check for numbers or special characters in last name
    if (lastName.contains(QRegExp("[0-9!@#$%^&*(),.?\":{}|<>]"))) {
        return ErrorCode::NameCannotContainCharacter;
    }

    if (!firstName.contains(QRegExp("^[a-zA-Z]+$"))) {
        return ErrorCode::FirstNameContainsNonAlphabetic;
    }

    if (!lastName.contains(QRegExp("^[a-zA-Z]+$"))) {
        return ErrorCode::LastNameContainsNonAlphabetic;
    }

    if (firstName.contains(QRegExp("\\s\\s+")) || lastName.contains(QRegExp("\\s\\s+"))) {
        return ErrorCode::ExcessiveWhitespace;
    }


    return ErrorCode::NoError;
}

bool NameValidator::isValid(const QString &firstName, const QString &lastName) const {
    return validate(firstName, lastName) == ErrorCode::NoError;
}
