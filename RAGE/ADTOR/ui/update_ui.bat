@echo off
setlocal enabledelayedexpansion

set UIC_PATH=H:\RAGE-NGYN\RAGE\bin\uic.exe
set UI_DIR=H:\RAGE-NGYN\RAGE\ADTOR\UI
set OUTPUT_DIR=H:\RAGE-NGYN\RAGE\ADTOR\UI

echo Updating UI...
for %%f in ("%UI_DIR%\*.ui") do (
    set "UI_PATH=%%f"
    set "HEADER_PATH=%OUTPUT_DIR%\%%~nf.h"
    set "UI_FILE=%%~nf.ui"
    set "HEADER_FILE=%%~nf.h"

    if not exist "!HEADER_PATH!" (
        echo !UI_FILE! -^> !HEADER_FILE! : CREATED
        call "%UIC_PATH%" -o "!HEADER_PATH!" "!UI_PATH!"
    ) else (
        rem Compare timestamps using RoboCopy (reliable for this task)
        robocopy /l "!UI_PATH!" "!HEADER_PATH!" /njh /njs /ndl /nc /ns >nul
        if errorlevel 1 (
            echo !UI_FILE! -^> !HEADER_FILE! : MODIFIED
            call "%UIC_PATH%" -o "!HEADER_PATH!" "!UI_PATH!"
        ) else (
            echo !UI_FILE! -^> !HEADER_FILE! : UNCHANGED
        )
    )
)
echo UPDATED... To change updation, come to update_ui.bat in ui folder.
endlocal