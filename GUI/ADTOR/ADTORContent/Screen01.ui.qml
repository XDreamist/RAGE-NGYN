/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/

import QtQuick 6.5
import QtQuick.Controls 6.5
import ADTOR

Rectangle {
    width: Constants.width
    height: Constants.height
    color: "#1e1e1e"

    Frame {
        id: frame
        anchors.fill: parent
        anchors.leftMargin: 8
        anchors.rightMargin: 8
        anchors.topMargin: 8
        anchors.bottomMargin: 8

        Frame {
            id: frame2
            x: 150
            y: -12
            width: 200
            height: 200
            anchors.right: parent.right
            anchors.rightMargin: 8
        }

        Frame {
            id: frame1
            x: 695
            anchors.fill: parent
        }

        Frame {
            id: frame3
            x: 823
            y: 584
            width: 200
            height: 200
            anchors.right: parent.right
            anchors.rightMargin: 8
        }

        Frame {
            id: frame4
            width: 200
            height: 200
            anchors.top: parent.top
            anchors.topMargin: 0
        }
    }

}
