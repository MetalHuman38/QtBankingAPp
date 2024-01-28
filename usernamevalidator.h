#ifndef USERNAMEVALIDATOR_H
#define USERNAMEVALIDATOR_H

#pragma once

#include <QObject>
#include <QString>
#include "errorhandler.h"//
#include <QSqlDatabase>

class usernameValidator
{
public:
    usernameValidator(ErrorHandler* errorHandler);
    void setTableName(const QString& tableName);
    ErrorCode validate(const QString& username, const QSqlDatabase& db) const;
    bool isValid(const QString &username, const QSqlDatabase& db) const;


private:
    ErrorHandler* errorHandler;
    QString tableName;
    // Check if username already exists in the Database.
    bool isUsernameExists(const QString& username, const QSqlDatabase& db) const;
};

#endif // USERNAMEVALIDATOR_H




