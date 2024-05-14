#include <QCoreApplication>
#include "Root.hpp"


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Root root;

    root.demoMetaObject();
    root.demoMetaEnum();

    return 0;
}




