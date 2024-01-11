#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>


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


    if (titleLabel) {
        // QLabel found, you can use it here
        titleLabel->setText("Banking Made Easy.");
        titleLabel->setFont(QFont("Arial", 28, QFont::Bold));
        titleLabel->setAlignment(Qt::AlignCenter);

        // Set text Color using styleSheet
        titleLabel->setStyleSheet("color: White");
        titleLabel->move(150, 150); // Adjust the position as needed
        titleLabel->show(); // Make sure to call show() to make the QLabel visible

        // Create another QLabel
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

    } else {
        qDebug() << "Error: QLabel 'BankMadeEasy' not found";
    }
}

void MainWindow::handleButtonClick()
{
    qDebug() << "Button clicked!";
    // Add your button click handling code here
}
