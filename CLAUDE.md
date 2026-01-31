# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

**CPPDrugLordTycoonClone** is an Unreal Engine 5.6 C++ project using the **Windwalker Modular Framework V2.13** - a comprehensive plugin ecosystem designed for AAA-level performance and marketplace distribution.

## Build Commands

Build the project using Unreal Build Tool:
```bash
# From project root - build Development Editor
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat" CPPDrugLordCloneEditor Win64 Development -Project="D:\Unreal Projects (2nd Place)\CPPDrugLordClone\CPPDrugLordClone.uproject"

# Generate project files
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\GenerateProjectFiles.bat" -project="D:\Unreal Projects (2nd Place)\CPPDrugLordClone\CPPDrugLordClone.uproject"
```

## Architecture Overview

### Layer System (Dependencies Flow DOWN Only)

| Layer | Plugin | Purpose |
|-------|--------|---------|
| **L0** | Windwalker_Productions_SharedDefaults | Interfaces, delegates, data structs, enums, tags |
| **L0.5** | ModularSystemsBase | Shared components, subsystems, helpers |
| **L2** | All feature plugins | Domain-specific functionality |

**Critical Rule:** L2 plugins never depend on each other. Communication flows UP via delegates.

### Plugin Ecosystem (11 Plugins)

**Foundation:**
- `Windwalker_Productions_SharedDefaults` - All contracts (interfaces, delegates, structs)
- `ModularSystemsBase` - Shared helpers, base components, subsystems

**Feature Plugins (L2):**
- `ModularPlayerController` - Pawn orchestration, camera modules, input routing
- `ModularInteractionSystem` - Traces, interactables, spatial hash grid
- `ModularInventorySystem` - Items, slots, containers
- `SimulatorFramework` - Devices, applications, mini-games (6 handler types)
- `AdvancedWidgetFramework` - Widget lifecycle management
- `ModularSaveGameSystem` - Save/load architecture
- `ModularSpawnSystem` - Entity spawning (30% complete)
- `ModularCheatManager` - Debug commands

### Key Architectural Patterns

**1. Interface-Based Decoupling**
```cpp
// Always use ImplementsInterface() + Execute_ pattern, never Cast<>
if (Actor->GetClass()->ImplementsInterface(UInventoryInterface::StaticClass()))
{
    IInventoryInterface::Execute_AddItem(Actor, ItemID, Quantity);
}
```

**2. Delegate-Based Events (UP communication)**
```cpp
// L2 plugins broadcast events, others listen
OnItemAdded.Broadcast(ItemID, Quantity);
```

**3. GameplayTags for State (not enums)**
```cpp
// Tag naming: PluginPrefix.Category.Subcategory
// Exception: Input tags have NO prefix (Input.Action.Primary)
```

### Key Files to Understand

- **Interfaces:** `Plugins/Windwalker_Productions_SharedDefaults/Source/.../Public/Interfaces/`
- **Data Structs:** `Plugins/Windwalker_Productions_SharedDefaults/Source/.../Public/Lib/Data/`
- **Delegates:** `Plugins/Windwalker_Productions_SharedDefaults/Source/.../Public/Delegates/`
- **Master Pawn:** `Plugins/ModularPlayerController/Source/.../Public/Pawns/MPC_Pawn_Master.h`
- **Interaction Subsystem:** `Plugins/ModularInteractionSystem/Source/.../Public/InteractionSubsystem.h`

## Golden Rules (Key Subset)

1. **Performance:** Sub-0.02ms per-component budget. Always async traces.
2. **Modularity:** Delete any L2 plugin → others still compile
3. **No Lateral Dependencies:** L2 plugins communicate only via delegates through L0
4. **Interface Pattern:** Use `ImplementsInterface()` + `Execute_`, never cross-plugin `Cast<>`
5. **Networking:** Always add Server RPCs and replication to new components
6. **Tags:** Cache `FGameplayTag` as `UPROPERTY`, never `RequestGameplayTag()` in hot paths
7. **Mandatory Getters:** Every interface includes `GetXAsActorComponent()` or `GetXAsActor()`

## Include Order Convention

```cpp
#include "OwnHeader.h"
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"  // L0 interfaces
#include "Delegates/ModularInventorySystem/InventoryDelegates.h"   // L0 delegates
#include "Lib/Data/ModularInventorySystem/InventoryData.h"         // L0 data structs
#include "Utilities/Helpers/Item/ItemHelpers.h"                    // L0.5 helpers
#include "Subsystems/EventBusSubsystem.h"                          // L0.5 subsystems
#include "GameFramework/Actor.h"                                   // Engine
#include "OwnHeader.generated.h"                                   // ALWAYS last
```

## Naming Conventions

- **Classes:** `U` = UObject, `A` = AActor, `F` = struct, `I` = interface, `E` = enum
- **Booleans:** `bIsStolen`, `bIsFavorite` (b prefix)
- **Functions:** PascalCase (`AddItem()`)
- **Local Variables:** camelCase (`itemCount`)
- **Folders:** PascalCase (`Lib/Data/Tags/`)

## Existing Documentation

Full architecture documentation exists in these files:
- `WINDWALKER_FRAMEWORK_ARCHITECTURE_V2.13_REVISED.md` - Complete 40 Golden Rules, repository structure, patterns
- `WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md` - Project status, task tracking, completion metrics

**Read these files before implementing new systems** - they contain detailed specifications for interfaces, save system architecture, and design patterns.

## Common Tasks

**Adding a new interactable:**
1. Implement `IInteractableInterface` from SharedDefaults
2. Add `UInteractableComponent` to the actor
3. Define interaction via GameplayTags

**Adding inventory functionality:**
1. Use `IInventoryInterface::Execute_*` functions
2. Listen to `OnItemAdded`/`OnItemRemoved` delegates
3. Never cast to `UInventoryComponent` cross-plugin

**Adding a new mini-game type:**
1. Create handler extending `UMiniGameHandlerBase`
2. Add data struct to `FMiniGameData`
3. Register via DataTable row with GameplayTag

**Adding save support to a component:**
1. Implement `ISaveableInterface`
2. Call `Registry->AnnounceSaveable(this)` in BeginPlay
3. Call `Registry->RevokeSaveable(this)` in EndPlay
4. Provide unique SaveID format: `"Actor.Component.Instance"`

## Git Workflow

**Two-repo architecture:**
- `WWSimulatorFramework` - Plugins only (framework repo)
- `CPPDrugLordTycoonClone` - Game project (excludes Plugins/)

**Session Setup - Run this alias block at start of each Claude Code session:**
```bash
alias goframework='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins"' && alias gogame='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone"' && alias pushframework='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git add . && git commit -m "framework update" && git push origin main' && alias pushgame='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone" && git add . && git commit -m "game update" && git push origin main' && alias pushall='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git add . && git commit -m "framework update" && git push origin main && cd .. && git add . && git commit -m "game update" && git push origin main' && alias pullframework='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git pull origin main' && alias pullgame='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone" && git pull origin main' && alias pullall='cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git pull origin main && cd .. && git pull origin main'
```

**Available commands after setup:**
| Command | Action |
|---------|--------|
| `goframework` | Navigate to Plugins |
| `gogame` | Navigate to game root |
| `pushframework` | Push plugins only |
| `pushgame` | Push game only |
| `pushall` | Push both repos |
| `pullframework` | Pull plugins only |
| `pullgame` | Pull game only |
| `pullall` | Pull both repos |

**Fresh clone (new machine):**
```bash
cd "D:\Unreal Projects (2nd Place)"
git clone https://github.com/x11Windwalker11x/CPPDrugLordTycoonClone.git CPPDrugLordClone
cd CPPDrugLordClone
git clone https://github.com/x11Windwalker11x/WWSimulatorFramework.git Plugins
```

## On Command: Create Command

**Trigger:** `create command: <name>` or `create command: <name> "<description>"`

**Claude executes automatically:**
1. Ask user for description (if not provided) and prompt instructions
2. Create `.claude/commands/<name>.md` with YAML frontmatter
3. Commit to git with message: `Add /<name> custom command`

**File format:**
```markdown
---
description: <user-provided description>
argument-hint: "[optional-args]"
---

<user-provided prompt instructions>
```

| Field | Purpose |
|-------|---------|
| `description` | Shows in `/help` and while typing command |
| `argument-hint` | Shows expected arguments in autocomplete |

**No manual work required.** Command appears in `/help` immediately after creation.

### Windows Shortcut Automation (`BatchFiles/`)
Structure: `SetupX.bat` → `CreateX.ps1` → `LauncherX.bat` → `X.lnk`

**PowerShell Shortcut (CreateX.ps1):**
```powershell
$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
$ProjectRoot = Split-Path -Parent $ScriptDir
$WshShell = New-Object -ComObject WScript.Shell
$Shortcut = $WshShell.CreateShortcut("$ProjectRoot\Name.lnk")
$Shortcut.TargetPath = "$ScriptDir\Launcher.bat"
$Shortcut.WorkingDirectory = $ProjectRoot
$Shortcut.IconLocation = ((Get-Command claude -EA SilentlyContinue).Source + ",0")
$Shortcut.Description = "Description"
$Shortcut.Save()
```

**Batch Dynamic Paths (LauncherX.bat):**
```batch
set "BATCH_DIR=%~dp0"
set "PROJECT_ROOT=%BATCH_DIR%.."
for /d %%i in ("C:\Program Files\App*") do set "APP=%%i\bin\app.exe"
```

**Workflow:**
1. Create files in `BatchFiles/`
2. Run `SetupX.bat` to generate shortcut
3. Add `.claude/commands/<name>.md` if slash command needed
4. Commit all to git

