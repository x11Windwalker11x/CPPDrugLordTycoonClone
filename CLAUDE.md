# CLAUDE.md

## Project
**CPPDrugLordTycoonClone** - UE 5.6 C++ | Windwalker Framework V2.13

## Build
```bash
"C:\Program Files\Epic Games\UE_5.6\Engine\Build\BatchFiles\Build.bat" CPPDrugLordCloneEditor Win64 Development -Project="D:\Unreal Projects (2nd Place)\CPPDrugLordClone\CPPDrugLordClone.uproject"
```

---

# WINDWALKER MODULAR FRAMEWORK V2.13

## Core Principles
- **Performance First:** Sub-0.02ms per-component budget
- **Complete Modularity:** Delete any L2 plugin → others still compile
- **Pawn-Centric:** AMPC_Pawn_Master orchestrates all systems
- **Network Ready:** Server RPCs, validation, replication by default

## Plugin Architecture (11 Plugins)

| Plugin | Layer | Purpose |
|--------|-------|---------|
| Windwalker_Productions_SharedDefaults | L0 | Interfaces, delegates, structs, tags - the ONLY place plugins "know" each other |
| ModularSystemsBase | L0.5 | Shared components, subsystems, helpers |
| ModularPlayerController | L2 | Pawn orchestration, input routing, camera modules |
| ModularInteractionSystem | L2 | Traces, interactables, highlighting, physics grab |
| ModularInventorySystem | L2 | Items, containers, slots, equipment |
| SimulatorFramework | L2 | Devices, mini-games, applications |
| AdvancedWidgetFramework | L2 | Widget management, drag-drop |
| ModularSaveGameSystem | L2 | Save/load state |
| ModularSpawnSystem | L2 | Entity spawning, pooling |
| ModularCheatManager | L2 | Debug/cheat commands |

**Dependency Flow:** L2 depends on L0.5 and L0. Communication flows UP via delegates. NO lateral L2→L2 dependencies ever.

## Golden Rules (#1-40)

### Performance (#1-4)
1. **If it's slow, it's wrong** — Profile everything. Sub-0.02ms per-component budget.
2. **Never use sync traces** — Always async. Game thread impact < 0.03ms.
3. **Never iterate all actors** — Use spatial queries (octree, hash grid).
4. **Never allocate in hot paths** — Use pooling, TArray::Reserve, const references.

### Modularity (#5-8)
5. **Delete any plugin → others still compile** — Complete plugin independence.
6. **SharedDefaults is the ONLY place plugins "know" each other** — All contracts live here.
7. **Dependencies flow DOWN, communication flows UP** — L2→L0.5→L0 deps. UP via delegates.
8. **Each plugin must work standalone** — No required dependencies between L2 plugins.

### Single API & Maintainability (#9-12)
9. **One component = one API** — Single entry point per system.
10. **Properties should be protected** — Use getters/setters for validation and replication.
11. **Centralize, consolidate, unify** — No scattered logic across files.
12. **Data structs have ZERO logic** — Except IsValid(). All logic in Helpers.

### Networking (#13-14)
13. **ALWAYS add networking to new components** — Server RPCs, validation, replication by default.
14. **ALWAYS optimize from day one** — Cache tags as UPROPERTY, minimize tick, profile hot paths.

### Tags & State (#15-18)
15. **Use GameplayTags for state, not enums** — Extensible, hierarchical, data-driven.
16. **Cache tags as UPROPERTY** — Never RequestGameplayTag() in hot paths.
17. **Tag naming: PluginPrefix.System.Detail** — `Inventory.Item.Type.Weapon`
18. **Input tags have NO plugin prefix** — `Input.Numpad.0`, `Input.Action.Primary`

### Naming Conventions (#19-24)
19. **U**=UObject, **A**=AActor, **F**=struct, **I**=interface, **E**=enum, **T**=template, **S**=Slate
20. **Boolean properties: b prefix** — `bIsStolen`, `bIsFavorite`
21. **Functions: PascalCase** — `AddItem()`, `GetSlot()`
22. **Local variables: camelCase** — `itemCount`, `slotIndex`
23. **Private members: No prefix** — `MaxSlots` not `mMaxSlots`
24. **Folders: PascalCase** — `Lib/Data/Tags/`

### Interfaces & Polymorphism (#25-32)
25. **Use ImplementsInterface() + Execute_ pattern** — Never Cast<> for custom interfaces.
26. **Interfaces must be lightweight** — < 0.02ms per call.
27. **Create interface when 2+ conditions met** — Cross-plugin access, multiple implementations, Blueprint override needed, or polymorphic calls required.
28. **Interfaces = public contracts only** — No Server_, Internal_, OnRep_ functions in interfaces.
29. **Every interface has mandatory getter** — `GetXAsActorComponent()`, `GetXAsActor()`, or `GetXAsObject()` for type-safe access without casting.
30. **Strict no-casting across plugins** — Try interface FIRST. Cast only for: (1) profiled optimization, (2) engine class access, (3) same-plugin internal. Never cast cross-plugin.
31. **Interface functions < 0.02ms** — Profile all implementations.
32. **All stateful objects implement ISaveableInterface** — Announce via Registry in BeginPlay, revoke in EndPlay.

### Design Patterns (#33-36)
33. **Use Atomic Composition for complex systems** — Layer 0 atomics (single-purpose, 3-8 fields) → Layer 1 composites → Layer 2 shared → Layer 3 definitions. Keep hierarchy ≤ 3 layers.
34. **Search past chats before implementing** — For ANY new feature, search history first. If pattern exists, follow it.
35. **Research before designing** — For new systems, search 5+ successful games with relevant mechanics. Create comparison table.
36. **Architecture Decision Document (ADD) required** — For every new system, provide ADD first: overview, files to create, dependencies, performance budget, validation criteria. Wait for approval.

### Save System (#37-40)
37. **Two-tier save architecture required** — USaveableRegistrySubsystem (L0.5 foundation) handles registration. USaveGameSubsystem (L2, optional) handles actual save/load. Components announce to Registry in BeginPlay, revoke in EndPlay.
38. **SaveID must be globally unique** — Format: `"Actor.Component.Instance"` for components, `"Class.Name"` for actors. Must be deterministic. Max 256 chars.
39. **Save priority determines load order** — Actors (0-49), Subsystems (50-99), Components (100-149), Managers (150-199), UI (200+). Load: 0→Higher. Save: Higher→0.
40. **Dirty tracking required** — Mark dirty on state change. Only save dirty objects. Clear flag after save.

## Interface System (8 Interfaces)

| Interface | File Location | Mandatory Getter | Purpose |
|-----------|---------------|------------------|---------|
| IInventoryInterface | Interfaces/ModularInventorySystem/InventoryInterface.h | GetInventoryAsActorComponent() | Item management |
| IInteractableInterface | Interfaces/ModularInteractionSystem/InteractableInterface.h | GetInteractableAsActor() | Interaction, pickup |
| ICraftingInterface | Interfaces/ModularInventorySystem/CraftingInterface.h | GetCrafterAsActorComponent() | Crafter capabilities |
| IMiniGameStationInterface | Interfaces/SimulatorFramework/MiniGameStationInterface.h | GetStationAsActor() | Mini-game lifecycle |
| IDurabilityInterface | Interfaces/SimulatorFramework/DurabilityInterface.h | GetDurabilityAsActorComponent() | Durability operations |
| ISaveableInterface | Interfaces/ModularSaveGameSystem/SaveableInterface.h | GetSaveableAsObject() | Save/load state |
| ICameraControlInterface | Interfaces/ModularPlayerController/CameraControlInterface.h | GetCameraControllerAsActor() | Camera modes |
| IPhysicalInteractionInterface | Interfaces/SimulatorFramework/PhysicalInteractionInterface.h | GetPhysicalInteractableAsActor() | Physics grab |

**Create interface when TWO+ conditions met:** Cross-plugin access, multiple implementations, Blueprint override required, polymorphic calls needed.

**Anti-patterns (don't create):** Single implementation only, internal-only calls, pure data access, static helpers.

## Include Path Reference

### SharedDefaults Interfaces
```cpp
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"
#include "Interfaces/ModularInteractionSystem/InteractableInterface.h"
#include "Interfaces/SimulatorFramework/DurabilityInterface.h"
#include "Interfaces/ModularPlayerController/CameraControlInterface.h"
#include "Interfaces/ModularSaveGameSystem/SaveableInterface.h"
```

### SharedDefaults Delegates
```cpp
#include "Delegates/ModularInventorySystem/InventoryDelegates.h"
#include "Delegates/ModularInteractionSystem/InteractionDelegates.h"
#include "Delegates/CraftingDelegates/CraftingDelegates.h"
#include "Delegates/SimulatorFramework/SimulatorDelegates.h"
#include "Delegates/ModularSaveGameSystem/SaveDelegates.h"
```

### SharedDefaults Data Structs
```cpp
#include "Lib/Data/Core/InputConfigData.h"
#include "Lib/Data/Core/ObjectiveData.h"
#include "Lib/Data/ModularInventorySystem/InventoryData.h"
#include "Lib/Data/ModularCraftingData/CraftingData.h"
#include "Lib/Data/SimulatorFramework/MiniGameData.h"
#include "Lib/Data/ModularSaveGameSystem/SaveData.h"
#include "Lib/Data/Enums/WW_Enums.h"
#include "Lib/Data/Tags/WW_TagLibrary.h"
```

### ModularSystemsBase
```cpp
// Helpers
#include "Utilities/Helpers/Item/ItemHelpers.h"
#include "Utilities/Helpers/Crafting/CraftingHelpers.h"
#include "Utilities/Helpers/Tags/TagHelpers.h"
#include "Utilities/Helpers/Spawn/SpawnHelpers.h"

// Subsystems
#include "Subsystems/EventBusSubsystem.h"
#include "Subsystems/ModularQuestSystem/ObjectiveTrackerSubsystem.h"
#include "Subsystems/AdvancedWidgetFramework/WidgetManagerBase.h"

// Components
#include "Components/DurabilityComponent.h"
#include "Components/CrafterComponent.h"
#include "Components/ComponentManager.h"
```

### Include Order
```cpp
// 1. Own header (if .cpp)
#include "InventoryComponent.h"
// 2. SharedDefaults interfaces
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"
// 3. SharedDefaults delegates
#include "Delegates/ModularInventorySystem/InventoryDelegates.h"
// 4. SharedDefaults data structs
#include "Lib/Data/ModularInventorySystem/InventoryData.h"
// 5. ModularSystemsBase helpers
#include "Utilities/Helpers/Item/ItemHelpers.h"
// 6. ModularSystemsBase subsystems
#include "Subsystems/EventBusSubsystem.h"
// 7. Engine includes
#include "GameFramework/Actor.h"
// 8. Generated header (ALWAYS last)
#include "InventoryComponent.generated.h"
```

## Code Patterns

### Interface Call Pattern (Rule #25, #30)
```cpp
// ✅ CORRECT: Interface pattern
if (Comp->GetClass()->ImplementsInterface(UInventoryInterface::StaticClass()))
{
    IInventoryInterface::Execute_AddItem(Comp, ItemID, 1);
}

// ❌ WRONG: Cross-plugin cast
UInventoryComponent* InvComp = Cast<UInventoryComponent>(Comp);  // FORBIDDEN cross-plugin!
```

### Delegate Communication Pattern (Rule #7)
```cpp
// L2 Component broadcasts UP to L0
#include "Delegates/ModularInventorySystem/InventoryDelegates.h"
OnItemAdded.Broadcast(ItemID, Quantity);

// L0.5 Subsystem or other L2 listens
Component->OnItemRemoved.AddDynamic(this, &AMyActor::HandleItemRemoved);
```

### Save System Pattern (Rules #37, #32)
```cpp
// In BeginPlay - announce to registry
void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
    if (UGameInstance* GI = GetWorld()->GetGameInstance())
    {
        if (USaveableRegistrySubsystem* Registry = GI->GetSubsystem<USaveableRegistrySubsystem>())
        {
            Registry->AnnounceSaveable(this);
        }
    }
}

// In EndPlay - revoke from registry
void UInventoryComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    if (UGameInstance* GI = GetWorld()->GetGameInstance())
    {
        if (USaveableRegistrySubsystem* Registry = GI->GetSubsystem<USaveableRegistrySubsystem>())
        {
            Registry->RevokeSaveable(this);
        }
    }
    Super::EndPlay(EndPlayReason);
}
```

### SaveID Format (Rule #38)
```cpp
// Components: "Actor.Component.Instance"
FString::Printf(TEXT("%s.%s.%s"), *GetOwner()->GetName(), *GetClass()->GetName(), *GetFName().ToString());

// Actors: "Class.Name"
FString::Printf(TEXT("%s.%s"), *GetClass()->GetName(), *GetName());

// Subsystems: "ClassName" (singletons)
FString::Printf(TEXT("%s"), *GetClass()->GetName());
```

### Cached Tags Pattern (Rule #16)
```cpp
// ✅ CORRECT: Cached as UPROPERTY
UPROPERTY()
FGameplayTag CachedWeaponTag;

void BeginPlay()
{
    CachedWeaponTag = FGameplayTag::RequestGameplayTag(FName("Inventory.Item.Type.Weapon"));
}

// ❌ WRONG: RequestGameplayTag in hot path
void Tick(float DeltaTime)
{
    if (ItemTag.MatchesTag(FGameplayTag::RequestGameplayTag(FName("Inventory.Item.Type.Weapon"))))  // BAD!
}
```

## Repository Structure

```
Plugins/
├── Windwalker_Productions_SharedDefaults/Source/.../Public/
│   ├── Debug/                          # DebugSubsystem, DebugSettingsDataAsset
│   ├── Delegates/                      # Per-plugin delegate headers
│   │   ├── AdvancedWidgetFramework/WW_WidgetDelegates.h
│   │   ├── ModularInteractionSystem/InteractionDelegates.h
│   │   ├── ModularInventorySystem/InventoryDelegates.h
│   │   ├── ModularSaveGameSystem/SaveDelegates.h
│   │   ├── ModularSpawnSystem/SpawnDelegates.h
│   │   └── SimulatorFramework/SimulatorDelegates.h
│   ├── Interfaces/                     # Per-plugin interface headers
│   │   ├── ModularInteractionSystem/{InteractableInterface, InteractorInterface}.h
│   │   ├── ModularInventorySystem/{InventoryInterface, CraftingInterface, SlottableInterface}.h
│   │   ├── ModularPlayerController/{CameraControlInterface, ModularInputReceiver}.h
│   │   ├── ModularSaveGameSystem/SaveableInterface.h
│   │   └── SimulatorFramework/{DeviceInterface, DurabilityInterface, MiniGameStationInterface, PhysicalInteractionInterface}.h
│   ├── Lib/Data/                       # All data structs
│   │   ├── Core/{InputConfigData, ObjectiveData, WorldObjectData}.h
│   │   ├── Enums/WW_Enums.h
│   │   ├── ModularInteractionSystem/InteractionData.h
│   │   ├── ModularInventorySystem/InventoryData.h
│   │   ├── ModularSaveGameSystem/SaveData.h
│   │   ├── SimulatorFramework/MiniGameData.h
│   │   └── Tags/WW_TagLibrary.h
│   └── Logging/SharedLogging.h
│
├── ModularSystemsBase/Source/.../Public/
│   ├── Components/{ComponentManager, CrafterComponent, DurabilityComponent, DataTableOverwritableComponent}.h
│   ├── Subsystems/
│   │   ├── EventBusSubsystem.h
│   │   ├── DataReloadSubsystem.h
│   │   ├── AdvancedWidgetFramework/WidgetManagerBase.h
│   │   └── ModularQuestSystem/ObjectiveTrackerSubsystem.h
│   └── Utilities/
│       ├── Helpers/{Crafting, Item, Progression, Spawn, Tags}/
│       └── JsonReader/{JsonReaderBase, ItemJsonReader, RecipeJsonReader}.h
│
├── ModularPlayerController/Source/.../Public/
│   ├── Camera/{CameraModule_Master, CameraModule_FPS, CameraModule_TPS, CameraModule_TopDown, CameraModule_TrueFPS, CameraModule_Vehicle}.h
│   ├── Pawns/{MPC_Pawn_Master, MPC_Character_Master, MPC_Vehicle_Master}.h
│   ├── Input/InputSettingsDataAsset.h
│   └── {ModularPlayerController_Master, MPC_GameMode, MPC_PlayerState}.h
│
├── ModularInteractionSystem/Source/.../Public/
│   ├── Components/{InteractableComponent, InteractorComponent, OutlineComponent}.h
│   ├── InteractionSubsystem.h
│   └── SpatialHashGrid.h
│
├── ModularInventorySystem/Source/.../Public/
│   ├── Actors/Interactables/{InteractableActor_Master, PickupActor_Master}.h
│   ├── Components/{InventoryComponent, QuickSlotsComponent, WearableSlotsComponent}.h
│   └── UI/{InventoryGridWidget, InventorySlotWidget, ContextMenuWidget_Master}.h
│
├── SimulatorFramework/Source/.../Public/
│   ├── Actors/{SimulatedDeviceBase, VaultNumpadStation}.h
│   ├── Components/{DeviceStateComponent, MiniGameComponent, PhysicsGrabComponent}.h
│   ├── Subsystems/{ApplicationManager, MiniGameHandlerBase, ManipulationHandler, SequenceHandler, SweetSpotHandler, TimingHandler, TemperatureHandler, CalibrationHandler}.h
│   └── UI/ApplicationBase.h
│
├── AdvancedWidgetFramework/Source/.../Public/
│   ├── MasterWidgets/ManagedWidget_Master.h
│   ├── Subsystems/WidgetManager.h
│   └── Operations/AWF_DragDropOperation.h
│
├── ModularSaveGameSystem/Source/.../Public/
│   ├── {MasterSaveGame, MasterSaveSubsystem}.h
│   └── {InventorySaveModule, CharacterSaveModule, AbilitiesSaveModule, UserSettingsSaveModule}.h
│
├── ModularSpawnSystem/Source/.../Public/
│   └── Subsystems/UniversalSpawnManager.h
│
└── ModularCheatManager/Source/.../Public/
    └── {ModularCheatManager_Master, DeveloperWhiteListAsset}.h
```

## Workflow V2: Architecture Decision Document (ADD)

For every new system/feature, provide ADD first:

```markdown
## [SYSTEM NAME] — ARCHITECTURE LOCK-IN

### Summary
[1-2 sentence description]

### Files to Create
1. FileName.h → Plugin/Path/
2. FileName.cpp → Plugin/Private/Path/

### Dependency Flow
✅ [Valid dependencies DOWN]
✅ [Valid communication UP via delegates]
❌ No L2→L2 lateral dependencies

### Performance Budget
[Component: < X.XXms per operation]

### Validation Criteria
✅ [Delete plugin → others compile]
✅ [Other testable criteria]

### Golden Rules Applied
Rule #X: [Description]

**USER: Approve to proceed or request changes**
```

## Quality Checklist (Before Every Delivery)

1. **Compilation:** All includes present, types declared, signatures match
2. **Framework Compliance:** Golden Rules checked, no L2→L2 deps, networking included
3. **Atomic Contracts:** Every function has contract, edge cases handled
4. **Performance:** Hot paths < 0.02ms, no sync ops, containers optimized, tags cached
5. **Integration:** File locations correct, deletion test passed

---

## Full Docs Reference
Extended specs: `WINDWALKER_FRAMEWORK_ARCHITECTURE_V2.13_REVISED.md`, `WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md`

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
