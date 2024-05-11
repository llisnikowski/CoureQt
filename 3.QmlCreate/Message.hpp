#pragma once
#include <QObject>
#include <QString>
#include <QQmlEngine>

class Message : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString text MEMBER text CONSTANT)

private:
    QString text = "This is example message";
};