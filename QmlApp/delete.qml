import QtQuick 1.1

Rectangle {
    id: rectangleDelete
    width: 360
    height: 360


    Rectangle {
        id: rectangleInfo
        x: 0
        width: 202
        height: 196
        color : "#ffcdbd"
        anchors.top: parent.top
        anchors.topMargin: 40
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: textConfirmation
            x: 69
            y: 20
            text: qsTr("Confirmation")
            font.pixelSize: 12
        }

        Text {
            id: textInfo1
            x: 61
            y: 58
            text: qsTr("Are you sure you")
            font.pixelSize: 12
        }

        Text {
            id: textInfo2
            x: 43
            y: 92
            text: qsTr("want to delete user data ?")
            font.pixelSize: 12
        }

        Text {
            id: textName
            x: 90
            y: 144
            color: "#be0e0e"
            text: qsTr("name")
            font.pixelSize: 12
        }

    }


    Row{
        x: 80
        y: 286
        width: 202
        height: 68
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        spacing: 10

        Button {
            id : yesButton
            text : "Yes"
            border.color: "#ffbb55"
            width: 96
            height: 64
            onClicked: {
                console.log("Add New Data");
                FlowControl.loadAddPage("","","");
            }
        }

        Button {
            id : noButton
            text : "No"
            border.color: "#ffbc57"
            width: 96
            height: 64
            onClicked: {
                console.log("View Data");
                FlowControl.loadViewPage();
            }
        }
    }
}
