#pragma once
#include <QObject>
#include <QQmlEngine>
#include <QString>

class Counter : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public slots:
    void increment(){
        value++;
        qDebug() << "value: " << value;
    }

    int getValue(){
        return value;
    }

public:
    Q_INVOKABLE void emitValue() {
        emit valueChanged(value);
    }

signals:
    void valueChanged(int value);

private:
    int value = 0;
};


