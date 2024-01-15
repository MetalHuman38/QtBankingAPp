#ifndef CUSTOMCOLORMANAGER_H
#define CUSTOMCOLORMANAGER_H

#include <QColorDialog>
#include <QColor>
#include <QHash>
#include <QString>
#include <QtWidgets/QWidget>
#include <QtGui>
#include <QtCore>
#include <QLabel>

class CustomColorManager :  public QObject
{
public:
    static CustomColorManager& getInstance();

    void setCustomColor(const QString& key, const QColor& color);
    QColor getCustomColor(const QString& key) const;

    void setGradientColor(const QString& key, const QGradient& gradient);
    QGradient getGradientColor(const QString& key) const;

private:
    QHash<QString, QColor> customColors;
    QHash<QString, QGradient> customGradients;

    CustomColorManager();
    ~CustomColorManager();

    CustomColorManager(const CustomColorManager&) = delete;
    CustomColorManager& operator=(const CustomColorManager&) = delete;

};

#endif // CUSTOMCOLORMANAGER_H
