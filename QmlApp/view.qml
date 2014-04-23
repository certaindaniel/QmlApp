import QtQuick 1.1

Rectangle {
    width: 360;
    height: 360
    color: "white"

    Component {
        id: appDelegate

        Item {
            width: 360;
            height: 60

            Row {
                spacing: 10
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                Button {
                    width: 96
                    height: 32
                    text: modelData
                    onClicked : {
                        console.log("name");
                    }
                }

                Button {
                    width: 96
                    height: 32
                    text: "Delete ?"
                    onClicked : {
                        console.log("Delete ?");
                    }
                }
            }
        }
    }

    Component {
        id: appHighlight
        Rectangle { width: 360; height: 360; color: "lightsteelblue" }
    }

    GridView {
        anchors.fill: parent
        cellWidth: 360; cellHeight: 60
        //highlight: appHighlight
        focus: true
        model: DatabaseManager.dataModel()
        delegate: appDelegate
    }
}
