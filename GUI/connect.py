import os
import ctypes

# Get the directory path of the current script
script_dir = os.path.dirname(os.path.abspath(__file__))

# Specify the filename to attach
dll_filename = '..\\dep\\x64\\RAGE.dll'

# Construct the full path to the DLL
dll_path = os.path.join(script_dir, dll_filename)

# Load the DLL using the full path
dll = ctypes.CDLL(dll_path)

# Example: Call a function from the DLL
dll.InitOpenGL()

dll.RenderCube()