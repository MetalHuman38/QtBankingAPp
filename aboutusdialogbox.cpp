#include "aboutusdialogbox.h"

#include <QLabel>
#include <QVBoxLayout>

aboutUsDialogBox::aboutUsDialogBox(QWidget *parent) : QDialog(parent){
    setWindowTitle("ABOUT US");

    QLabel *infoLabel = new QLabel("This is information about the app.", this);
    infoLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(infoLabel);
}


