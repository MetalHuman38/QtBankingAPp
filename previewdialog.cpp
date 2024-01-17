#include "previewdialog.h"

#include <QWidget>

previewDialog::previewDialog(QWidget *parent)
    : QDialog {parent}
{
    //Initialize Labels
    firstNameLabel = new QLabel(this);
    lastNameLabel = new QLabel(this);
    usernameLabel = new QLabel(this);
    passwordLabel = new QLabel(this);
    emailLabel = new QLabel(this);
    dateOfBirthLabel = new QLabel(this);
    phoneNumberLabel = new QLabel(this);

    mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(firstNameLabel);
    mainLayout->addWidget(lastNameLabel);
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(emailLabel);
    mainLayout->addWidget(dateOfBirthLabel);
    mainLayout->addWidget(phoneNumberLabel);

    //Initialize Buttons
    confirmButton = new QPushButton("Confirm", this);
    editButton = new QPushButton("Edit", this);

    connect(confirmButton, &QPushButton::clicked, this, &previewDialog::confirmDetails);
    connect(editButton, &QPushButton::clicked, this, &previewDialog::editDetails);

    setLayout(mainLayout);
}

void previewDialog::setUserData(const QString &firstNameText, const QString &lastNameText,
                                   const QString &usernameText, const QString &passwordText,
                                   const QString &emailText, const QString &dateOfBirthText,
                                   const QString &phoneNumberText)
{
    firstNameLabel->setText("First Name: " + firstNameText);
    lastNameLabel->setText("Last Name: " + lastNameText);
    usernameLabel->setText("Username: " + usernameText);
    passwordLabel->setText("Password: " + passwordText);
    emailLabel->setText("Email: " + emailText);
    dateOfBirthLabel->setText("Date of Birth: " + dateOfBirthText);
    phoneNumberLabel->setText("Phone Number: " + phoneNumberText);
}


void::previewDialog::confirmDetails(){

}

void::previewDialog::editDetails(){

}




