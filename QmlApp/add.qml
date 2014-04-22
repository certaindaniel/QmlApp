import QtQuick 1.1

Rectangle {
    id: rectangleAdd
    width: 360
    height: 360

    Column {
        id: columnAdd
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10

        Row {
            id: rowName
            width: 134
            spacing: 10

            Text {
                id: textName
                height: 20
                text: qsTr("Name:")
                anchors.top: parent.top
                anchors.topMargin: 3
                font.pixelSize: 12
            }

            Rectangle {
                width: 80
                height: 20
                color: "#85aeff"
                anchors.right: parent.right
                anchors.rightMargin: 0

                TextEdit {
                    id: textEditName
                    width: 80
                    height: 20
                    color: "#141414"
                    selectionColor: "green"
                    font.pixelSize: 12
                    text: qsTr("")
                }
            }
        }

        Row {
            id: rowAge
            width: 134
            spacing: 10

            Text {
                id: textAge
                text: qsTr("Age:")
                anchors.top: parent.top
                anchors.topMargin: 3
                font.pixelSize: 12
            }

            Rectangle {
                width: 80
                height: 20
                color: "#85aeff"
                anchors.right: parent.right
                anchors.rightMargin: 0

                TextEdit {
                    id: textEditAge
                    width: 80
                    height: 20
                    text: qsTr("")
                    font.pixelSize: 12
                }
            }
        }

        Row {
            id: rowBirthday
            spacing: 10

            Text {
                id: textBirthday
                text: qsTr("Birthday:")
                anchors.top: parent.top
                anchors.topMargin: 2
                font.pixelSize: 12
            }

            Rectangle {
                width: 80
                height: 20
                color: "#85aeff"
                anchors.right: parent.right
                anchors.rightMargin: 0

                TextEdit {
                        id: textEditBirthday
                        width: 80
                        height: 20
                        text: qsTr("")
                        font.pixelSize: 12
                }
            }
        }

        Button {
            id : saveButton
            text : "Save"
            anchors.left: parent.left
            anchors.leftMargin: 20
            border.color: "#ffbc57"
            width: 96
            height: 64
            onClicked: {
                console.log("Save Data");
                // Save to SQLite >>> Start
                console.log(textEditName.text);
                console.log(textEditAge.text);
                console.log(textEditBirthday.text);
                DatabaseManager.addUserData(textEditName.text,textEditAge.text,textEditBirthday.text);
                // Save to SQLite <<< End

            }
        }
    }
}

