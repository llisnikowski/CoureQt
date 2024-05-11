#include "Message.hpp"

Message::Message(QObject *parent)
:QObject{parent}
{}
Message::Message(QString text, QObject *parent)
:QObject{parent}, m_text{text}
{}

QString Message::getText() const
{
    return this->m_text;
}
void Message::setText(const QString &text)
{
    this->m_text = text;
    emit textChanged(this->m_text);
}
