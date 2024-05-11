#pragma once
#include <QObject>
#include <QQmlEngine>
#include <QString>
#include "Message.hpp"
#include <QList>
#include <QColor>
#include "Header.hpp"

class MessageList : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    // can use QList<Message*> (QList<QObject*>) or better QAbstractListModel
    Q_PROPERTY(QVariant list READ getList RESET clearList NOTIFY listChanged)
    Q_PROPERTY(int messageLimit MEMBER messageLimit)
    Q_PROPERTY(QColor messageColor MEMBER messageColor NOTIFY messageColorChanged)
    Q_PROPERTY(QObject* header MEMBER header CONSTANT)

public:
    MessageList(QObject *parent = nullptr)
    :QObject{parent}, header{new Header}
    {
        list.push_back(new Message("default", this));
        list.push_back(new Message("message", this));
    }

    QVariant getList(){
        return QVariant::fromValue(this->list);
    }
    void clearList(){
        this->list.clear();
        emit this->listChanged();
    }

public slots:
    void addMessage(QString text){
        if(list.size() >= messageLimit){
            list.pop_front();
        }
        this->list.push_back(new Message(text, this));
        emit this->listChanged();
    }

signals:
    void listChanged();
    void messageColorChanged();

private:
    QObject *header;
    QVector<Message*> list;
    int messageLimit = 3;
    QColor messageColor;
};


