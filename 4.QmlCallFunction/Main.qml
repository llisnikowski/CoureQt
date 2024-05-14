import QtQuick
import QtQuick.Controls 2.15

Window {
    width: 600; height: 400
    
    visible: true
    title: qsTr("Hello World")

    Counter{
        id: counter

        // signal: valueChanged -> onValueChanged
        onValueChanged: (value) =>{
            console.log("signal1 " + value)
        }
        // OR
        // onValueChanged: {
        //     console.log("signal2")
        // }
        // OR
        // onValueChanged: console.log("signal3")
    }


    Column {
        Button{
            property int clickCount: 0;
            text: "increment"
            onClicked: {
                counter.increment();
            }
        }

        Button{
            property int clickCount: 0;
            text: "getValue"
            onClicked: {
                text = "getValue = " + counter.getValue();
            }
        }

        Text {
            id: description
            text: "Counter"

            Connections {
                target: counter
                function onValueChanged(value) {
                    description.text = "value: " + value
                }
            }
        }

        Button{
            property int clickCount: 0;
            text: "emit"
            onClicked: {
                counter.emitValue();
            }
        }
    }
}
