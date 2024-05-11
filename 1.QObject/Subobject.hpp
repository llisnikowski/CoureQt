#pragma once
#include <QObject>
#include <QDebug>

class Subobject : public QObject
{
public:
    Subobject(QObject * parent)
    :QObject{parent}
    {
        qDebug() << "Subobject::Subobject";
    }

    ~Subobject(){
        qDebug() << "Subobject::~Subobject";
    }
};