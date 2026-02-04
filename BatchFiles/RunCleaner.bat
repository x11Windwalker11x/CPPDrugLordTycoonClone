@echo off
Title Clean and Regen
color 0A

echo Killing processes...
taskkill /F /IM UnrealEditor.exe 2>nul
taskkill /F /IM UE5Editor.exe 2>nul
taskkill /F /IM ShaderCompileWorker.exe 2>nul
taskkill /F /IM Rider64.exe 2>nul
taskkill /F /IM devenv.exe 2>nul
timeout /t 2 /nobreak >nul

cd /d "%~dp0.."

echo Deleting folders...
if exist "Binaries" (
    echo Deleting Binaries...
    rmdir /S /Q "Binaries"
)
if exist "Intermediate" (
    echo Deleting Intermediate...
    rmdir /S /Q "Intermediate"
)

if exist "Plugins" (
    for /d %%P in (Plugins\*) do (
        if exist "%%P\Binaries" (
            echo Deleting %%P\Binaries...
            rmdir /S /Q "%%P\Binaries"
        )
        if exist "%%P\Intermediate" (
            echo Deleting %%P\Intermediate...
            rmdir /S /Q "%%P\Intermediate"
        )
    )
)

echo Regenerating...

dotnet "D:\Program Files\Epic Games\UE_5.6\Engine\Binaries\DotNET\UnrealBuildTool\UnrealBuildTool.dll" -projectfiles -project="D:\Unreal Projects (2nd Place)\CPPDrugLordClone\CPPDrugLordClone.uproject" -game -engine

echo.
echo Opening Rider...
start "" "C:\Program Files\JetBrains\JetBrains Rider 2025.1.5\bin\rider64.exe"

pause