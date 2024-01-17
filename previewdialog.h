#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>



class previewDialog : public QDialog
{
    Q_OBJECT
public:
    explicit previewDialog(QWidget *parent = nullptr);

    // Function to set and display user data
    void setUserData(const QString &firstNameText, const QString &lastNameText,
                     const QString &usernameText, const QString &passwordText,
                     const QString &emailText, const QString &dateOfBirthText,
                     const QString &phoneNumberText);

private slots:
    // Function called when the user clicks "Confirm"
    void confirmDetails();

    // Function called when the user clicks "Edit"
    void editDetails();

private:
    // Add QLabel members to display user data
    QLabel *firstNameLabel;
    QLabel *lastNameLabel;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QLabel *emailLabel;
    QLabel *dateOfBirthLabel;
    QLabel *phoneNumberLabel;
    // Add more labels as needed

    // Add a layout to arrange the labels
    QVBoxLayout *mainLayout;

    // Add buttons for confirmation and editing
    QPushButton *confirmButton;
    QPushButton *editButton;

signals:
};

#endif // PREVIEWDIALOG_H
