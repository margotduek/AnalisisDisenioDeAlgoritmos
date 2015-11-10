import QtQuick 2.5

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Text {
        anchors.centerIn: parent
        text: "Hola Margot"
        anchors.verticalCenterOffset: -142
        anchors.horizontalCenterOffset: 1
    }
}

