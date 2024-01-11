#include "user_registrationwidget.h"
#include "ui_user_registrationwidget.h"

user_RegistrationWidget::user_RegistrationWidget(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::user_RegistrationWidget)
{
    ui->setupUi(this);
}

user_RegistrationWidget::~user_RegistrationWidget()
{
    delete ui;
}
