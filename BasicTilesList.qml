import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import Qt.labs.folderlistmodel 2.12

ListView {
    property var selectedSprites: []
    id: basicTilesList
    width: parent.width * 0.1
    layoutDirection: Qt.RightToLeft
    keyNavigationWraps: false
    anchors.top: parent.top
    anchors.topMargin: 10
    anchors.right: parent.right
    anchors.rightMargin: 0
    delegate: Item {
        property bool selected: false
        width: parent.width
        height: width
        clip: true
        Image {
            source: "file:sprites/"+fileName
            anchors.fill: parent
            anchors.margins: 2
        }
        
        Text {
            text: fileName
            fontSizeMode: Text.Fit
            font.bold: true
            anchors.centerIn: parent
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(parent.selected){
                    parent.selected = false;
                    selectedSprites.splice(selectedSprites.indexOf(fileName),1)
                }
                else{
                    parent.selected = true;
                    selectedSprites.push(fileName)
                }
            }
        }
        Rectangle{
            visible: parent.selected
            anchors.fill: parent
            color: "#F5DDDD"
        }
    }
    model:FolderListModel{
        folder: "file:sprites/"
        nameFilters: ["*.png"]
        showDirs: false
    }


}
