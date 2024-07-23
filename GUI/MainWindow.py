import sys
import os
from PyQt6.QtWidgets import QApplication, QMainWindow
from PyQt6.uic import loadUi
from PyQt6.QtCore import Qt, QPoint

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.load_ui()
        self.setFramelessWindow()
        
    def load_ui(self):
        # Load the UI file
        ui_file = "main.ui"
        if os.path.exists(ui_file):
            loadUi(ui_file, self)
        else:
            print(f"Error: UI file {ui_file} not found!")

    def setFramelessWindow(self):
        # Remove window frame
        self.setWindowFlag(Qt.WindowType.FramelessWindowHint)
        
        # Implement methods for handling window dragging
        self.old_pos = self.pos()
        self.mouse_pos = None
        
    def mousePressEvent(self, event):
        if event.button() == Qt.MouseButton.LeftButton:
            # self.mouse_pos = event.globalPos()
            self.old_pos = self.pos()

    def mouseMoveEvent(self, event):
        if self.mouse_pos:
            # delta = QPoint(event.globalPos() - self.mouse_pos)
            # self.move(self.old_pos + delta)
            pass

    def mouseReleaseEvent(self, event):
        if event.button() == Qt.MouseButton.LeftButton:
            self.mouse_pos = None

def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()

    sys.exit(app.exec())

if __name__ == "__main__":
    main()
