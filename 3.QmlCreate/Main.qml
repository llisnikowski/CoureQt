import QtQuick

Window {
    width: 600; height: 400
    
    visible: true
    title: qsTr("Hello World")

    PieChart {
        id: aPieChart
        anchors.centerIn: parent
        width: 100; height: 100
        color: "red"
    }

    Message {
        id: message
    }

    Text {
        text: message.text
        anchors { 
            bottom: parent.bottom; 
            horizontalCenter: 
            parent.horizontalCenter; 
            bottomMargin: 20 
        }
    }

    Text {
        text: "Counter: " + counter.value
    }

}
