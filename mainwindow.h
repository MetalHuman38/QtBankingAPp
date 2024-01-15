#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QStackedWidget>
#include "user_registrationwidget.h"


#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    // Add slots for handling events in the main window
private slots:
    void handleButtonClick();
    void handleRegisterButtonClick();
    void handleAboutUsButtonClick();




private:
    Ui::MainWindow *ui;

    void addLabelToGraphicsView();
    QStackedWidget *stackedWidget;
    // Private function to add QLabel to QGraphicsView
    QPushButton *btnRegister;
    user_RegistrationWidget registrationWidget;


};
#endif // MAINWINDOW_H
