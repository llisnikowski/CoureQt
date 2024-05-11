#include "Root.hpp"
#include <QDebug>
#include "Subobject.hpp"

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