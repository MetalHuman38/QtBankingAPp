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

    // Add a QLabel at the top of the page
    QLabel *titleLabel = new QLabel("Registering for BankApp Online Banking.", this);
    titleLabel->setFont(QFont("Arial", 16, QFont::Bold));
    titleLabel->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    titleLabel->setMargin(0);
    titleLabel->setContentsMargins(0,0,0,0);
    titleLabel->setStyleSheet("color: White");
    //titleLabel->setFixedSize(700, 70);
    //titleLabel->show();

    // Add a QLabel at the top of the page
    QLabel *titleLabel1 = new QLabel("Who can Register?", this);
    titleLabel1->setFont(QFont("Arial", 12, QFont::DemiBold));
    titleLabel1->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    //titleLabel1->setFixedSize(200, 50);
    titleLabel1->setContentsMargins(0,8,0,0);
    titleLabel1->setStyleSheet("color: White");
    //titleLabel1->show();
    titleLabel1->setMargin(0);


    // Add a QLabel at the top of the page
    QLabel *titleLabel2 = new QLabel("Should be 18yrs and over.", this);
    titleLabel2->setFont(QFont("Arial", 12, QFont::DemiBold));
    titleLabel2->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    //titleLabel2->setFixedSize(200, 50);
    titleLabel2->setContentsMargins(0,8,0,0);
    titleLabel2->setStyleSheet("color: White");
    titleLabel2->setMargin(0);
    //titleLabel2->show();

    //Add Qlabel to the layout
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(titleLabel1);
    mainLayout->addWidget(titleLabel2);

    QWidget *formWidget = new QWidget(this);

    QFormLayout *formLayout = new QFormLayout(formWidget);
    formLayout->setSpacing(0);
    formLayout->setContentsMargins(5, 10, 0, 0);
    formLayout->setAlignment(Qt::AlignLeft);
    formLayout->setContentsMargins(0, 50, 0, 0);

    // Programmatically add a QLineEdit
    QLineEdit *firstNameLineEdit = new QLineEdit(formWidget);
    firstNameLineEdit->setPlaceholderText("Enter your First Name");
    firstNameLineEdit->setFont(QFont("Arial", 12));
    firstNameLineEdit->setFixedSize(200, 30);
    formLayout->addRow("First Name:", firstNameLineEdit);

    // Add other QLabel and QLineEdit pairs as needed
    QLineEdit *lastNameLineEdit = new QLineEdit(formWidget);
    lastNameLineEdit->setPlaceholderText("Enter your Last Name");
    lastNameLineEdit->setFont(QFont("Arial", 12));
    lastNameLineEdit->setFixedSize(200, 30);
    formLayout->addRow("Last Name:", lastNameLineEdit);


    // Add the QLineEdit to the layout
    mainLayout->addWidget(formWidget);
}

user_RegistrationWidget::~user_RegistrationWidget()
{
    delete ui;
}

