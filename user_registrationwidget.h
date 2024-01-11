#ifndef USER_REGISTRATIONWIDGET_H
#define USER_REGISTRATIONWIDGET_H

#include <QDialog>

namespace Ui {
class user_RegistrationWidget;
}

class user_RegistrationWidget : public QDialog
{
    Q_OBJECT

public:
    explicit user_RegistrationWidget(QWidget *parent = nullptr);
    ~user_RegistrationWidget();

private:
    Ui::user_RegistrationWidget *ui;
};

#endif // USER_REGISTRATIONWIDGET_H
