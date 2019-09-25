import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13

ListView {
    id: basicTilesList
    width: parent.width * 0.1
    layoutDirection: Qt.RightToLeft
    keyNavigationWraps: false
    anchors.top: parent.top
    anchors.topMargin: 10
    anchors.right: parent.right
    anchors.rightMargin: 0
    delegate: Item {
        width: parent.width
        height: width
        Rectangle {
            anchors.fill: parent
            anchors.margins: 2
            color: colorCode
        }
        
        Text {
            text: name
            font.bold: true
            anchors.centerIn: parent
        }
    }
    model: ListModel {
        ListElement {
            name: "Grey"
            colorCode: "grey"
        }
        
        ListElement {
            name: "Red"
            colorCode: "red"
        }
        
        ListElement {
            name: "Blue"
            colorCode: "blue"
        }
        
        ListElement {
            name: "Green"
            colorCode: "green"
        }
    }
}
