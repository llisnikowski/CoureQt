#include "Counter.hpp"
#include <QDebug>

void Counter::noSlotFunction(int value)
{
    qDebug() << "call: no slot function";
}

void Counter::privateSlotFunction(int value)
{
    qDebug() << "call: private slot function";
}