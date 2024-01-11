#include "mainwindow.h"
//#include "user_registrationwidget.h"


#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDebug>
#include <QMainWindow>
#include <QPixmap>
#include <QLinearGradient>
#include <QBrush>
#include <QGradient>
#include <QtGui>
#include <QtCore>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "BankingApp_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w;


    w.show();

    //user_RegistrationWidget registrationWidget;
    //registrationWidget.resize(900, 600);
    //registrationWidget.exec();


    return a.exec();
}
