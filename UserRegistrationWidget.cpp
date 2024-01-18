// UserRegistrationWidget.cpp

#include "UserRegistrationWidget.h"
#include "ui_user_registrationwidget.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QWidget>
#include <QDialog>




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
    QString address = addressLineEdit->text();


    // Connect to the database (ensure QSqlDatabase is properly set up)
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("BankingSystem");
    db.setUserName("root");
    db.setPassword("London1983@@@!");

    if (!db.open()) {
        // Handle database connection error
        return;
    }

    // Execute SQL query to insert user into the database
    QSqlQuery query;
    query.prepare("INSERT INTO UserRegistration (firstName, lastName, username, password, eMail, phoneNumber) "
                  "VALUES (:firstName, :lastName, :username, :password, :email, :phoneNumber)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":email", email);
    query.bindValue(":phoneNumber", phoneNumber);
    query.bindValue(":dateOfBirth", dateOfBirth);  // Assuming dateOfBirth is a variable holding the date value
    query.bindValue(":address", address);

    if (!query.exec()) {
        // Handle SQL query error
    }

    // Close the database connection
    db.close();

    // Display a message or update the GUI to indicate success
    statusLabel->setText("Registration successful!");
}


// void UserRegistrationWidget::setupConnections() {
//     // Connect the registerButton's clicked signal to the registerUser slot
//     connect(registerButton, &QPushButton::clicked, this, &UserRegistrationWidget::registerUser);
// }

UserRegistrationWidget::~UserRegistrationWidget() {
    // Destructor implementation, if needed
}
