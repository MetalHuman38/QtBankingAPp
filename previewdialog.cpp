#include "previewdialog.h"
#include "errorhandler.h"
#include "namevalidator.h"
#include "passwordvalidator.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QWidget>
#include <QDialog>
#include <QVariant>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QDate>





previewDialog::previewDialog(QWidget *parent)
    : QDialog {parent}, nameValidator(&errorHandler)
                      , usernamevalidator(&errorHandler)
                      , passwordvalidator(&errorHandler)

{
    //Initialize Labels
    firstNameLabel = new QLabel(this);
    lastNameLabel = new QLabel(this);
    usernameLabel = new QLabel(this);
    passwordLabel = new QLabel(this);
    emailLabel = new QLabel(this);
    dateOfBirthLabel = new QLabel(this);
    phoneNumberLabel = new QLabel(this);




    // Create a QLabel for the title
    QLabel *titleLabel = new QLabel("Preview your details. Click Confirm to save details or Edit to make changes.", this);
    titleLabel->setFont(QFont("Arial", 16, QFont::Bold));
    titleLabel->setAlignment(Qt::AlignCenter | Qt::AlignTop);
    titleLabel->setStyleSheet("color: white;");
    titleLabel->setFixedWidth(700);
    titleLabel->setContentsMargins(0,5,0,0);


    //Initialize Buttons
    confirmButton = new QPushButton("Confirm", this);
    editButton = new QPushButton("Edit", this);

    confirmButton->setFixedWidth(150);  // Adjust the width as needed
    editButton->setFixedWidth(150);      // Adjust the width as needed

    connect(confirmButton, &QPushButton::clicked, this, &previewDialog::confirmAndInsertDetails);
    connect(editButton, &QPushButton::clicked, this, &previewDialog::editDetails);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(firstNameLabel);
    mainLayout->addWidget(lastNameLabel);
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(emailLabel);
    mainLayout->addWidget(dateOfBirthLabel);
    mainLayout->addWidget(phoneNumberLabel);

    mainLayout->setSpacing(0);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(confirmButton);
    mainLayout->addLayout(buttonLayout);

    setStyleSheet("QDialog { background-color: blue; }"
                  "QLabel { color: gold; font: 18px; }"  // Style for input text
                  "QPushButton { background-color: gold; "
                  "border-style: outset;"
                  "border-width: 1px; "
                  "border-radius: 5px; "
                  "border-color: blue; "
                  "font: bold 16px; "
                  "min-width: 5em; "
                  "padding: 6px; }"
                  "QPushButton:pressed { background-color: rgb(224, 0, 0); border-style: inset; }");

    statusLabel = new QLabel(this);
    statusLabel->setAlignment(Qt::AlignCenter);
    statusLabel->setStyleSheet("color: green;");  // You can customize the style as needed


    // Set dialog size
    setFixedSize(1000, 600);

    setLayout(mainLayout);
}

void previewDialog::setUserData(const QString &firstNameText, const QString &lastNameText,
                                   const QString &usernameText, const QString &passwordText,
                                   const QString &emailText, const QString &dateOfBirthText,
                                   const QString &phoneNumberText)
{

    firstNameLabel->setText("First Name:   " + firstNameText);
    lastNameLabel->setText("Last Name:   " + lastNameText);
    usernameLabel->setText("Username:   " + usernameText);
    passwordLabel->setText("Password:   " + passwordText);
    emailLabel->setText("Email:   " + emailText);
    dateOfBirthLabel->setText("Date of Birth:   " + dateOfBirthText);
    phoneNumberLabel->setText("Phone Number:   " + phoneNumberText);
}

QString extractLabelText(const QLabel* label) {
    if (label) {

        QString fullText = label->text().trimmed();

        QStringList parts = fullText.split("  ");
        if (parts.size() > 1){
            return parts.at(1);
        }
    }
    return QString();  // Return an empty string if the label is null
}

// Helper function to convert date format
QString convertDateFormat(const QString &inputDate, const QString &inputFormat, const QString &outputFormat) {
    QDate date = QDate::fromString(inputDate, inputFormat);
    if (!date.isValid()) {
        qDebug() << "Invalid date format:" << inputDate;
        return QString();  // Return an empty string for invalid date
    }

    return date.toString(outputFormat);
}



void previewDialog::confirmAndInsertDetails() {
    // Retrieve user details from labels
    QString firstName = extractLabelText(firstNameLabel);
    QString lastName = extractLabelText(lastNameLabel);
    QString username = extractLabelText(usernameLabel);
    QString password = extractLabelText(passwordLabel);
    QString email = extractLabelText(emailLabel);
    QString dateString = extractLabelText(dateOfBirthLabel);
    QString phoneNumber = extractLabelText(phoneNumberLabel);


    firstName = firstName.trimmed();
    lastName = lastName.trimmed();

    NameValidator nameValidator(&errorHandler);
    ErrorCode firstAndLastNameValidation = nameValidator.validate(firstName, lastName);
    if (firstAndLastNameValidation != ErrorCode::NoError) {
        QString errorMessages = errorHandler.getErrorMessage(firstAndLastNameValidation);
        qDebug() << errorMessages;
        QMessageBox::critical(this, "Error", errorMessages);
        return;
    }

    password = password.trimmed();
    PasswordValidator passwordValidator(&errorHandler);
    ErrorCode passwordValidation = passwordValidator.validate(password);
    if(passwordValidation != ErrorCode::NoError){

        QString errorMessages = errorHandler.getErrorMessage(passwordValidation);
        qDebug() << errorMessages;
        QMessageBox::critical(this, "Error", errorMessages);
        return;
    }



    // Trim leading and trailing whitespaces from dateString
    dateString = dateString.trimmed();

    QDate dateOfBirth = QDate::fromString(dateString, "MM/dd/yyyy");

    if (!dateOfBirth.isValid()) {
        // Handle the case where the date is not valid
        qDebug() << "Invalid date format:" << dateString;
        QMessageBox::critical(this, "Error", "Invalid date format. Check the date of birth.");
        return;
    }

    QString sqlFormattedDate = dateOfBirth.toString("yyyy-MM-dd");


    // Connect to the database (ensure QSqlDatabase is properly set up)
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("BankingSystem");
    db.setUserName("root");
    db.setPassword("London1983@@@!");
    bool ok = db.open();


    if (!ok) {
        // Handle database connection error
        qDebug() << "Database connection error:" << db.lastError().text();
        QMessageBox::critical(this, "Error", "Failed to connect to the database. Check connection details.");
        return;
    }

    username = username.trimmed();

    usernameValidator usernameValidator(&errorHandler);
    ErrorCode UsernameValidation = usernameValidator.validate(username, db);

    if (UsernameValidation != ErrorCode::NoError) {
        QString errorMessages = errorHandler.getErrorMessage(UsernameValidation);
        qDebug() << errorMessages;
        QMessageBox::critical(this, "Error", errorMessages);
        return;
    }



    // Execute SQL query to insert user into the database
    QSqlQuery query;
    query.prepare("INSERT INTO UserRegistration (firstName, lastName, username, password, eMail, dateOfBirth, phoneNumber) "
                  "VALUES (:firstName, :lastName, :username, :password, :email, :dateOfBirth, :phoneNumber)");
    query.bindValue(":firstName", firstName);
    query.bindValue(":lastName", lastName);
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":email", email);
    query.bindValue(":dateOfBirth", sqlFormattedDate);
    query.bindValue(":phoneNumber", phoneNumber);


    if (!query.exec()) {
        // Handle SQL query error
        qDebug() << "SQL query error:" << query.lastError().text();
        statusLabel->setText("Failed to insert Data into Database!");
        QMessageBox::critical(this, "Error", "Failed to insert data into the Database.");
    } else {
        qDebug() << "Registration Successful!";
        // Display a message or update the GUI to indicate success
        statusLabel->setText("Registration successful!");
        QMessageBox::information(this, "success", "Registration Successful!");
    }

    // Close the database connection
    db.close();

    accept();  // Close the dialog after confirming details
}


void previewDialog::setLabelWithMargins(QLabel *label, const QString &text)
{
    label->setText(text);

    // Set contents margins to add space around the label
    label->setContentsMargins(0, 0, 0, 5);  // Adjust the bottom margin as needed

    label->setStyleSheet("QLabel {color: gold; font: 18px;}");

    // Apply additional styling if desireds
    label->setStyleSheet("color: white;");
}


void previewDialog::confirmDetails(){

    accept();
}

void previewDialog::editDetails()
{
    reject();
}




