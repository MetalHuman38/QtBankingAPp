#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "customcolormanager.h"
#include "user_registrationwidget.h"
#include <QPushButton>
#include <QColorDialog>
#include <QGraphicsColorizeEffect>
#include <QVariant>
#include <QGradient>
#include <QAction>
#include <QStackedWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addLabelToGraphicsView();

    stackedWidget = new QStackedWidget(this);
    //setCentralWidget(stackedWidget);  // Set the stacked widget as the central widget

    // Create and add pages to the stacked widget
    QWidget *userRegistrationPage = new user_RegistrationWidget(this);
    stackedWidget->addWidget(userRegistrationPage);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addLabelToGraphicsView()
{
    // Assuming BankMadeEasy is the QLabel object name inside MainWindow.ui
    QLabel *titleLabel = findChild<QLabel*>("BankMadeEasy");

    QColor textColor = CustomColorManager::getInstance().getCustomColor("Text");
    QGradient textGradient = CustomColorManager::getInstance().getGradientColor("TextGradient");



    if (titleLabel) {
        // QLabel found, you can use it here
        titleLabel->setText("Banking Made Easy.");
        titleLabel->setFont(QFont("Arial", 28, QFont::Bold));
        titleLabel->setAlignment(Qt::AlignCenter);
        //titleLabel->setStyleSheet("color: White");
        titleLabel->setStyleSheet("QLabel { color: " + textColor.name() + "; }");
        titleLabel->move(150, 150); // Adjust the position as needed
        titleLabel->show(); // Make sure to call show() to make the QLabel visible


        QLabel *secondLabel = new QLabel("Empowering Finances, Enabling Dreams: Your Money, Your Solution", this);
        secondLabel->setFont(QFont("Arial", 14, QFont::DemiBold));
        secondLabel->setStyleSheet("color: Yellow");
        //secondLabel->setWordWrap(true);
        secondLabel->setAlignment(Qt::AlignLeft);

        int secondLabelX = 150;
        int secondLabelY = 250;
        int secondLabelWidth = 700; // Adjust the width as needed
        int secondLabelHeight = 150; // Adjust the height as needed
        secondLabel->setGeometry(secondLabelX, secondLabelY, secondLabelWidth, secondLabelHeight);
        secondLabel->show();


        // Create a QPushButton styled like a label
        QPushButton *aboutUsButton = new QPushButton("ABOUT US", this);
        aboutUsButton->setFont(QFont("Arial", 14, QFont::DemiBold));
        aboutUsButton->setStyleSheet("text-align: left; color: Yellow; background-color: transparent; border: none;");
        aboutUsButton->setFlat(true);  // Make the button flat to look like a label

        int aboutUsButtonX = 22;
        int aboutUsButtonY = 22;
        int aboutUsButtonWidth = 700; // Adjust the width as needed
        int aboutUsButtonHeight = 15; // Adjust the height as needed
        aboutUsButton->setGeometry(aboutUsButtonX, aboutUsButtonY, aboutUsButtonWidth, aboutUsButtonHeight);
        aboutUsButton->show();

        // Create a QPushButton
        QPushButton *button = new QPushButton("Log On", this);
        button->setFont(QFont("Arial", 16));
        button->setObjectName("evilButton");
        // Move the button to the far right of the window
        int buttonX = this->width() - button->width() - 22; // Adjust the margin as needed
        int buttonY = 22; // Adjust the vertical position as needed
        button->move(buttonX, buttonY);

        button->setStyleSheet("QPushButton#evilButton {"
                              "    background-color: yellow;"
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


        //Button to Register
        QPushButton *btnRegister = new QPushButton("Register", this);
        btnRegister->setFont(QFont("Arial", 16));
        btnRegister->setObjectName("evilButton");
        // Move the button to the far right of the window
        int btnRegisterX = this->width() - btnRegister->width() - 150; // Adjust the margin as needed
        int btnRegisterY = 22; // Adjust the vertical position as needed
        btnRegister->move(btnRegisterX, btnRegisterY);

        btnRegister->setStyleSheet("QPushButton#evilButton {"
                              "    background-color: yellow;"
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



        connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        btnRegister->show();


        connect(btnRegister, &QPushButton::clicked, this, &MainWindow::handleRegisterButtonClick);
        button->show();

    } else {
        qDebug() << "Error: QLabel 'BankMadeEasy' not found";
    }
}




void MainWindow::handleButtonClick()
{
    qDebug() << "Button clicked!";
    // Add your button click handling code here

}

void MainWindow::handleRegisterButtonClick()
{

    // Add your button click handling code here
    registrationWidget.resize(900, 700);

    registrationWidget.exec();
    qDebug() << "Successfully Registered!";
}

void MainWindow::handleAboutUsButtonClick()
{
    qDebug() << "Clicked!";
    // Add your button click handling code here
}

void MainWindow::openRegistrationPage()
{
    // Switch to the registration page when the button is clicked
    stackedWidget->setCurrentIndex(0);  // Adjust the index based on the order of addition
}



