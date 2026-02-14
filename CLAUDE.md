# CLAUDE.md
> **P1:** Max effectiveness, no info loss. **P2:** Min tokens. See full docs for details.

## Project
**CPPDrugLordTycoonClone** - UE 5.6 C++ | Windwalker Framework V2.13.9

## Build
```bash
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat" CPPDrugLordCloneEditor Win64 Development -Project="D:\Unreal Projects (2nd Place)\CPPDrugLordClone\CPPDrugLordClone.uproject"
```

## Architecture
| Layer | Plugin | Purpose |
|-------|--------|---------|
| L0 | SharedDefaults | Interfaces, delegates, structs, tags |
| L0.5 | MSB | Shared components, subsystems, helpers |
| L2 | MPC, MIS, MIIS, Crafting, Simulator, AWF, Save, Spawn, Cheat, Economy, Quest, WeatherTime | 14 feature plugins |

**Rule:** L2→L2 forbidden. Communicate via L0 delegates. Delete any L2→others compile.

## Patterns
```cpp
// Interface (never Cast<>)
if (Actor->ImplementsInterface(UInterface::StaticClass()))
    IInterface::Execute_Method(Actor, Args);
// Delegate (UP communication) | Tags: Plugin.Category.Sub (Input.* no prefix)
```

## Golden Rules (48) - Key Subset
| # | Rule |
|---|------|
| 1-4 | Perf: <0.02ms, async traces, no iteration, no allocation |
| 5-8 | Modularity: Plugin independence, L0 contracts, DOWN deps/UP delegates |
| 13-14 | Networking: Always RPCs + replication |
| 25-32 | Interfaces: ImplementsInterface+Execute_, mandatory getter, <0.02ms |
| 37-40 | Save: Two-tier delegate, unique SaveID, priority load, dirty tracking |
| 41 | Cache subsystem refs in components |
| 42-45 | Module creation = doc update |
| 46 | HUD widgets MUST use UManagedWidget_Master |
| 47 | Widgets belong in owning plugin's UI/ folder (not MSB/AWF) |
| 48 | Tags in BOTH ini+WW_TagLibrary; never RequestGameplayTag() |

## AWF (Option B - Complete V2.13.6)
UWidgetManagerBase stays MSB permanently. UInventoryWidgetManager in MIS extends base. UManagedWidget_Master now in MSB (L0.5).
- ✅ Widget Location Refactor (Feb 12, 2026): ManagedWidget_Master→MSB, interaction widgets→MIIS, inventory widgets→MIS, 5 L2→L2 violations eliminated
- ✅ Widget System Refactor complete: UWidgetManagerBase (MSB) + UInventoryWidgetManager (MIS) (Feb 6, 2026)
- ✅ IValidWidgetInterface merged into IManagedWidgetInterface (Feb 2, 2026)
- ✅ All 4 deferred features complete (Feb 6, 2026): StateMachine, Pooling, MPSync, Dockable
- AWF is now purely optional: state machine, pooling, MP sync, docking only. No other plugin depends on AWF.

## Naming
`U`=UObject `A`=Actor `F`=struct `I`=interface `E`=enum | `bPrefix` bools | PascalCase funcs | camelCase locals

## Includes
Order: Own→SharedDefaults→MSB→Engine→`.generated.h` LAST

## Module Creation (SharedDefaults)
| Type | Path | # |
|------|------|---|
| Interface | `Public/Interfaces/<Plugin>/<n>Interface.h` | 12 |
| Delegate | `Public/Delegates/<Plugin>/<n>Delegates.h` | 8 |
| Data | `Public/Lib/Data/<Plugin>/<n>Data.h` | 12 |

Steps: Create→Registry→include path→directory tree (Rules #42-45)

## Protocol Files
| File | Purpose |
|------|---------|
| `WW_SESSION_STARTER.md` | Detect leftover, plan session |
| `WW_CLAUDE_CODE_PROMPTS.md` | Copy-paste prompts for Claude Code |
| `WW_END_OF_SESSION.md` | Generate briefing for next session |
| `WW_LEARNING_MODE.md` | Deep C++ explanations |

## Workflow
```
START→Upload docs→Paste SESSION_STARTER→I plan→You approve→I write ADD
IMPLEMENT→Claude Code→/compact at 70%→Output summary
VALIDATE→Paste summary→I verify→Mark complete
BUILD→ONLY when user explicitly requests ("build", "compile", "run build")
END→Paste END_OF_SESSION→I generate briefing
```

## Docs
- `WINDWALKER_FRAMEWORK_ARCHITECTURE_V2_13_REVISED.md` - Full specs
- `WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md` - Tasks, roadmap

## Git
Two repos: `Plugins/`=WWSimulatorFramework | Root=CPPDrugLordTycoonClone
`/git` setup | `/githelp` reference

## Doc Update Cascade
ARCHITECTURE updated → Update PROGRESS_TODO (version, rules, metrics) + CLAUDE.md (version) + WW_CLAUDE_CODE_PROMPTS.md (version)
Milestone completed → Update PROGRESS_TODO Completed Work section
Session end → Update WW_SESSION_STARTER.md (Last Session line) + Create WW_SESSION_BRIEFING_[DATE].md

## Common Mistakes
❌ `Cast<>()` cross-plugin→interface+Execute_
❌ L2→L2 dep→L0 delegate
❌ Logic in structs→helpers
❌ No networking→Always Server RPCs+replication
❌ Wrong include order→`.generated.h` LAST
❌ Widget without base→UManagedWidget_Master
❌ `RequestGameplayTag("Tag")`→FWWTagLibrary::Tag_Name()
❌ Files at `SimulatorFramework/`→`Plugins/SimulatorFramework/`
❌ Plugin code to game repo→verify `git remote -v` before commit
