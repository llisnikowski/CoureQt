import QtQuick
import QtQuick.Controls 2.15

Window {
    width: 600; height: 400
    
    visible: true
    title: qsTr("Hello World")


    Column {
        Text {
            text: "Counter: " + message.text
            font.pixelSize: message.size
        }

        Button{
            property int clickCount: 0;
            text: "click"
            onClicked: {
                clickCount++;
                message.text = "clicked " + clickCount + " times";
            }
        }

        MessageList{
            id: messageList
            messageLimit: 10        // set 'messageLimit' property
            messageColor: "green"   // set 'messageColor' property
        }

        Button{
            property int nextNumber: 0;
            text: "Add Message"
            onClicked: {
                messageList.addMessage("Message number: " + nextNumber)
                nextNumber++;
            }
        }

        Rectangle{
            id: header
            border.color: "red"
            width: parent.width
            height: 40
            Text {
                text: messageList.header.text
                font.pixelSize: 30
            }
        }

        ListView{
            id: messageListView
            model: messageList.list
            width: parent.width
            height: 150
            anchors.topMargin: 20
            anchors.bottomMargin: 20
            spacing: 2

            delegate: Rectangle{
                required property var modelData // (messageList.list[i])
                width: parent.width
                height: 30
                border.color: "blue"
                Text {
                    text: modelData.text
                    font.pixelSize: modelData.size
                    color: messageList.messageColor
                }
            }
        }
    }
}
