#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <QObject>
#include <QMap>

enum class ErrorCode{
    NoError,
    InvalidFormat,
    TooShort,
    TooLong,
    InvalidFirstName,
    InvalidLastName,
    NameCannotContainCharacter,
    FirstNameContainsNonAlphabetic,
    LastNameContainsNonAlphabetic,
    ExcessiveWhitespace,
    InvalidUserName,
    UserNameLength,
    UserNameAlreadyExists,
    UserNameCannotContainOnlyIntegerOrSpecialChar,
    UserNameAcceptCharacters,
    PasswordTooshort,
    PasswordMustContainSpecialChar,
    EmailNotValid,
    PhoneNumberNotValid,
};


class ErrorHandler : public QObject
{
    Q_OBJECT
public:
    explicit ErrorHandler(QObject *parent = nullptr);

    QString getErrorMessage(ErrorCode errorCode);

private:
    static QMap<ErrorCode, QString> errorMessages;

};

#endif // ERRORHANDLER_H
