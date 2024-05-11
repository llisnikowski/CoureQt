#pragma once
#include <QObject>

class Counter : public QObject
{
    Q_OBJECT

public:
    Counter() { value = 0; }

    int getValue() const { 
        return value;
    }

    void noSlotFunction(int value);

public slots:
    void setValue(int value) {
        if (this->value == value) return;
        this->value = value;
        emit valueChanged(this->value);
    }
    void add1(){
        this->value++;
        emit valueChanged(this->value);
    }

private slots:
    void privateSlotFunction(int value);

signals:
    void valueChanged(int newValue);

private:
    int value;
};
