#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>              //for rootContext()

#include "Counter.hpp"


int main(int argc, char *argv[])
{
    Counter counter; // befor engine

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    counter.value = 7;

    // const QUrl url(u"qrc:/qml/Main.qml"_qs);
    // const QUrl url(u"qrc:/qml/Main.qml"_qs);

    const QUrl url(u"qrc:/qmlTest/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    // Message msg;

    // engine.setInitialProperties({
    //     {"msg", QVariant::fromValue(&msg)}
    // });

    engine.rootContext()->setContextProperty("counter", &counter);

    engine.loadFromModule("qmlTest", "Main");
    // engine.load(url);

    return app.exec();
}