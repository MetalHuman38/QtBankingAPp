#include "user_registrationwidget.h"
#include "user_registrationwidget.h"
#include "ui_user_registrationwidget.h"
#include "UserRegistrationWidget.h"
#include "previewdialog.h"
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>
#include <QFormLayout>
#include <QPushButton>



user_RegistrationWidget::user_RegistrationWidget(QWidget *parent)
    : QDialog(parent), ui(new Ui::user_RegistrationWidget)
{
    ui->setupUi(this);

    // Set up the background gradient using CustomColorManager
    QLinearGradient gradient;
    gradient.setStart(0, 0);          // Starting point of the gradient
    gradient.setFinalStop(width(), 0); // Ending point of the gradient

    // Add color stops to the gradient
    gradient.setColorAt(0.5, QColor(Qt::blue)); // Color in the middle
    gradient.setColorAt(1, QColor(Qt::darkBlue));   // Color at the ending point

    // Set up additional properties if needed, e.g., gradient.setSpread(QGradient::ReflectSpread);

    // Apply the gradient to the background
    QPalette palette;
    palette.setBrush(QPalette::Window, gradient);

    setAutoFillBackground(true);
    setPalette(palette);

    // Create a QVBoxLayout for the user_RegistrationWidget
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(8);
    mainLayout->setContentsMargins(50, 10, 0, 0);
    mainLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLabel *titleLabel = createLabel("Registering for BankApp Online Banking.", 16, Qt::white, Qt::AlignLeft | Qt::AlignTop);

    QLabel *titleLabel1 = createLabel("Who can Register?", 12, Qt::white, Qt::AlignLeft | Qt::AlignTop);

    QLabel *titleLabel2 = createLabel("Should be 18yrs and over", 12, Qt::white, Qt::AlignLeft | Qt::AlignTop);

    //Add Qlabel to the layout
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(titleLabel1);
    mainLayout->addWidget(titleLabel2);

    QWidget *formWidget = new QWidget(this);

    QFormLayout *formLayout = new QFormLayout(formWidget);
    formLayout->setSpacing(20);
    //formLayout->setContentsMargins(5, 5, 0, 0);
    formLayout->setAlignment(Qt::AlignCenter);
    formLayout->setContentsMargins(0, 40, 0, 40);



    firstNameLineEdit = createLineEdit("Enter your First Name...", 12,200,30);
    QLabel *firstNameLabel = createLabel("First Name:", 12, Qt::yellow, Qt::AlignCenter);
    formLayout->addRow(firstNameLabel, firstNameLineEdit);


    lastNameLineEdit = createLineEdit("Enter your Last Name...", 12,200,30);
    QLabel *lastNameLabel = createLabel("Last Name:", 12, Qt::yellow, Qt::AlignCenter);
    formLayout->addRow(lastNameLabel, lastNameLineEdit);


    usernameLineEdit = createLineEdit("Enter your desired username...", 12,200,30);
    QLabel *usernameLabel = createLabel("Username:", 12, Qt::yellow, Qt::AlignCenter);
    formLayout->addRow(usernameLabel, usernameLineEdit);


    passwordLineEdit = createLineEdit("Create a Password...", 12,200,30);
    QLabel *passwordLabel = createLabel("Password:", 12, Qt::yellow, Qt::AlignCenter);
    formLayout->addRow(passwordLabel, passwordLineEdit);


    emailLineEdit = createLineEdit("Enter your Email Address...", 12,200,30);
    QLabel *emailLabel = createLabel("Email:", 12, Qt::yellow, Qt::AlignCenter);
    formLayout->addRow(emailLabel, emailLineEdit);


    dateOfBirthLineEdit = createLineEdit("Enter dob in yyyy/MM/dd...", 12,200,30);
    QLabel *dateOfBirthLabel = createLabel("Date of Birth:", 12, Qt::yellow, Qt::AlignCenter);
    formLayout->addRow(dateOfBirthLabel, dateOfBirthLineEdit);

    phoneNumberLineEdit = createLineEdit("Enter your phone number...", 12,200,30);
    QLabel *phoneNumberLabel = createLabel("Phone No:", 12, Qt::yellow, Qt::AlignCenter);
    formLayout->addRow(phoneNumberLabel, phoneNumberLineEdit);


    // Add the QLineEdit to the layout
    mainLayout->addWidget(formWidget);


    // Create a QHBoxLayout for the buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Add spacing between buttons
    buttonLayout->addSpacing(20);

    // Create the "Cancel" button
    QPushButton *cancelButton = createButton("Cancel", 16, 150, 40, "gold", "blue");
    connect(cancelButton, &QPushButton::clicked, this, &user_RegistrationWidget::cancelButtonClick);
    buttonLayout->addWidget(cancelButton);


    // Create the "Preview Detail" button
    QPushButton *previewButton = createButton("Preview", 16, 150, 40, "gold", "blue");
    connect(previewButton, &QPushButton::clicked, this, &user_RegistrationWidget::previewButtonClick);
    buttonLayout->addWidget(previewButton);


    // Add the button layout to the main layout
    mainLayout->addLayout(buttonLayout);
}

QLabel* user_RegistrationWidget::createLabel(const QString &text, int fontSize, const QColor &color,
                                             Qt:: Alignment alignment, int leftMargin, int topMargin,
                                             int rightMargin, int bottomMargin)
{
    QLabel *label = new QLabel(text, this);
    label->setFont(QFont("Arial", fontSize, QFont::DemiBold));
    label->setAlignment(alignment);
    label->setContentsMargins(leftMargin, topMargin, rightMargin, bottomMargin);
    label->setStyleSheet("color: " + color.name());
    return label;

}

QLineEdit* user_RegistrationWidget::createLineEdit(const QString &placeholder, int fontSize, int width, int height)
{
    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText(placeholder);
    lineEdit->setFont(QFont("Arial", fontSize));
    lineEdit->setFixedSize(width, height);
    return lineEdit;
}

QPushButton* user_RegistrationWidget::createButton(const QString &text, int fontSize, int width, int height, const QString &backgroundColor, const QString &borderColor)
{
    QPushButton *button = new QPushButton(text, this);
    button->setFont(QFont("Arial", fontSize));
    button->setFixedSize(width, height);

    // Set up stylesheets for background color and border color
    button->setStyleSheet("QPushButton {"
                          "background-color: " + backgroundColor + ";"
                          "    border-style: outset;"
                          "    border-width: 1px;"
                          "    border-radius: 5px;"
                          "    border-color: " + borderColor + ";"
                          "    font: bold " + QString::number(fontSize) + "px;"
                          "    min-width: 5em;"
                          "    padding: 6px;"
                          "}"
                          "QPushButton:pressed {"
                          "    background-color: rgb(224, 0, 0);"
                          "    border-style: inset;"
                          "}");

    return button;
}


void user_RegistrationWidget::cancelButtonClick(){



}

void user_RegistrationWidget::previewButtonClick(){

    // Get the text from the QLineEdit fields
    QString firstNameText = firstNameLineEdit->text();
    QString lastNameText = lastNameLineEdit->text();
    QString usernameText = usernameLineEdit->text();
    QString passwordText = passwordLineEdit->text();
    QString emailText = emailLineEdit->text();
    QString dateOfBirthText = dateOfBirthLineEdit->text();
    QString phoneNumberText = phoneNumberLineEdit->text();

    // Create and configure the preview dialog
    previewDialog* previewDialogBox = new previewDialog(this);
    previewDialogBox->setUserData(firstNameText, lastNameText, usernameText, passwordText, emailText, dateOfBirthText, phoneNumberText);

    // Show the preview dialog
    if (previewDialogBox->exec() == QDialog::Accepted) {
        // User confirmed the details, proceed with saving
        //saveUserData(); // Implement this function to save the user data
    } else {
        // User chose to edit, no action needed
    }
}


user_RegistrationWidget::~user_RegistrationWidget()
{
    delete ui;
}

