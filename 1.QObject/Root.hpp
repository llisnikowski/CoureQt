#pragma once
#include <QObject>

class Subobject;

class Root : public QObject
{
    Q_OBJECT

public:
    Root(QObject *parent=nullptr);
    ~Root();

    enum class Color{
        NONE,
        RED,
        GREEN,
        BLUE
    };
    Q_ENUM(Color)

    void demoMetaObject();
    void demoMetaEnum();

private:
    Subobject *subobject;
};

