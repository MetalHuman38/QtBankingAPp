#include "errorhandler.h"

ErrorHandler::ErrorHandler(QObject *parent)
    : QObject{parent}
{


}

QMap<ErrorCode, QString> ErrorHandler::errorMessages = {

    {ErrorCode::NoError, "No Error"},
    {ErrorCode::InvalidFormat, "Invalid Format"},
    {ErrorCode::TooShort, "first name or last is too short or too long! "},
    {ErrorCode::TooLong, "first name or last is too short or too long!"},
    {ErrorCode::InvalidFirstName, "first name or last name field cannot be empty! Please enter your name"},
    {ErrorCode::InvalidLastName,"last name field can not be empty! Please enter your name"},
    {ErrorCode::NameCannotContainCharacter, "first name or last name cannot contain special character or number"},
    {ErrorCode::FirstNameContainsNonAlphabetic, "first name contains non-alphabetic! Use only letters."},
    {ErrorCode::LastNameContainsNonAlphabetic, "last name contains non-alphabetic! Use only letters."},
    {ErrorCode::ExcessiveWhitespace, "first name or last name contains excessive whitespace!"},
    {ErrorCode::UserNameLength, "Username too short or too long!"},
    {ErrorCode::InvalidUserName, "Username field cannot be empty!"},
    {ErrorCode::UserNameCannotContainOnlyIntegerOrSpecialChar, "Username must be combination of numbers and character(_)!"},
    {ErrorCode::UserNameAlreadyExists, "Username is taken!"},
    {ErrorCode::UserNameAcceptCharacters, "The only special character accepted is UnderScore!"},
    {ErrorCode::PasswordMustContainSpecialChar, "Password must contain special character and numbers!"},
    {ErrorCode::UserNameAlreadyExists, "Usename already Exist! Choose another one."},
    {ErrorCode::EmailNotValid, "Not a valid email!"},
    {ErrorCode::PhoneNumberNotValid, "Phone Number is Ivalid!"}
};


QString ErrorHandler::getErrorMessage(ErrorCode errorCode) {
    return errorMessages.value(errorCode, "Unknown error!");
}
