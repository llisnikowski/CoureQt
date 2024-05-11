#pragma once
#include <QObject>
#include <QQmlEngine>
#include <QString>

class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString text READ getText WRITE setText NOTIFY textChanged FINAL)
    Q_PROPERTY(int size MEMBER m_size CONSTANT)

public:
    Message(QObject *parent = nullptr);
    Message(QString text, QObject *parent = nullptr);

    QString getText() const;
    void setText(const QString &text);

signals:
    void textChanged(const QString text);

private:
    QString m_text = "example text";
    int m_size = 20;
};


