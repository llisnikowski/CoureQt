#include "PieChart.hpp"
#include <QPen>
#include <QPainter>

PieChart::PieChart(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

void PieChart::paint(QPainter *painter)
{
    QPen pen(m_color, 2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
}

QColor PieChart::color() const
{
    return m_color;
}
void PieChart::setColor(const QColor &color)
{
    m_color = color;
}