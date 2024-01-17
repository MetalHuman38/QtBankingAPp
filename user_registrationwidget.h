#ifndef USER_REGISTRATIONWIDGET_H
#define USER_REGISTRATIONWIDGET_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

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

private slots:
    void cancelButtonClick();
    void previewDetailsButtonClick();

private:
    Ui::user_RegistrationWidget *ui;

    //Helper functions..
    QLabel* createLabel(const QString &text, int fontSize, const QColor &color, Qt::Alignment alignment, int leftMargin = 0, int topMargin = 0, int rightMargin = 0, int bottomMargin = 0);
    QLineEdit* createLineEdit(const QString &placeholder, int fontSize, int width, int height);
    QPushButton* createButton(const QString &text, int fontSize, int width, int height, const QString &backgroundColor, const QString &borderColor);
};



#endif // USER_REGISTRATIONWIDGET_H
