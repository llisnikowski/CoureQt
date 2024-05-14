#include "Root.hpp"
#include <QDebug>
#include "Subobject.hpp"
#include <QMetaEnum>
#include <QMetaObject>


Root::Root(QObject *parent)
:QObject{parent}
{
    qDebug() << "Root::Root";

    // dynamic allocate
    // ! parent of subobject == this
    subobject = new Subobject{this}; 
}

Root::~Root()
{
    qDebug() << "Root::~Root";

    // not required
    // deallocate in QObject destructor 
    /*
    if(subobject) {
        delete subobject;
        subobject = nullptr;
    }
    */
}

void Root::demoMetaObject()
{
    QMetaObject meta = Root::staticMetaObject;
    // or
    // const QMetaObject * meta = this->metaObject();

    qDebug() << "\n-----| Q_OBJECT |-----";
    qDebug() << "classInfo: " << meta.className();
    qDebug() << "methodCount: " << meta.methodCount();
    qDebug() << "enumeratorCount: " << meta.enumeratorCount();
    qDebug() << "----------------------\n";
}

void Root::demoMetaEnum()
{
    QMetaEnum metaEnum = QMetaEnum::fromType<Color>();
    
    qDebug() << "\n-----| Q_ENUM |-----";
    qDebug() << "name: " << metaEnum.name();
    qDebug() << "scope: " << metaEnum.scope();
    qDebug() << "red key: " << metaEnum.key(static_cast<int>(Color::RED));
    qDebug() << "red to key: " << metaEnum.valueToKey(static_cast<int>(Color::RED));
    qDebug() << "green to value:" << metaEnum.keyToValue("GREEN");
    qDebug() << "key count" << metaEnum.keyCount();
    qDebug() << "--------------------\n";
}