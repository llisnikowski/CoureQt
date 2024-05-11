#pragma once
#include <QObject>

class Subobject;

class Root : public QObject
{
    Q_OBJECT

public:
    Root(QObject *parent=nullptr);
    ~Root();

private:
    Subobject *subobject;
};

