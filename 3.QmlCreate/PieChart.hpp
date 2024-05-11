#pragma once

#include <QtQuick/QQuickPaintedItem>
#include <QColor>

class PieChart : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged FINAL)
    QML_ELEMENT

public:
    PieChart(QQuickItem *parent = nullptr);

    QColor color() const;
    void setColor(const QColor &color);

    void paint(QPainter *painter) override;

signals:
    void colorChanged(const QColor color);

private:
    QColor m_color;
};