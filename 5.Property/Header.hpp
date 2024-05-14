#pragma once
#include <QObject>
#include <QQmlEngine>
#include <QString>
#include "Message.hpp"
#include <QList>
#include <QColor>

class Header : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text MEMBER text NOTIFY textChanged)
    Q_PROPERTY(QColor color MEMBER color NOTIFY colorChanged)

public:
    Header(QObject *parent = nullptr)
    :QObject{parent}, text{"HEADER"}
    {}

signals:
    void textChanged();
    void colorChanged();

private:
    QString text;
    QColor color;
};


