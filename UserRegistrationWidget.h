#ifndef USERREGISTRATIONWIDGET_H
#define USERREGISTRATIONWIDGET_H


#include <QtWidgets/QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QtSql/QSqlDatabase>
#include <QtWidgets/QLabel>
#include <QtSql/QSqlQuery>
#include <QDialog>


namespace Ui{
class user_RegistrationWidget;
}

class UserRegistrationWidget : public QDialog {
    Q_OBJECT

public:
    explicit UserRegistrationWidget(QWidget *parent = nullptr);
    ~UserRegistrationWidget();

public slots:
    void registerUser();

private:

    Ui::user_RegistrationWidget *ui;

    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *dateOfBirthLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *addressLineEdit;
    QLabel *statusLabel;
    QPushButton *registerButton;
    void setupUi();
    void setupConnections();
};

#endif // USERREGISTRATIONWIDGET_H
