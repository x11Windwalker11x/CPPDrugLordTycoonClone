@echo off
REM ============================================
REM WWDevLauncher Setup
REM Use it on fresh pull: Creates shortcut. Updates local paths accordingly.
REM ============================================

echo Setting up WWDevLauncher shortcut...
echo.

powershell -ExecutionPolicy Bypass -File "%~dp0CreateShortcut.ps1"

echo.
pause
