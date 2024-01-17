#include "user_registrationwidget.h"
#include "user_registrationwidget.h"
#include "ui_user_registrationwidget.h"
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
    mainLayout->setSpacing(0);
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
    formLayout->setSpacing(0);
    formLayout->setContentsMargins(5, 10, 0, 0);
    formLayout->setAlignment(Qt::AlignLeft);
    formLayout->setContentsMargins(0, 40, 0, 0);

    QLineEdit *firstNameLineEdit = createLineEdit("Enter your First Name...", 12,200,30);
    formLayout->addRow("First Name:", firstNameLineEdit);
    formLayout->addWidget(firstNameLineEdit);

    QLineEdit *lastNameLineEdit = createLineEdit("Enter your First Name...", 12,200,30);
    formLayout->addRow("Last Name:", lastNameLineEdit);
    formLayout->addWidget(lastNameLineEdit);

    QLineEdit *usernameLineEdit = createLineEdit("Enter your desired username...", 12,200,30);
    formLayout->addRow("Username:", usernameLineEdit);
    formLayout->addWidget(usernameLineEdit);

    QLineEdit *passwordLineEdit = createLineEdit("Create a Password...", 12,200,30);
    formLayout->addRow("Password:", passwordLineEdit);
    formLayout->addWidget(passwordLineEdit);

    QLineEdit *emailLineEdit = createLineEdit("Create a Password...", 12,200,30);
    formLayout->addRow("Email:", emailLineEdit);
    formLayout->addWidget(emailLineEdit);

    QLineEdit *dateOfBirthLineEdit = createLineEdit("Create a Password...", 12,200,30);
    formLayout->addRow("Date of Birth:", dateOfBirthLineEdit);
    formLayout->addWidget(dateOfBirthLineEdit);

    QLineEdit *phoneNumberLineEdit = createLineEdit("Create a Password...", 12,200,30);
    formLayout->addRow("Phone:", phoneNumberLineEdit);
    formLayout->addWidget(phoneNumberLineEdit);

    // Add the QLineEdit to the layout
    mainLayout->addWidget(formWidget);



    // Create a QHBoxLayout for the buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Add spacing between buttons
    buttonLayout->addSpacing(20);

    // Create the "Cancel" button
    QPushButton *cancelButton = new QPushButton("Cancel", this);
    buttonLayout->addWidget(cancelButton);
    cancelButton->setFont(QFont("Arial", 16));
    cancelButton->setFixedSize(150, 40);
    cancelButton->setObjectName("evilButton");
    cancelButton->setStyleSheet("QPushButton#evilButton {"
                          "    background-color: gold;"
                          "    border-style: outset;"
                          "    border-width: 1px;"
                          "    border-radius: 5px;"
                          "    border-color: blue;"
                          "    font: bold 14px;"
                          "    min-width: 5em;"
                          "    padding: 6px;"
                          "}"
                          "QPushButton#evilButton:pressed {"
                          "    background-color: rgb(224, 0, 0);"
                          "    border-style: inset;"
                          "}");
    // int cancelButtonX = this->width() - cancelButton->width() - 50; // Adjust the margin as needed
    // int cancelButtonY = 2; // Adjust the vertical position as needed
    // cancelButton->move(cancelButtonX, cancelButtonY);

    connect(cancelButton, &QPushButton::clicked, this, &user_RegistrationWidget::cancelButtonClick);
    //cancelButton->show();

    QPushButton *previewButton = new QPushButton("Preview Details", this);
    buttonLayout->addWidget(previewButton);
    previewButton->setFont(QFont("Arial", 16));
    previewButton->setFixedSize(150, 40);
    previewButton->setObjectName("evilButton");
    previewButton->setStyleSheet("QPushButton#evilButton {"
                                "    background-color: gold;"
                                "    border-style: outset;"
                                "    border-width: 1px;"
                                "    border-radius: 5px;"
                                "    border-color: blue;"
                                "    font: bold 14px;"
                                "    min-width: 5em;"
                                "    padding: 6px;"
                                "}"
                                "QPushButton#evilButton:pressed {"
                                "    background-color: rgb(224, 0, 0);"
                                "    border-style: inset;"
                                "}");



    connect(previewButton, &QPushButton::clicked, this, &user_RegistrationWidget::previewDetailsButtonClick);
    //cancelButton->show();

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
                          "    background-color: " + backgroundColor + ";"
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

void user_RegistrationWidget::previewDetailsButtonClick(){



}

user_RegistrationWidget::~user_RegistrationWidget()
{
    delete ui;
}

