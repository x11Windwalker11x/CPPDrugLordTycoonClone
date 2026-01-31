# CLAUDE.md
> **Priority #1: Minimal token usage.** Keep responses concise. Reference docs instead of repeating.

## Project
**CPPDrugLordTycoonClone** - UE 5.6 C++ | Windwalker Framework V2.13

## Build
```bash
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat" CPPDrugLordCloneEditor Win64 Development -Project="D:\Unreal Projects (2nd Place)\CPPDrugLordClone\CPPDrugLordClone.uproject"
```

## Architecture
**Layers:** L0 (SharedDefaults: interfaces/delegates/structs) → L0.5 (ModularSystemsBase) → L2 (feature plugins)

**Rule:** L2 plugins never depend on each other. Communicate via L0 delegates only.

**Plugins:** SharedDefaults, ModularSystemsBase, ModularPlayerController, ModularInteractionSystem, ModularInventorySystem, SimulatorFramework, AdvancedWidgetFramework, ModularSaveGameSystem, ModularSpawnSystem, ModularCheatManager

## Patterns
```cpp
// Interface calls (never Cast<>)
if (Actor->GetClass()->ImplementsInterface(UInterface::StaticClass()))
    IInterface::Execute_Method(Actor, Args);

// Delegates (UP communication)
OnEvent.Broadcast(Args);

// Tags: PluginPrefix.Category.Sub (except Input.Action.*)
```

## Rules
1. Sub-0.02ms/component, async traces
2. Delete any L2 → others compile
3. `ImplementsInterface()` + `Execute_`, no cross-plugin `Cast<>`
4. Cache `FGameplayTag` as UPROPERTY
5. Always add Server RPCs + replication

## Naming
`U`=UObject `A`=Actor `F`=struct `I`=interface `E`=enum | `bPrefix` for bools | PascalCase functions | camelCase locals

## Docs
Full specs: `WINDWALKER_FRAMEWORK_ARCHITECTURE_V2.13_REVISED.md`, `WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md`

## Git
Two repos: `Plugins/` = WWSimulatorFramework | Root = CPPDrugLordTycoonClone

Use `/git` to setup aliases, `/githelp` for reference.

## On Command: Create Command
**Trigger:** `create command: <name>` or `create command: <name> "<description>"`

Auto-execute: Ask description/prompt → Create `.claude/commands/<name>.md` → Commit

```markdown
---
description: Shows in /help and autocomplete
argument-hint: "[args]"
---
Prompt here
```

## On Command: Create Shortcut
**Trigger:** `create shortcut: <name>`

Auto-execute: Create `BatchFiles/` scripts with dynamic paths → Run setup → Commit

Pattern: `SetupX.bat` → `CreateX.ps1` → `LauncherX.bat` → `X.lnk`
