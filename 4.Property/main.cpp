#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>              //for rootContext()


#include "Message.hpp"

bool changeProperties(Message &message)
{
    QObject::connect(&message, &Message::textChanged,
    [](QString newText){
        qDebug() << "Changed message to: " << newText;
    });

    QVariant textProperty = message.property("text");
    if(!textProperty.isValid()) return false;
    if(!textProperty.canConvert<QString>()) return false;

    QString text = textProperty.toString();
    qDebug() << "Current message: " << text;

    return message.setProperty("text", "new message");
}

int main(int argc, char *argv[])
{
    Message message; // befor engine

    changeProperties(message);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(u"qrc:/qmlTest/Main.qml"_qs);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.rootContext()->setContextProperty("message", &message);
    engine.loadFromModule("qmlTest", "Main");

    return app.exec();
}