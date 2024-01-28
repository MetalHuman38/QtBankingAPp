#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "errorhandler.h"
#include "namevalidator.h"
#include "passwordvalidator.h"
#include "usernamevalidator.h"



class previewDialog : public QDialog
{
    Q_OBJECT
public:
    explicit previewDialog(QWidget *parent = nullptr);

    // Function to set and display user data
    void setUserData(const QString &firstNameText, const QString &lastNameText,
                     const QString &usernameText, const QString &passwordText,
                     const QString &emailText, const QString &dateOfBirthText,
                     const QString &phoneNumberText);

    void setLabelWithMargins(QLabel *label, const QString &text);


private slots:
    // Function called when the user clicks "Confirm"
    void confirmDetails();
    void confirmAndInsertDetails();


    // Function called when the user clicks "Edit"
    void editDetails();

private:
    // Add QLabel members to display user data
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *emailLabel;
    QLabel *dateOfBirthLabel;
    QLabel *phoneNumberLabel;
    ErrorHandler errorHandler;
    NameValidator nameValidator;
    usernameValidator usernamevalidator;
    PasswordValidator passwordvalidator;
    // Add more labels as needed
    QLabel *statusLabel;
    // Add a layout to arrange the labels
    QVBoxLayout *mainLayout;

    // Add buttons for confirmation and editing
    QPushButton *confirmButton;
    QPushButton *editButton;
    QSqlDatabase db_Connection;

signals:
    void userDetailsConfirmed(QString firstName, QString lastName, QString username, QString password,
                              QString email, QString dateOfBirth, QString phoneNumber);
};

#endif // PREVIEWDIALOG_H
