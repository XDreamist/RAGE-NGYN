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
        rem Get last modified timestamps
        for %%A in ("!UI_PATH!") do set "UI_MODIFIED=%%~tA"
        for %%B in ("!HEADER_PATH!") do set "HEADER_MODIFIED=%%~tB"

        rem Convert timestamps to a comparable format (YYYYMMDDHHMMSS)
        set "UI_MODIFIED=!UI_MODIFIED:~6,4!!UI_MODIFIED:~3,2!!UI_MODIFIED:~0,2!!UI_MODIFIED:~11,2!!UI_MODIFIED:~14,2!!UI_MODIFIED:~17,2!"
        set "HEADER_MODIFIED=!HEADER_MODIFIED:~6,4!!HEADER_MODIFIED:~3,2!!HEADER_MODIFIED:~0,2!!HEADER_MODIFIED:~11,2!!HEADER_MODIFIED:~14,2!!HEADER_MODIFIED:~17,2!"

        if "!UI_MODIFIED!" gtr "!HEADER_MODIFIED!" (
            echo !UI_FILE! -^> !HEADER_FILE! : MODIFIED
            call "%UIC_PATH%" -o "!HEADER_PATH!" "!UI_PATH!"
        ) else (
            echo !UI_FILE! -^> !HEADER_FILE! : UNCHANGED
        )
    )
)
echo UPDATED... To change updation, come to update_ui.bat in UI folder.
endlocal