# ============================================
# WWDevLauncher Shortcut Creator
# Use it on fresh pull: Creates shortcut. Updates local paths accordingly.
# ============================================

$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectRoot = Split-Path -Parent $ScriptDir
$ClaudePath = (Get-Command claude -ErrorAction SilentlyContinue).Source

$WshShell = New-Object -ComObject WScript.Shell
$ShortcutPath = Join-Path $ProjectRoot "WWDevLauncher.lnk"
$Shortcut = $WshShell.CreateShortcut($ShortcutPath)
$Shortcut.TargetPath = Join-Path $ScriptDir "StartClaudeCodeSession.bat"
$Shortcut.WorkingDirectory = $ProjectRoot
$Shortcut.Description = "PS Batch code pattern for developing in cpp using Rider IDE + UE. Purpose: To make the session setup as simple and effortless as possible."

if ($ClaudePath) {
    $Shortcut.IconLocation = "$ClaudePath,0"
    Write-Host "Icon set to Claude Code icon" -ForegroundColor Cyan
} else {
    Write-Host "Claude CLI not found - using default icon" -ForegroundColor Yellow
}

$Shortcut.Save()
Write-Host "Shortcut created successfully at: $ShortcutPath" -ForegroundColor Green
Write-Host "Project root: $ProjectRoot" -ForegroundColor Gray
