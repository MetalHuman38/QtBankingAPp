#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsView>
#include <QGraphicsScene>


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

private:
    Ui::MainWindow *ui;

    // Private function to add QLabel to QGraphicsView
    void addLabelToGraphicsView();
};
#endif // MAINWINDOW_H
