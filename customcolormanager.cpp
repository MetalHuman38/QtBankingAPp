#include "customcolormanager.h"
#include <QtWidgets>
#include <QLabel>
#include <QFont>


CustomColorManager& CustomColorManager::getInstance() {
    static CustomColorManager instance;
    return instance;

}


CustomColorManager::CustomColorManager()
{
    // Set initial custom colors
    setCustomColor("Text", QColor(Qt::white));
    setCustomColor("ButtonBackground", QColor(Qt::blue));

    // ... other color settings ...
    QLinearGradient gradient;
    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(1, Qt::yellow);
    //CustomColorManager::getInstance().setGradientColor("TextGradient", gradient);

}

CustomColorManager::~CustomColorManager()
{
    // Perform cleanup tasks if needed
    // For example, releasing resources or saving state
}


void CustomColorManager::setCustomColor(const QString& key, const QColor& color) {
    customColors[key] = color;
}

QColor CustomColorManager::getCustomColor(const QString& key) const{
    if(customColors.contains(key)){
        return customColors[key];
    }else{
        return QColor();
    }
}


void CustomColorManager::setGradientColor(const QString& key, const QGradient& gradient) {
    customGradients[key] = gradient;
}

QGradient CustomColorManager::getGradientColor(const QString& key) const {
    if (customGradients.contains(key)) {
        return customGradients[key];
    } else {
        // Return a default gradient or handle the case where the key is not found
        return QLinearGradient();
    }
}




