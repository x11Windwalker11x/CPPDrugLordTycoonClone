# CLAUDE.md
> **Priority #1:** Maximum effectiveness, no loss of information.
> **Priority #2:** Minimal token usage. Reference full docs for details.

## Project
**CPPDrugLordTycoonClone** - UE 5.6 C++ | Windwalker Framework V2.13

## Build
```bash
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat" CPPDrugLordCloneEditor Win64 Development -Project="D:\Unreal Projects (2nd Place)\CPPDrugLordClone\CPPDrugLordClone.uproject"
```

## Architecture
| Layer | Plugin | Purpose |
|-------|--------|---------|
| L0 | SharedDefaults | Interfaces, delegates, structs, tags |
| L0.5 | ModularSystemsBase | Shared components, subsystems, helpers |
| L2 | MPC, MIS, MIIS, Crafting, Simulator, AWF, Save, Spawn, Cheat | Feature plugins (11 total) |

**Rule:** L2 never depends on L2. Communicate via L0 delegates only. Delete any L2 → others compile.

## Core Patterns
```cpp
// Interface (never Cast<>)
if (Actor->ImplementsInterface(UInterface::StaticClass()))
    IInterface::Execute_Method(Actor, Args);

// Delegate (UP communication) | Tags: Plugin.Category.Sub (Input.* has no prefix)
```

## Golden Rules (46 total - see Architecture)
| # | Rule |
|---|------|
| 1-4 | Performance: <0.02ms/component, async traces, no iteration, no allocation |
| 5-8 | Modularity: Plugin independence, L0 contracts, DOWN deps/UP delegates |
| 13-14 | Networking: Always add RPCs + replication |
| 25-32 | Interfaces: ImplementsInterface+Execute_, mandatory getter, <0.02ms |
| 37-40 | Save: Two-tier delegate, unique SaveID, priority load order, dirty tracking |
| 41 | Cache subsystem refs in components |
| 42-45 | Module creation requires doc update |
| 46 | HUD widgets MUST use UManagedWidget_Master |

## Naming
`U`=UObject `A`=Actor `F`=struct `I`=interface `E`=enum | `bPrefix` bools | PascalCase funcs | camelCase locals

## Includes
Order: Own → SharedDefaults → MSB → Engine → `.generated.h` (always LAST)

## Module Creation (SharedDefaults)
| Type | Path | Count |
|------|------|-------|
| Interface | `Public/Interfaces/<Plugin>/<Name>Interface.h` | 18 |
| Delegate | `Public/Delegates/<Plugin>/<Name>Delegates.h` | 8 |
| Data Struct | `Public/Lib/Data/<Plugin>/<Name>Data.h` | 14 |

**Steps:** Create file → Add to Registry → Add include path → Update directory tree (Rules #42-45)

**Interface:** `SHAREDDEFAULTS_API`, mandatory `GetXComponent()`/`GetXActor()`, <0.02ms

**Delegate:** Parameter order `Old, New`, fire AFTER the fact

## Docs
- `WINDWALKER_FRAMEWORK_ARCHITECTURE_V2.13_REVISED.md` - Full specs, rules, patterns
- `WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md` - Status, tasks, roadmap

## Git
Two repos: `Plugins/` = WWSimulatorFramework | Root = CPPDrugLordTycoonClone

`/git` setup aliases | `/githelp` reference

## Commands
**`create command: <name>`** - Auto: Ask prompt → Create `.claude/commands/<name>.md` → Commit

**`create shortcut: <name>`** - Auto: Create `BatchFiles/` scripts → Run setup → Commit
