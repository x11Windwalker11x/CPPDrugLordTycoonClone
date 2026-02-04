@echo off
echo === Git Repository Verification ===
echo.
echo ROOT REPO (expect: CppDrugLordTycoonClone):
cd /d "D:\Unreal Projects (2nd Place)\CPPDrugLordClone"
git remote get-url origin
echo.
echo PLUGINS REPO (expect: WWSimulatorFramework):
cd /d "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins"
git remote get-url origin
echo.
echo === Checking for Misplaced Files ===
if exist "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\SimulatorFramework" (
    echo WARNING: SimulatorFramework exists at ROOT - should be in Plugins/
) else (
    echo OK: No plugin folders at root
)
echo.
pause
