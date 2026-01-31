# CLAUDE.md
> **Priority #1: Maximum effectiveness, no loss of information.**
> **Priority #2: Minimal token usage.** Reference full docs for details.

## Project
**CPPDrugLordTycoonClone** - UE 5.6 C++ | Windwalker Framework V2.13

## Build
```bash
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat" CPPDrugLordCloneEditor Win64 Development -Project="D:\Unreal Projects (2nd Place)\CPPDrugLordClone\CPPDrugLordClone.uproject"
```

## Architecture
**Layers:** L0 (SharedDefaults: interfaces/delegates/structs) → L0.5 (ModularSystemsBase) → L2 (feature plugins)

**Rule:** L2 plugins never depend on each other. Communicate via L0 delegates only.

**Plugins:** SharedDefaults, ModularSystemsBase, ModularPlayerController, ModularInteractionSystem, ModularInventorySystem, CraftingPlugin, SimulatorFramework, AdvancedWidgetFramework, ModularSaveGameSystem, ModularSpawnSystem, ModularCheatManager

## Patterns
```cpp
// Interface calls (never Cast<>)
if (Actor->GetClass()->ImplementsInterface(UInterface::StaticClass()))
    IInterface::Execute_Method(Actor, Args);

// Delegates (UP communication)
OnEvent.Broadcast(Args);

// Tags: PluginPrefix.Category.Sub (except Input.Action.*)
```

## Rules (46 Golden Rules in Architecture)
1. Sub-0.02ms/component, async traces
2. Delete any L2 → others compile
3. `ImplementsInterface()` + `Execute_`, no cross-plugin `Cast<>`
4. Cache `FGameplayTag` as UPROPERTY
5. Always add Server RPCs + replication
6. Cache subsystem refs in components (Rule #41)
7. Every new module requires doc update (Rules #42-45)

## Naming
`U`=UObject `A`=Actor `F`=struct `I`=interface `E`=enum | `bPrefix` for bools | PascalCase functions | camelCase locals

## UE Conventions
- `.generated.h` always LAST include in header files (UHT auto-generated, never document)
- Include order: Own header → SharedDefaults → MSB → Engine → Generated

## Module Creation Protocol

### Locations (All in SharedDefaults)
| Type | Path |
|------|------|
| Interface | `Public/Interfaces/<PluginName>/<Name>Interface.h` |
| Delegate | `Public/Delegates/<PluginName>/<Name>Delegates.h` |
| Data Struct | `Public/Lib/Data/<PluginName>/<Name>Data.h` |

### Registries (Architecture File)
| Registry | Count | Purpose |
|----------|-------|---------|
| Interface | 18 | Cross-plugin contracts |
| Delegate | 8 | UP communication |
| Data Struct | 14 | Shared data types |

### Creation Steps (Rules #42-45)
1. **Create file** using template from Architecture file
2. **Add to Registry table** in Architecture file
3. **Add include path** to Standard Include Patterns section
4. **Update directory tree** in Repository Structure

### Interface Requirements
- Use `SHAREDDEFAULTS_API` export macro
- Include mandatory getter: `GetXComponent()` or `GetXActor()`
- All functions < 0.02ms (Rule #31)

### Delegate Requirements
- Parameter order: always `Old, New`
- Fire AFTER the fact, not before

### Commit Format
```
Add I<Name> interface for <purpose>

- Create SharedDefaults/Interfaces/<Plugin>/<Name>.h
- Update Architecture: Registry, Include Paths, Directory Tree
```

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
