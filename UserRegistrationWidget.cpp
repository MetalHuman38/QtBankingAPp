// UserRegistrationWidget.cpp

#include "UserRegistrationWidget.h"
#include "ui_user_registrationwidget.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QWidget>
#include <QDialog>
#include <QDateEdit>




UserRegistrationWidget::UserRegistrationWidget(QWidget *parent) : QDialog(parent), ui(new Ui::user_RegistrationWidget) {
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
    QString dateOfBirth = dateOfBirthLineEdit->text();
    QString phoneNumber = phoneNumberLineEdit->text();





    // Emit the signal with user input
    emit userRegistrationRequested(firstName, lastName, username, password, email, dateOfBirth, phoneNumber);
}


UserRegistrationWidget::~UserRegistrationWidget() {
    // Destructor implementation, if needed
}
