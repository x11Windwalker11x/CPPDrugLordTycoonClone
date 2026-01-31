@echo off
REM ============================================
REM Claude Code Development Session Launcher
REM ============================================
REM This batch file starts:
REM 1. JetBrains Rider with the project
REM 2. PowerShell in the project root folder
REM ============================================

set "PROJECT_ROOT=D:\Unreal Projects (2nd Place)\CPPDrugLordClone"
set "RIDER_PATH=C:\Program Files\JetBrains\JetBrains Rider 2025.1.5\bin\rider64.exe"
set "PROJECT_FILE=%PROJECT_ROOT%\CPPDrugLordClone.uproject"

echo Starting Claude Code Development Session...
echo.

REM Start Rider with the project (non-blocking)
echo [1/2] Launching JetBrains Rider...
start "" "%RIDER_PATH%" "%PROJECT_FILE%"

REM Give Rider a moment to start
timeout /t 2 /nobreak > nul

REM Start PowerShell in project root and launch Claude Code
echo [2/2] Opening PowerShell with Claude Code...
echo.
start powershell -NoExit -Command "cd '%PROJECT_ROOT%'; claude"

echo.
echo Session launched successfully!
timeout /t 2 /nobreak > nul
