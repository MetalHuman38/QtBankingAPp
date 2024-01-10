// UserRegistrationWidget.cpp

#include "UserRegistrationWidget.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>




UserRegistrationWidget::UserRegistrationWidget(QWidget *parent) : QWidget(parent) {
    setupUi();
    setupConnections();
}

void UserRegistrationWidget::registerUser() {
    // Get user input from the GUI elements
    QString firstName = firstNameLineEdit->text();
    QString lastName = lastNameLineEdit->text();
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    QString email = emailLineEdit->text();
    QString phoneNumber = phoneNumberLineEdit->text();

    // Connect to the database (ensure QSqlDatabase is properly set up)
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("FinApp");
    db.setUserName("root");
    db.setPassword("London1983@@@!");

    if (!db.open()) {
        // Handle database connection error
        return;
    }

    // Execute SQL query to insert user into the database
    QSqlQuery query;
    query.prepare("INSERT INTO NewUserRegister (firstName, lastName, username, password, eMail, phoneNumber) "
                  "VALUES (:firstName, :lastName, :username, :password, :email, :phoneNumber)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":email", email);
    query.bindValue(":phoneNumber", phoneNumber);

    if (!query.exec()) {
        // Handle SQL query error
    }

    // Close the database connection
    db.close();

    // Display a message or update the GUI to indicate success
    statusLabel->setText("Registration successful!");
}


void UserRegistrationWidget::setupUi() {
    // Create GUI elements (QLineEdit, QPushButton, QLabel, etc.) and layout
    // Add them to the layout using QVBoxLayout or other layout managers

    firstNameLineEdit = new QLineEdit(this);
    lastNameLineEdit = new QLineEdit(this);
    usernameLineEdit = new QLineEdit(this);
    passwordLineEdit = new QLineEdit(this);
    emailLineEdit = new QLineEdit(this);
    phoneNumberLineEdit = new QLineEdit(this);

    QPushButton *registerButton = new QPushButton("Register", this);

    statusLabel = new QLabel(this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(firstNameLineEdit);
    layout->addWidget(lastNameLineEdit);
    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(emailLineEdit);
    layout->addWidget(phoneNumberLineEdit);
    layout->addWidget(registerButton);
    layout->addWidget(statusLabel);
}

void UserRegistrationWidget::setupConnections() {
    // Connect the registerButton's clicked signal to the registerUser slot
    connect(registerButton, &QPushButton::clicked, this, &UserRegistrationWidget::registerUser);
}
