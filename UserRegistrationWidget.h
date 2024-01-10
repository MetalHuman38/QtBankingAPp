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


class UserRegistrationWidget : public QWidget {
    Q_OBJECT

public:
    UserRegistrationWidget(QWidget *parent = nullptr);

public slots:
    void registerUser();

private:
    QLineEdit *firstNameLineEdit;
    QLineEdit *lastNameLineEdit;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *emailLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLabel *statusLabel;
    QPushButton *registerButton;

    void setupUi();
    void setupConnections();
};

#endif // USERREGISTRATIONWIDGET_H
