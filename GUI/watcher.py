import time
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import subprocess
import os
import platform

import MainWindow as MW

class ChangeHandler(FileSystemEventHandler):
    def __init__(self, file_path, command, restart):
        self.file_path = file_path
        self.command = command
        self.restart = restart

    def on_modified(self, event):
        if event.src_path == self.file_path:
            print(f"Detected changes in {self.file_path}. Running command...")
            subprocess.run(self.command, shell=True)
            self.restart.set()
        

def watch_file(file_path, command):
    if not os.path.isabs(file_path):
        file_path = os.path.abspath(file_path)

    restart = threading.Event()
        
    observer = Observer()
    event_handler = ChangeHandler(file_path, command, restart)
    # subprocess.Popen(['python3', 'main.py'])
    observer.schedule(event_handler, path=file_path, recursive=False)
    observer.start()
    print(f"Watching {file_path} for changes...")

    try:
        while True:
            if restart.is_set():
                MW.window.reload_logic()
                proc.terminate()
                observer.stop()
                observer.join()
                restart.clear()
                observer = Observer()
                event_handler = ChangeHandler(file_path, command, restart)
                observer.schedule(event_handler, path=file_path, recursive=False)
                observer.start()
                proc = subprocess.Popen(['python', 'main.py'])
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()

if __name__ == "__main__":
    import threading
    file_to_watch = "main.ui"  # Replace with your file path
    command_to_run = "pyuic6 -x main.ui -o main.py"  # Replace with the command you want to run
    watch_file(file_to_watch, command_to_run)
