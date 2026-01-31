$WshShell = New-Object -ComObject WScript.Shell
$ShortcutPath = "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\WWDevLauncher.lnk"
$Shortcut = $WshShell.CreateShortcut($ShortcutPath)
$Shortcut.TargetPath = "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\BatchFiles\StartClaudeCodeSession.bat"
$Shortcut.WorkingDirectory = "D:\Unreal Projects (2nd Place)\CPPDrugLordClone"
$Shortcut.Description = "PS Batch code pattern for developing in cpp using Rider IDE + UE. Purpose: To make the session setup as simple and effortless as possible."
$Shortcut.IconLocation = "C:\Users\Admin\.local\bin\claude.exe,0"
$Shortcut.Save()
Write-Host "Shortcut created successfully at: $ShortcutPath" -ForegroundColor Green
Write-Host "Icon set to Claude Code icon" -ForegroundColor Cyan
