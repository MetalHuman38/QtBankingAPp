#include "errorhandler.h"
#include "usernamevalidator.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>


usernameValidator::usernameValidator(ErrorHandler* errorHandler)
      : errorHandler(errorHandler)

{
}


ErrorCode usernameValidator::validate(const QString& username) const {



    // Check if username already exists in the database.
    if (isUsernameExists(username)) {
        return ErrorCode::UserNameAlreadyExists;
    }

    if(username.trimmed().isEmpty()){
        return ErrorCode::InvalidUserName;
    }

    if(username.length() < 2 || username.length() > 10){
        return ErrorCode::UserNameLength;
    }


    // Check if username contains only integer or special characters.
    if (username.toInt() != 0 || username.contains(QRegExp("[!@#$%^&*(),.?\":{}|<>]"))) {
        return ErrorCode::UserNameCannotContainOnlyIntegerOrSpecialChar;
    }


    //Check if username contains only letter and underScore.
    if (!username.contains(QRegExp("^[a-zA-Z0-9_]+$"))) {
        return ErrorCode::UserNameAcceptCharacters;
    }

    if (username.contains(QRegExp("\\s\\s+"))) {
        return ErrorCode::ExcessiveWhitespace;
    }


    return ErrorCode::NoError;
}

bool usernameValidator::isValid(const QString &username) const {
    return validate(username) == ErrorCode::NoError;
}


bool usernameValidator::isUsernameExists(const QString& username) const {
    // Implement your database query logic to check if the username exists
    // Return true if the username exists, false otherwise

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");


    // Check if the database is open
    if (!db.isOpen()) {
        qDebug() << "Database not open";
        return false;
    }

    // Placeholder code, replace it with actual database query logic
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM UserRegistration WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}

