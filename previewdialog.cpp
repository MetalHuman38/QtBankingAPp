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

    connect(confirmButton, &QPushButton::clicked, this, &previewDialog::confirmDetails);
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

    // Apply stylesheets
    setStyleSheet("QDialog { background-color: blue; }"
                  "QLabel { color: gold;"
                  "         font: 18px"
                  "         }"
                  "QPushButton {"
                  "    background-color: gold;"
                  "    border-style: outset;"
                  "    border-width: 1px;"
                  "    border-radius: 5px;"
                  "    border-color: blue;"
                  "    font: bold 16px;"
                  "    min-width: 5em;"
                  "    padding: 6px;"
                  "}"
                  "QPushButton:pressed {"
                  "    background-color: rgb(224, 0, 0);"
                  "    border-style: inset;"
                  "}");

    // Set dialog size
    setFixedSize(1000, 600);

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

void previewDialog::setLabelWithMargins(QLabel *label, const QString &text)
{
    label->setText(text);

    // Set contents margins to add space around the label
    label->setContentsMargins(0, 0, 0, 10);  // Adjust the bottom margin as needed

    // Apply additional styling if desired
    label->setStyleSheet("color: white;");
}


void previewDialog::confirmDetails(){

    accept();
}

void previewDialog::editDetails()
{
    reject();
}




