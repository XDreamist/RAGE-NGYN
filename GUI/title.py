import sys
from PyQt6.QtWidgets import QApplication, QWidget, QPushButton, QHBoxLayout
from PyQt6.QtGui import QIcon
from PyQt6.QtCore import Qt
from PyQt6.QtWidgets import QStyle

class TitleBar(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        
        style = self.style() if parent is None else parent.style()
        
        closeButton = QPushButton(self)
        maxButton = QPushButton(self)
        minButton = QPushButton(self)

        closeButton.setIcon(style.standardIcon(QStyle.StandardPixmap.SP_TitleBarCloseButton))
        maxButton.setIcon(style.standardIcon(QStyle.StandardPixmap.SP_TitleBarMaxButton))
        minButton.setIcon(style.standardIcon(QStyle.StandardPixmap.SP_TitleBarMinButton))

        layout = QHBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.addWidget(minButton)
        layout.addWidget(maxButton)
        layout.addWidget(closeButton)
        self.setLayout(layout)

def main():
    app = QApplication(sys.argv)
    window = QWidget()
    window.setWindowTitle('Custom TitleBar Example')
    window.resize(400, 300)

    titleBar = TitleBar(window)
    layout = QHBoxLayout(window)
    layout.addWidget(titleBar)
    window.setLayout(layout)

    window.show()

    sys.exit(app.exec())

if __name__ == "__main__":
    main()
