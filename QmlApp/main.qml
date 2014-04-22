import QtQuick 1.1

Rectangle {
    id: rectangle1
    width: 360
    height: 360

    Column{
        x: 0
        y: 0
        spacing: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter

        Button {
            id : addButton
            text : "Add New Data"
            border.color: "#ffbb55"
            width: 96
            height: 64
            onClicked: {
                console.log("Add New Data");
                FlowControl.loadAddPage("name","age","birthday");
            }
        }

        Button {
            id : viewButton
            text : "View Data"
            border.color: "#ffbb55"
            width: 96
            height: 64
            onClicked: {
                console.log("View Data");
                FlowControl.loadViewPage();
            }
        }

        Button {
            id : exitButton
            text : "Exit"
            border.color: "#ffbb55"
            width: 96
            height: 64
            onClicked: {
                console.log("Exit");
                Qt.quit();
            }
        }
    }
}
