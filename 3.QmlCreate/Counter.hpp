#pragma once
#include <QObject>

class Counter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int value MEMBER value CONSTANT)
public:

    int value = 0;
};