@echo off
REM ============================================
REM Claude Code Development Session Launcher
REM ============================================
REM This batch file starts:
REM 1. JetBrains Rider with the project
REM 2. PowerShell in the project root folder with Claude Code
REM ============================================

REM Get the directory where this batch file is located
set "BATCH_DIR=%~dp0"
REM Remove trailing backslash and go up one level to project root
set "PROJECT_ROOT=%BATCH_DIR%.."

REM Find Rider installation
set "RIDER_PATH="
for /d %%i in ("C:\Program Files\JetBrains\JetBrains Rider*") do set "RIDER_PATH=%%i\bin\rider64.exe"

REM Find .uproject file
for %%f in ("%PROJECT_ROOT%\*.uproject") do set "PROJECT_FILE=%%f"

echo Starting Claude Code Development Session...
echo.

REM Start Rider with the project (non-blocking)
if defined RIDER_PATH (
    echo [1/2] Launching JetBrains Rider...
    start "" "%RIDER_PATH%" "%PROJECT_FILE%"
) else (
    echo [1/2] Rider not found - skipping...
)

REM Give Rider a moment to start
timeout /t 2 /nobreak > nul

REM Start PowerShell in project root and launch Claude Code
echo [2/2] Opening PowerShell with Claude Code...
echo.
pushd "%PROJECT_ROOT%"
start powershell -NoExit -Command "claude"
popd

echo.
echo Session launched successfully!
timeout /t 2 /nobreak > nul
