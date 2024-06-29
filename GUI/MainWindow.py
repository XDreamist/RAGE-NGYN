import sys
import os
from PyQt6.QtWidgets import QApplication, QMainWindow
from PyQt6.uic import loadUi

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.load_ui()
        
    def load_ui(self):
        # Load the UI file
        ui_file = "main.ui"
        if os.path.exists(ui_file):
            loadUi(ui_file, self)
        else:
            print(f"Error: UI file {ui_file} not found!")

def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()

    # Monitor the ui file for changes and reload the UI dynamically
    ui_file = "main.ui"
    last_modified = os.path.getmtime(ui_file)

    while True:
        if os.path.getmtime(ui_file) != last_modified:
            last_modified = os.path.getmtime(ui_file)
            window.load_ui()
        app.processEvents()

    sys.exit(app.exec())

if __name__ == "__main__":
    main()
