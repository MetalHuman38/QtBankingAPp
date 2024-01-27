// UserRegistrationWidget.cpp

#include "UserRegistrationWidget.h"
#include "ui_user_registrationwidget.h"
#include "namevalidator.h"
#include "errorhandler.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QWidget>
#include <QDialog>
#include <QDateEdit>
#include <QDebug>
#include <QMessageBox>




UserRegistrationWidget::UserRegistrationWidget(QWidget *parent) : QDialog(parent), ui(new Ui::user_RegistrationWidget),
    nameValidator(&errorHandler)
{
    ui->setupUi(this);
    //setupConnections();

}

void UserRegistrationWidget::registerUser() {
    // Get user input from the GUI elements
    QString firstName = firstNameLineEdit->text();
    QString lastName = lastNameLineEdit->text();
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    QString email = emailLineEdit->text();
    QString dateString = dateOfBirthLineEdit->text();
    QString phoneNumber = phoneNumberLineEdit->text();

    // Trim leading and trailing whitespaces from dateString
    dateString = dateString.trimmed();

    QDate dateOfBirth = QDate::fromString(dateString, "MM/dd/yyyy");

    if (!dateOfBirth.isValid()) {
        // Handle the case where the date is not valid
        qDebug() << "Invalid date format:" << dateString;
        QMessageBox::critical(this, "Error", "Ivalid date format. Check the date of birth");
    }


    // Emit the signal with user input
    emit userRegistrationRequested(firstName, lastName, username, password, email, dateString, phoneNumber);
}


UserRegistrationWidget::~UserRegistrationWidget() {
    // Destructor implementation, if needed
}
