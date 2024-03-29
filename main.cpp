#include "mainwindow.h"
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
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>


void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    Q_UNUSED(context);

    switch (type) {
    case QtDebugMsg:
        fprintf(stderr, "Debug: %s\n", msg.toUtf8().constData());
        break;
    case QtWarningMsg:
        fprintf(stderr, "Warning: %s\n", msg.toUtf8().constData());
        break;
    case QtCriticalMsg:
        fprintf(stderr, "Critical: %s\n", msg.toUtf8().constData());
        break;
    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s\n", msg.toUtf8().constData());
        abort();
    case QtInfoMsg:
        break;
    }
}


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

    qInstallMessageHandler(customMessageHandler);

    MainWindow w;
    w.show();

    //user_RegistrationWidget registrationWidget;
    //registrationWidget.resize(900, 600);
    //registrationWidget.exec();


    return a.exec();
}
