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
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addLabelToGraphicsView();
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
        titleLabel->setStyleSheet("QLabel { color: " + textColor.name() + "; }");
        titleLabel->move(150, 150);
        titleLabel->show();

        QLabel *secondLabel = new QLabel("Empowering Finances, Enabling Dreams: Your Money, Your Solution", this);
        secondLabel->setFont(QFont("Arial", 14, QFont::DemiBold));
        secondLabel->setStyleSheet("color: Yellow");
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

        connect(button, &QPushButton::clicked, this, &MainWindow::handleButtonClick);
        button->show();

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


        connect(btnRegister, &QPushButton::clicked, this, &MainWindow::handleRegisterButtonClick);
        btnRegister->show();

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

    user_RegistrationWidget registrationDialog(this);
    registrationDialog.exec();
    qDebug() << "Successfully Registered!";
}

void MainWindow::handleAboutUsButtonClick()
{
    qDebug() << "Clicked!";
    // Add your button click handling code here
}





