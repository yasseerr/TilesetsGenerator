import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.13
import QtQuick.Layouts 1.3
import Qt.labs.folderlistmodel 2.12
import Tiles 1.0

ApplicationWindow{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
//    background: Rectangle{
//        anchors.fill: parent
//        color: "#87919E"
//    }
    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            Action {
                id:newTileset
                text: qsTr("&New...")
                shortcut: StandardKey.New
                onTriggered: {
                }
            }
            Action {
                id: openTileset
                shortcut: StandardKey.Open
                text: qsTr("&Open...") ;
            }
            Action {
                id:saveTileset
                shortcut: StandardKey.Save
                text: qsTr("&Save")
                onTriggered: {
                    tilesCanvas.saveToImage()
                }

            }
            Action {
                id:saveAsTileset
                shortcut: StandardKey.SaveAs
                text: qsTr("Save &As...")
            }
            MenuSeparator { }
            Action {
                id:quitApp
                shortcut: StandardKey.Quit
                text: qsTr("&Quit")
            }
        }
        Menu {
            title: qsTr("&Edit")
            Action { text: qsTr("Cu&t") }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }

    Item {
        id: root
        anchors.fill: parent

        Row
        {
            id:actionMenu
            height: 70
            clip: true
            spacing: 3
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.right: basicTilesList.left
            anchors.rightMargin: 5

            Button {
                id: generateButton
                text: qsTr("generate from \n selected sprites \n selected masks")
                onClicked: {
                    tilesCanvas.sprites = basicTilesList.selectedSprites
                    tilesCanvas.maskes = masksList.selectedMasks
                    tilesCanvas.cellSize = cellspinBox.value
                    tilesCanvas.gridWidth = widthspinBox.value
                    tilesCanvas.generateTiles()
                }
            }
            Button {
                id: generateSM
                text: qsTr("generate from \n all sprites \n selected mask")
            }
            Button {
                id: generateall
                text: qsTr("generate from \n all sprites \n all masks")
            }

            Text {
                id: element
                width: 40
                height: 70
                text: qsTr("Grid \n Width")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: 12
            }

            SpinBox {
                id: widthspinBox
                height: generateall.height
                value: 10
                to: 9000
                editable: true
            }

            Text {
                id: element1
                width: 40
                height: 70
                text: qsTr("cell \n Size")
                font.pixelSize: 12
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }

            SpinBox {
                id: cellspinBox
                height: generateall.height
                value: 40
                to: 9000
                editable: true
            }




        }
        Flickable{
            id: tilesFlickable
            clip: true
            anchors.right: basicTilesList.left
            anchors.rightMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.bottom: masksList.top
            anchors.bottomMargin: 5
            anchors.top: actionMenu.bottom
            anchors.topMargin: 5

            contentWidth: tilesCanvas.width
            contentHeight: tilesCanvas.height

            Tilescanvas{
                id: tilesCanvas
                width: cellspinBox.value * widthspinBox.value
                height: width
            }
        }
        Rectangle {
            id: rectangle
            color: "#00000000"
            border.width: 2
            anchors.fill: tilesFlickable
        }

        BasicTilesList {
            id: basicTilesList
            clip: true
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 0
        }

        MasksList {
            id: masksList
            clip: true
        }
    }


    //Men
}

/*##^##
Designer {
    D{i:15;anchors_height:200;anchors_width:200}
}
##^##*/
