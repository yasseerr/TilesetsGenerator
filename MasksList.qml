import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
import Qt.labs.folderlistmodel 2.12
import Tiles 1.0

ListView {
    property var selectedMasks: []
    id: masksList
    height: parent.width *0.1
    orientation: ListView.Horizontal
    flickableDirection: Flickable.HorizontalFlick
    anchors.right: basicTilesList.left
    anchors.rightMargin: 0
    anchors.left: parent.left
    anchors.leftMargin: 0
    anchors.bottom: parent.bottom
    anchors.bottomMargin: 0
    delegate: Item {
        property bool selected: false
        width: height
        height: parent.height
        Image {
            source: fileURL
            anchors.fill: parent
            anchors.margins: 2
        }
        Rectangle{
            visible: parent.selected
            anchors.fill: parent
            color: "#F5DDDD"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(parent.selected){
                    parent.selected = false;
                    selectedMasks.splice(selectedMasks.indexOf(fileName),1)
                }
                else{
                    parent.selected = true;
                    selectedMasks.push(fileName)
                }
                console.log(selectedMasks)
            }
        }
        
    }
    model:FolderListModel{
        folder: "file:masks/"
        nameFilters: ["*.png"]
        showDirs: false
    }
}
