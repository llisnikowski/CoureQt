#include <QCoreApplication>
#include "Counter.hpp"
#include <QDebug>


void display(const Counter &a, const Counter &b);

void noMemberFunction();


void connect1()
{
    Counter a, b;
    display(a, b); // a == 0, b == 0
    
    a.setValue(10);
    display(a, b); // a == 10, b == 0
    
//public slot
    QObject::connect(&a, &Counter::valueChanged, &b, &Counter::setValue);

    a.setValue(20);
    display(a, b); // a == 20, b == 20

    a.add1();
    display(a, b); // a == 21, b == 21

//private slot
    // QObject::connect(&a, &Counter::valueChanged, &b, &Counter::privateSlotFunction); //error
//noslot function
    QObject::connect(&a, &Counter::valueChanged, &b, &Counter::noSlotFunction);
//no member function
    QObject::connect(&a, &Counter::valueChanged, &noMemberFunction);
//lambda
    QObject::connect(&a, &Counter::valueChanged, [](int value){/*...*/});

// fewer arguments than a signal
    QObject::connect(&a, &Counter::valueChanged, [](){/*...*/});
// argument converted
    QObject::connect(&a, &Counter::valueChanged, [](float value){/*...*/});    
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);


    connect1();

    return 0;
    // return app.exec();
}


void display(const Counter &a, const Counter &b)
{
    qDebug() << "a == " << a.getValue() << " ; b == " << b.getValue();
}
void noMemberFunction()
{
    qDebug() << "call: no member function";
}



