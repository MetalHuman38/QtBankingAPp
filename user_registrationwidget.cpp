#include "user_registrationwidget.h"
#include "user_registrationwidget.h"
#include "ui_user_registrationwidget.h"
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>



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




    // Add a QLabel at the top of the page
    QLabel *titleLabel = new QLabel("Registering for BankApp Online Banking", this);
    titleLabel->setFont(QFont("Arial", 16, QFont::Bold));
    titleLabel->setAlignment(Qt::AlignCenter);

    //int titleLabelX = -30;
    //int titleLabelY = 30;
    int titleLabelWidth = 700; // Adjust the width as needed
    int titleLabelHeight = 150; // Adjust the height as needed
    //titleLabel->setGeometry(titleLabelX, titleLabelY, titleLabelWidth, titleLabelHeight);
    titleLabel->show();

    // Create a QVBoxLayout for the user_RegistrationWidget
    QVBoxLayout *mainLayout = new QVBoxLayout(this);


    // Programmatically add a QLineEdit
    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setPlaceholderText("Enter your First Name");
    lineEdit->setFont(QFont("Arial", 12));

    // Add the QLineEdit to the layout
    mainLayout->addWidget(lineEdit);
}

user_RegistrationWidget::~user_RegistrationWidget()
{
    delete ui;
}

