# WINDWALKER MODULAR FRAMEWORK ARCHITECTURE V2.13 (REVISED)

**Comprehensive Framework Documentation**  
**Date:** February 2, 2026  
**Status:** Production Ready  
**Revision:** V2.13.2 - Git Repository Rules, Two-repo architecture

---

## 📚 TABLE OF CONTENTS

1. [Framework Overview](#framework-overview)
2. [Complete Repository Structure](#complete-repository-structure)
3. [Include Path Reference](#include-path-reference)
4. [Golden Rules (Complete #1-48)](#golden-rules)
5. [GameplayTag Governance](#gameplay-tag-governance)
6. [Plugin Architecture](#plugin-architecture)
6. [Interface System](#interface-system)
7. [Save System Architecture](#save-system-architecture)
8. [Workflow Systems](#workflow-systems)
9. [Design Patterns](#design-patterns)
10. [Learning System](#learning-system)
11. [Quality Assurance](#quality-assurance)
12. [Git Repository Rules](#git-repository-rules)

---

## 🎯 FRAMEWORK OVERVIEW

**Windwalker Modular Framework** is a comprehensive UE5.5+ C++ plugin ecosystem designed for AAA-level performance and marketplace distribution.

### Core Principles

- **Performance First:** Sub-0.02ms per-component budget
- **Complete Modularity:** Delete any plugin → others still compile
- **Pawn-Centric:** AMPC_Pawn_Master orchestrates all systems
- **Network Ready:** Server RPCs, validation, replication by default
- **Marketplace Ready:** Professional quality, fully documented

### Plugin Count: 11 Plugins

| Plugin | Layer | Purpose |
|--------|-------|---------|
| Windwalker_Productions_SharedDefaults | L0 | Interfaces, delegates, structs, tags |
| ModularSystemsBase | L0.5 | Shared components, subsystems, helpers |
| ModularPlayerController | L2 | Pawn orchestration, input routing |
| ModularInteractionSystem | L2 | Traces, interactables, highlighting |
| ModularInventorySystem | L2 | Items, containers, slots |
| CraftingPlugin | L2 | Recipes, stations, queue |
| SimulatorFramework | L2 | Devices, mini-games, applications |
| AdvancedWidgetFramework | L2 | Widget management, drag-drop |
| ModularSaveGameSystem | L2 | Save/load state |
| ModularSpawnSystem | L2 | Entity spawning |
| ModularCheatManager | L2 | Debug/cheat commands |

---

## 📁 COMPLETE REPOSITORY STRUCTURE

**Base Path:** `D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins\`

### Windwalker_Productions_SharedDefaults (L0)

```
Windwalker_Productions_SharedDefaults/
├── Source/Windwalker_Productions_SharedDefaults/Public/
│   ├── Debug/
│   │   ├── DebugDefaultsConstants.h
│   │   ├── DebugSettingsDataAsset.h
│   │   └── DebugSubsystem.h
│   ├── Delegates/
│   │   ├── AdvancedWidgetFramework/
│   │   │   └── WW_WidgetDelegates.h
│   │   ├── CraftingDelegates/
│   │   │   └── CraftingDelegates.h
│   │   ├── ModularInteractionSystem/
│   │   │   └── InteractionDelegates.h
│   │   ├── ModularInventorySystem/
│   │   │   └── InventoryDelegates.h
│   │   ├── ModularQuestSystem/
│   │   │   └── GameplayEventDelegates.h
│   │   ├── ModularSaveGameSystem/
│   │   │   └── SaveDelegates.h
│   │   ├── ModularSpawnSystem/
│   │   │   └── SpawnDelegates.h
│   │   └── SimulatorFramework/
│   │       └── SimulatorDelegates.h
│   ├── Interfaces/
│   │   ├── AdvancedWidgetFramework/
│   │   │   └── ManagedWidgetInterface.h
│   │   ├── ModularInteractionSystem/
│   │   │   ├── InteractableInterface.h
│   │   │   └── InteractorInterface.h
│   │   ├── ModularInventorySystem/
│   │   │   ├── CraftingInterface.h
│   │   │   ├── InventoryInterface.h
│   │   │   ├── ItemSpawnerInterface.h
│   │   │   └── SlottableInteface.h
│   │   ├── ModularPlayerController/
│   │   │   ├── CameraControlInterface.h
│   │   │   └── ModularInputReceiver.h
│   │   ├── ModularQuestSystem/
│   │   │   └── GameplayEventHandlerInteface.h
│   │   ├── ModularSaveGameSystem/
│   │   │   └── SaveableInterface.h
│   │   ├── ModularSpawnSystem/
│   │   │   └── SaveableInteface.h
│   │   └── SimulatorFramework/
│   │       ├── DegradableInterface.h
│   │       ├── DeviceInterface.h
│   │       ├── DurabilityInterface.h
│   │       ├── MiniGameStationInterface.h
│   │       └── PhysicalInteractionInterface.h
│   ├── Lib/
│   │   ├── Data/
│   │   │   ├── Core/
│   │   │   │   ├── InputConfigData.h
│   │   │   │   ├── ObjectiveData.h
│   │   │   │   └── WorldObjectData.h
│   │   │   ├── Enums/
│   │   │   │   └── WW_Enums.h
│   │   │   ├── ModularCraftingData/
│   │   │   │   └── CraftingData.h
│   │   │   ├── ModularInteractionSystem/
│   │   │   │   ├── InteractionData.h
│   │   │   │   ├── InteractionDefaultsConstants.h
│   │   │   │   └── InteractionPredictionState.h
│   │   │   ├── ModularInventorySystem/
│   │   │   │   └── InventoryData.h
│   │   │   ├── ModularQuestSystem/
│   │   │   │   ├── CameraEvents.h
│   │   │   │   └── GameplayEventData.h
│   │   │   ├── ModularSaveGameSystem/
│   │   │   │   └── SaveData.h
│   │   │   ├── ModularSpawnSystem/
│   │   │   │   └── SpawnData.h
│   │   │   ├── SimulatorFramework/
│   │   │   │   └── MiniGameData.h
│   │   │   └── Tags/
│   │   │       └── WW_TagLibrary.h
│   ├── Logging/
│   │   ├── InteractableInventoryLogging.h
│   │   └── SharedLogging.h
│   └── Windwalker_Productions_SharedDefaults.h
└── Intermediate/Build/Win64/UnrealEditor/Inc/Windwalker_Productions_SharedDefaults/UHT/
    ├── DebugSettingsDataAsset.generated.h
    ├── DebugSubsystem.generated.h
    ├── InteractableInterface.generated.h
    ├── InteractionPredictionState.generated.h
    ├── InteractorInterface.generated.h
    ├── Windwalker_Productions_SharedDefaultsClasses.h
    └── WW_Enums.generated.h
```

### ModularSystemsBase (L0.5)

```
ModularSystemsBase/
├── Source/ModularSystemsBase/Public/
│   ├── Components/
│   │   ├── ComponentManager.h
│   │   ├── CrafterComponent.h
│   │   ├── CrafterComponent_Master.h
│   │   ├── DataTableOverwritableComponent.h
│   │   └── DurabilityComponent.h
│   ├── Operations/
│   │   └── WidgetDragDropOperation.h
│   ├── Subsystems/
│   │   ├── AdvancedWidgetFramework/
│   │   │   └── WidgetManagerBase.h
│   │   ├── ModularLevelingSkillSystem/
│   │   │   └── RegionSubsystem.h
│   │   ├── ModularQuestSystem/
│   │   │   └── ObjectiveTrackerSubsystem.h
│   │   ├── DataReloadSubsystem.h
│   │   └── EventBusSubsystem.h
│   ├── Utilities/
│   │   ├── Helpers/
│   │   │   ├── Crafting/
│   │   │   │   └── CraftingHelpers.h
│   │   │   ├── Item/
│   │   │   │   └── ItemHelpers.h
│   │   │   ├── Progression/
│   │   │   │   └── ProgressionHelpers.h
│   │   │   ├── Spawn/
│   │   │   │   └── SpawnHelpers.h
│   │   │   ├── Tags/
│   │   │   │   ├── TagHelpers.h
│   │   │   │   └── WWSharedFunctionLibrary.h
│   │   │   └── MSB_BlueprintFunctionLibrary_Base.h
│   │   └── JsonReader/
│   │       ├── CrafterJsonReader.h
│   │       ├── InteractableJsonReader.h
│   │       ├── ItemJsonReader.h
│   │       ├── JsonReaderBase.h
│   │       └── RecipeJsonReader.h
│   └── ModularSystemsBase.h
└── Intermediate/Build/Win64/x64/UnrealEditor/Development/ModularSystemsBase/
    └── Definitions.ModularSystemsBase.h
```

### ModularPlayerController (L2)

```
ModularPlayerController/
├── Source/ModularPlayerController/Public/
│   ├── Camera/
│   │   ├── Config/
│   │   │   ├── CameraConfigStructs.h
│   │   │   └── CameraShakeConfigStructs.h
│   │   ├── Manager/
│   │   │   └── MPC_PlayerCameraManager.h
│   │   ├── Shake/
│   │   │   ├── CameraShakeModule_Combat.h
│   │   │   └── CameraShakeModule_Master.h
│   │   ├── CameraModule_Custom.h
│   │   ├── CameraModule_FPS.h
│   │   ├── CameraModule_Master.h
│   │   ├── CameraModule_TopDown.h
│   │   ├── CameraModule_TPS.h
│   │   ├── CameraModule_TrueFPS.h
│   │   └── CameraModule_Vehicle.h
│   ├── Components/
│   │   └── PawnComponentManager.h
│   ├── Input/
│   │   └── InputSettingsDataAsset.h
│   ├── Pawns/
│   │   ├── Components/
│   │   │   └── InputActionMechanicComponent.h
│   │   ├── Vehicles/
│   │   │   └── MPC_Vehicle_Master.h
│   │   ├── MPC_Character_Master.h
│   │   └── MPC_Pawn_Master.h
│   ├── ModularAIController_Master.h
│   ├── ModularPlayerController.h
│   ├── ModularPlayerController_Master.h
│   ├── MPC_GameMode.h
│   ├── MPC_PlayerState.h
│   └── PersistentPlayerData.h
└── Intermediate/Build/Win64/UnrealEditor/Inc/ModularPlayerController/UHT/
    ├── InputActionMechanicComponent.generated.h
    ├── InputSettingsDataAsset.generated.h
    ├── ModularAIController_Master.generated.h
    ├── ModularInputReceiver.generated.h
    ├── ModularPlayerControllerClasses.h
    ├── ModularPlayerController_Master.generated.h
    ├── MPC_Character_Master.generated.h
    ├── MPC_GameMode.generated.h
    ├── MPC_Pawn_Master.generated.h
    ├── MPC_PlayerCameraManager.generated.h
    ├── MPC_PlayerState.generated.h
    ├── MPC_Vehicle_Master.generated.h
    └── PersistentPlayerData.generated.h
```

### ModularInteractionSystem (L2)

```
ModularInteractionSystem/
├── Source/ModularInteractionSystem/Public/
│   ├── Components/
│   │   ├── AI/
│   │   │   └── AIInteractorComponnet.h
│   │   ├── InteractableComponent.h
│   │   ├── InteractorComponent.h
│   │   └── OutlineComponent.h
│   ├── UI/
│   │   ├── Widget_InteractionPrompt.h
│   │   └── Widget_PreInteraction.h
│   ├── InteractablePriorityStruct.h
│   ├── InteractionSubsystem.h
│   ├── ModularInteractionSystem.h
│   └── SpatialHashGrid.h
├── Source/ModularInteractionSystem/Private/
│   └── UI/
│       ├── Widget_InteractionPrompt.cpp
│       └── Widget_PreInteraction.cpp
└── Intermediate/Build/Win64/UnrealEditor/Inc/ModularInteractionSystem/UHT/
    ├── AIInteractorComponnet.generated.h
    ├── InteractableComponent.generated.h
    ├── InteractablePriorityStruct.generated.h
    ├── InteractionSubsystem.generated.h
    ├── InteractorComponent.generated.h
    └── ModularInteractionSystemClasses.h
```

### ModularInventorySystem (L2)

```
ModularInventorySystem/
├── Source/ModularInventorySystem/Public/
│   ├── Actors/
│   │   └── Interactables/
│   │       ├── Item/
│   │       │   └── Pickup/
│   │       │       └── PickupActor_Master.h
│   │       └── InteractableActor_Master.h
│   ├── Components/
│   │   ├── InventoryComponent.h
│   │   ├── QuickSlotsComponent.h
│   │   └── WearableSlotsComponent.h
│   ├── Data/
│   │   └── InventoryPrediction.h
│   ├── UI/
│   │   ├── HelperUI/
│   │   │   ├── ContextMenu/
│   │   │   │   ├── ContextMenuWidget_Master.h
│   │   │   │   ├── DropQuantityWidget.h
│   │   │   │   ├── MIIS_RightClickContextMenu.h
│   │   │   │   └── SplitQuantitiyWidget.h
│   │   │   ├── InventorySearchSortWidget.h
│   │   │   ├── SearchSortWidget_Master.h
│   │   │   └── WW_SearchResultEntryWidget.h
│   │   ├── Operations/
│   │   │   └── InventorySlotDragDropOperation.h
│   │   ├── BoxSelectionWidget.h
│   │   ├── InventoryGridWidget.h
│   │   ├── InventoryResizableWindowWidget.h
│   │   ├── InventorySlotWidget.h
│   │   └── RootWidget.h
│   ├── Private/
│   │   └── UI/
│   │       └── BoxSelectionWidget.cpp
│   ├── ModularInventoryInteractableSystem.h
│   └── PickUpActor.h
└── Intermediate/Build/Win64/UnrealEditor/Inc/ModularInventoryInteractableSystem/UHT/
    ├── ContextMenuWidget_Master.generated.h
    ├── DropQuantityWidget.generated.h
    ├── InteractableActor_Master.generated.h
    ├── InteractableLoadSubsystem.generated.h
    ├── InventoryComponent.generated.h
    ├── InventoryGridWidget.generated.h
    ├── InventoryInterface.generated.h
    ├── InventoryResizableWindowWidget.generated.h
    ├── InventorySearchSortWidget.generated.h
    ├── InventorySlot.generated.h
    ├── InventorySlotWidget.generated.h
    ├── ItemData.generated.h
    ├── ItemData_Dynamic.generated.h
    ├── JsonItemLoader.generated.h
    ├── MIIS_RightClickContextMenu.generated.h
    ├── ModularInventoryInteractableSystemClasses.h
    ├── PickUpActor.generated.h
    ├── PickupActor_Master.generated.h
    ├── RootWidget.generated.h
    ├── SearchSortWidget_Master.generated.h
    ├── SplitQuantitiyWidget.generated.h
    └── WW_SearchResultEntryWidget.generated.h
```

### SimulatorFramework (L2)

```
SimulatorFramework/
├── Source/SimulatorFramework/Public/
│   ├── Actors/
│   │   ├── SimulatedDeviceBase.h
│   │   └── VaultNumpadStation.h
│   ├── Components/
│   │   ├── DeviceStateComponent.h
│   │   ├── MiniGameComponent.h
│   │   └── PhysicsGrabComponent.h
│   ├── Subsystems/
│   │   ├── ApplicationManager.h
│   │   ├── CalibrationHandler.h
│   │   ├── ManipulationHandler.h
│   │   ├── MiniGameHandlerBase.h
│   │   ├── SequenceHandler.h
│   │   ├── SweetSpotHandler.h
│   │   ├── TemperatureHandler.h
│   │   └── TimingHandler.h
│   ├── UI/
│   │   └── ApplicationBase.h
│   └── SimulatorFramework.h
└── Intermediate/Build/Win64/x64/UnrealEditor/Development/SimulatorFramework/
    └── Definitions.SimulatorFramework.h
```

### AdvancedWidgetFramework (L2)

```
AdvancedWidgetFramework/
├── Source/AdvancedWidgetFramework/Public/
│   ├── MasterWidgets/
│   │   └── ManagedWidget_Master.h
│   ├── Subsystems/
│   │   └── WidgetManager.h
│   └── AdvancedWidgetFramework.h
└── Intermediate/Build/Win64/UnrealEditor/Inc/AdvancedWidgetFramework/UHT/
    ├── ManagedWidget_Master.generated.h
    └── WidgetManager.generated.h
```

### ModularSaveGameSystem (L2)

```
ModularSaveGameSystem/
├── Source/ModularSaveGameSystem/Public/
│   ├── AbilitiesSaveModule.h
│   ├── CharacterSaveModule.h
│   ├── InventorySaveModule.h
│   ├── MasterSaveGame.h
│   ├── MasterSaveSubsystem.h
│   ├── ModularSaveGameSystem.h
│   └── UserSettingsSaveModule.h
└── Intermediate/Build/Win64/UnrealEditor/Inc/ModularSaveGameSystem/UHT/
    ├── AbilitiesSaveModule.generated.h
    ├── CharacterSaveModule.generated.h
    ├── InventorySaveModule.generated.h
    ├── MasterSaveGame.generated.h
    ├── MasterSaveSubsystem.generated.h
    └── ModularSaveGameSystemClasses.h
```

### ModularSpawnSystem (L2)

```
ModularSpawnSystem/
├── Source/ModularSpawnSystem/Public/
│   ├── Subsystems/
│   │   └── UniversalSpawnManager.h
│   └── ModularSpawnSystem.h
└── Intermediate/Build/Win64/UnrealEditor/Inc/ModularSpawnSystem/UHT/
    ├── ModularSpawnSystemClasses.h
    └── UniversalSpawnManager.generated.h
```

### ModularCheatManager (L2)

```
ModularCheatManager/
├── Source/ModularCheatManager/Public/
│   ├── DeveloperWhiteListAsset.h
│   ├── ECheatPermissionLevel.h
│   ├── ModularCheatManager.h
│   └── ModularCheatManager_Master.h
└── Intermediate/Build/Win64/UnrealEditor/Inc/ModularCheatManager/UHT/
    ├── DeveloperWhiteListAsset.generated.h
    ├── ECheatPermissionLevel.generated.h
    ├── ModularCheatManager.generated.h
    ├── ModularCheatManagerClasses.h
    └── ModularCheatManager_Master.generated.h
```

---

## 📋 INCLUDE PATH REFERENCE

### Standard Include Patterns

**1. SharedDefaults Interfaces:**
```cpp
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"
#include "Interfaces/ModularInteractionSystem/InteractableInterface.h"
#include "Interfaces/SimulatorFramework/DurabilityInterface.h"
#include "Interfaces/ModularPlayerController/CameraControlInterface.h"
#include "Interfaces/ModularSaveGameSystem/SaveableInterface.h"
```

**2. SharedDefaults Delegates:**
```cpp
#include "Delegates/ModularInventorySystem/InventoryDelegates.h"
#include "Delegates/ModularInteractionSystem/InteractionDelegates.h"
#include "Delegates/CraftingDelegates/CraftingDelegates.h"
#include "Delegates/SimulatorFramework/SimulatorDelegates.h"
#include "Delegates/ModularSaveGameSystem/SaveDelegates.h"
```

**3. SharedDefaults Data Structs:**
```cpp
#include "Lib/Data/Core/InputConfigData.h"
#include "Lib/Data/Core/ObjectiveData.h"
#include "Lib/Data/ModularInventorySystem/InventoryData.h"
#include "Lib/Data/ModularCraftingData/CraftingData.h"
#include "Lib/Data/SimulatorFramework/MiniGameData.h"
#include "Lib/Data/ModularSaveGameSystem/SaveData.h"
```

**4. SharedDefaults Enums & Tags:**
```cpp
#include "Lib/Data/Enums/WW_Enums.h"
#include "Lib/Data/Tags/WW_TagLibrary.h"
```

**5. ModularSystemsBase Helpers:**
```cpp
#include "Utilities/Helpers/Item/ItemHelpers.h"
#include "Utilities/Helpers/Crafting/CraftingHelpers.h"
#include "Utilities/Helpers/Progression/ProgressionHelpers.h"
#include "Utilities/Helpers/Tags/TagHelpers.h"
#include "Utilities/Helpers/Spawn/SpawnHelpers.h"
```

**6. ModularSystemsBase Subsystems:**
```cpp
#include "Subsystems/EventBusSubsystem.h"
#include "Subsystems/ModularQuestSystem/ObjectiveTrackerSubsystem.h"
#include "Subsystems/AdvancedWidgetFramework/WidgetManagerBase.h"
```

**7. ModularSystemsBase Components:**
```cpp
#include "Components/DurabilityComponent.h"
#include "Components/CrafterComponent.h"
#include "Components/ComponentManager.h"
```

### Include Order (Standard)

```cpp
// 1. Own header (if .cpp file)
#include "InventoryComponent.h"

// 2. SharedDefaults interfaces
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"
#include "Interfaces/ModularInventorySystem/CraftingInterface.h"

// 3. SharedDefaults delegates
#include "Delegates/ModularInventorySystem/InventoryDelegates.h"

// 4. SharedDefaults data structs
#include "Lib/Data/ModularInventorySystem/InventoryData.h"
#include "Lib/Data/Tags/WW_TagLibrary.h"

// 5. ModularSystemsBase helpers
#include "Utilities/Helpers/Item/ItemHelpers.h"

// 6. ModularSystemsBase subsystems
#include "Subsystems/EventBusSubsystem.h"

// 7. Engine includes
#include "GameFramework/Actor.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"

// 8. Generated header (ALWAYS last)
#include "InventoryComponent.generated.h"
```

---

## ⚡ GOLDEN RULES (Complete #1-48)

### Priority 1: Performance

**1. If it's slow, it's wrong** — Profile everything. Sub-0.02ms per-component budget.

**2. Never use sync traces** — Always async. Game thread impact < 0.03ms.

**3. Never iterate all actors** — Use spatial queries (octree, hash grid).

**4. Never allocate in hot paths** — Use pooling, TArray::Reserve, const references.

---

### Priority 2: Modularity

**5. Delete any plugin → others still compile** — Complete plugin independence.

**6. SharedDefaults is the ONLY place plugins "know" each other** — All contracts (interfaces, delegates, structs) live here.

**7. Dependencies flow DOWN, communication flows UP** — L2 plugins depend on L0.5 foundation. Communication flows UP via delegates (SaveableRegistry pattern). No lateral L2 → L2 dependencies.

**8. Each plugin must work standalone** — No required dependencies between L2 plugins.

---

### Priority 3: Single API & Maintainability

**9. One component = one API** — Single entry point per system. No hunting.

**10. Properties should be protected** — Use getters/setters for validation and replication control.

**11. Centralize, consolidate, unify** — No scattered logic across files.

**12. Data structs have ZERO logic** — Except IsValid(). All logic in Helpers.

---

### Networking

**13. ALWAYS add networking to new components** — Server RPCs, validation, replication included by default.

**14. ALWAYS optimize from day one** — Cache tags as UPROPERTY, minimize tick, profile hot paths.

---

### Tags & State

**15. Use GameplayTags for state, not enums** — Extensible, hierarchical, data-driven.

**16. Cache tags as UPROPERTY** — Never RequestGameplayTag() in hot paths.

**17. Tag naming: PluginPrefix.System.Detail** — `Inventory.Item.Type.Weapon`

**18. Input tags have NO plugin prefix** — `Input.Numpad.0`, `Input.Action.Primary` (shared across all plugins)

---

### Naming Conventions

**19. Follow UE5 C++ naming** — U=UObject, A=AActor, F=struct, I=interface, E=enum, T=template, S=Slate

**20. Boolean properties: b prefix** — `bIsStolen`, `bIsFavorite`

**21. Functions: PascalCase** — `AddItem()`, `GetSlot()`

**22. Local variables: camelCase** — `itemCount`, `slotIndex`

**23. Private members: No prefix** — `MaxSlots` not `mMaxSlots`

**24. Folders: PascalCase** — `Lib/Data/Tags/`

---

### Interfaces & Polymorphism

**25. Use ImplementsInterface() + Execute_ pattern** — Never Cast<> for custom interfaces.

**26. Interfaces must be lightweight** — < 0.02ms per call. Profile all implementations.

**27. Create interface when 2+ conditions met** — Cross-plugin access, multiple implementations, Blueprint override needed, or polymorphic calls required.

**28. Interfaces = public contracts only** — No Server_, Internal_, OnRep_ functions in interfaces.

**29. Every interface has mandatory getter** — `GetXAsActorComponent()`, `GetXAsActor()`, or `GetXAsObject()` for type-safe access without casting.

**30. Strict no-casting across plugins** — Try interface FIRST. Cast only for: (1) optimization (profiled), (2) engine class access, (3) same-plugin internal. Never cast cross-plugin.

**31. Interface functions < 0.02ms** — Profile all interface implementations. No heavy operations.

**32. All stateful objects implement ISaveableInterface** — Components, actors, subsystems with persistent state. Announce via USaveableRegistrySubsystem (L0.5) in BeginPlay. Revoke in EndPlay.

---

### Design Patterns

**33. Use Atomic Composition for complex systems** — Build from Layer 0 atomics (single-purpose, 3-8 fields) → Layer 1 composites (feature configs) → Layer 2 shared systems (cross-plugin primitives) → Layer 3 definitions (DataTable rows). Keep hierarchy ≤ 3 layers. No logic in structs (only IsValid()).

**34. Search past chats before implementing** — For ANY new feature, search conversation history first. If pattern exists, follow it. If not found, ask user. Extract successful patterns and document them. Never assume implementation approach without validation.

**35. Research before designing** — For new systems, search 5+ successful games with relevant mechanics. Create comparison table: Input | Feedback | Completion | Failure | Scaling. Extract atomic patterns. Document why designs work. Never invent mechanics without validation from shipped games.

**36. Architecture Decision Document (ADD) required** — For every new system/feature, provide ADD first showing: system overview, files to create with locations, dependencies (UP/DOWN flow), performance budget, validation criteria. Wait for user approval/revision. All high-level decisions made upfront before implementation begins. Prevents decision fatigue and ensures alignment.

---

### Save System Implementation

**37. Two-tier save architecture required** — USaveableRegistrySubsystem (L0.5 foundation) handles registration. USaveGameSubsystem (L2 feature, optional) handles actual save/load. Components announce to Registry in BeginPlay, revoke in EndPlay. No direct L2→L2 calls.

**38. SaveID must be globally unique** — Format: `"Actor.Component.Instance"` for components, `"Class.Name"` for actors. Use GetOwner()->GetName(), GetClass()->GetName(), GetFName(). Must be deterministic (same object = same ID). Max 256 characters.

**39. Save priority determines load order** — Actors (0-49) load first, Subsystems (50-99) second, Components (100-149) third, Managers (150-199) fourth, UI (200+) last. Load order: Priority 0 → Higher. Save order: Higher → 0 (cleanup before dependencies).

**40. Dirty tracking required for performance** — Mark object dirty when state changes. Only save dirty objects. Clear dirty flag after successful save. IsDirty() must return accurate state. Prevents unnecessary serialization of unchanged objects.

---

### Widget & UI System

**41. Cache subsystem refs in components** — Store frequently used subsystem pointers in BeginPlay. Never call Get*Subsystem() in hot paths.

**42-45. Module creation requires doc update** — New interface: update Interface Registry. New delegate: update Delegate Registry. New struct: update Data Registry. New module: update directory tree.

**46. HUD widgets MUST use UManagedWidget_Master** — All managed HUD widgets inherit from UManagedWidget_Master. No exceptions.

**47. Widgets belong in owning plugin's UI/ folder** — Each plugin owns its widgets. Interaction widgets → MIS/UI/, inventory widgets → MIIS/UI/, simulator widgets → SimulatorFramework/UI/. NOT in MSB or AWF. AWF only contains UManagedWidget_Master base class.

---

### GameplayTag Centralization

**48. All GameplayTags MUST be registered in BOTH locations** — Every tag requires dual registration: (1) `Config/DefaultGameplayTags.ini` for engine registration/editor discovery, (2) `WW_TagLibrary.h/.cpp` for type-safe code access. NEVER use `FGameplayTag::RequestGameplayTag()` directly in code. Always use `FWWTagLibrary::Tag_Name()` accessor. 5-step protocol: register in ini → define in WW_Internal namespace → declare accessor in .h → implement accessor in .cpp → use via FWWTagLibrary.

---

### AWF Architecture (Option B Decision)

**AWF Delegate Registration Pattern:**
- UWidgetManagerBase stays in MSB permanently (shared infrastructure)
- AWF's 4 features register INTO WidgetManagerBase via delegates at runtime
- Same two-tier pattern as Save System (Rule #37)
- Delete AWF → graceful degradation to basic show/hide
- No compile-time L2→L2 coupling

**AWF Deferred Feature 1: Widget Pooling System (P3)**
High-frequency widget spawn/destroy (damage numbers, floating markers, notifications, kill feed). Pre-instantiation, recycle pool, spatial sorting, priority eviction.
- ⬜ UWidgetPoolManager subsystem
- ⬜ Pool configuration via DataTable (pool size, recycle timeout, eviction priority)
- ⬜ Spatial widget sorting (screen-space clustering for overlapping popups)
- ⬜ Priority eviction (oldest/lowest-priority recycled first when pool full)
- ⬜ Integration hooks for: combat UI, quest UI, economy notifications, MiniGame feedback

**AWF Deferred Feature 2: Dockable/Composable Layout Engine (P4)**
Widgets arranged into panels, split views, tabbed containers. Player-rearrangeable dock zones.
- ⬜ UDockZone actor/component (placeable dock targets)
- ⬜ UDockableWidget base class (widgets that can be docked/undocked)
- ⬜ Split-view and tabbed container widgets
- ⬜ Layout persistence (save/load dock arrangement)
- ⬜ Conflict resolution (two widgets targeting same dock zone)

**AWF Deferred Feature 3: Widget State Machine Manager (P3)**
Non-trivial widget transitions: `Closed → AnimatingIn → Visible → Paused → AnimatingOut → Closed`. Interrupt handling when multiple widgets conflict. Priority-based conflict resolution. Registers into WidgetManagerBase via delegates.
- ⬜ FWidgetStateMachine struct (states, transitions, interrupts)
- ⬜ UWidgetStateManager subsystem (runs state machines, resolves conflicts)
- ⬜ UWidgetAnimation integration (transition animation per state change)
- ⬜ Interrupt rules (configurable per widget: cancel, queue, or pause)
- ⬜ Register state machine flow into WidgetManagerBase via delegate (OnShowRequested, OnHideRequested intercepted)

**AWF Deferred Feature 4: Multiplayer Widget Synchronization (P3)**
Shared UI state that replicates — spectator mirroring, co-op crafting stations, auction houses. Generic widget replication infrastructure any plugin opts into. Registers into WidgetManagerBase via delegates.
- ⬜ IReplicatedWidgetInterface (extends IManagedWidgetInterface)
- ⬜ UWidgetSyncSubsystem (replicates widget state deltas, not full state)
- ⬜ Server-authoritative widget ownership model
- ⬜ Spectator binding system (observe another player's widget state)
- ⬜ Bandwidth optimization (delta compression for widget properties)
- ⬜ Register sync hooks into WidgetManagerBase via delegate (OnWidgetStateChanged intercepted for replication)

**IValidWidgetInterface Removal (COMPLETE - Feb 2, 2026):**
- ✅ Merged into IManagedWidgetInterface with `IsValidWidget()` BlueprintNativeEvent
- ✅ Redundant interface removed: validation only happens on already-managed widgets
- ✅ Interface count: 18 → 17
- ✅ ValidWidgetInterface.h deleted

**Widget Location Rule (COMPLETE - Feb 2, 2026):**
- Widgets belong in their OWNING PLUGIN's `UI/` folder
- NOT in MSB or AWF (AWF only contains base classes)
- Each plugin owns its domain-specific widgets:
  - ModularInteractionSystem: Widget_InteractionPrompt, Widget_PreInteraction
  - ModularInventorySystem: BoxSelectionWidget, InventorySlotDragDropOperation, inventory widgets
  - MSB: UWidgetDragDropOperation (generic base class in Operations/)
  - SimulatorFramework: MiniGame widgets, ApplicationBase

---

## 🏷️ GAMEPLAY TAG GOVERNANCE

### Overview

All GameplayTags in the Windwalker Framework are centralized in two locations:
- **Registration:** `Config/DefaultGameplayTags.ini` (engine registration, editor discovery)
- **Code Access:** `WW_TagLibrary.h/.cpp` in SharedDefaults (type-safe, compile-time validation)

### Why Dual Registration?

| Location | Purpose | Consumer |
|----------|---------|----------|
| DefaultGameplayTags.ini | Engine registration, editor tag picker discovery | Designers, Blueprint |
| WW_TagLibrary | Type-safe access, static caching, compile-time validation | C++ code |

### Tag Category Prefixes

| Plugin | Tag Prefix | Example |
|--------|------------|---------|
| SharedDefaults | `Movement.*`, `Character.*` | `Movement.Stance.Standing` |
| ModularPlayerController | `Camera.*` | `Camera.Mode.TPS` |
| ModularInventorySystem | `Inventory.*` | `Inventory.Slot.MainHand` |
| SimulatorFramework | `Simulator.*` | `Simulator.Device.State.Off` |
| AdvancedWidgetFramework | `UI.*` | `UI.Widget.Category.HUD` |
| ModularCheatManager | `Cheat.*` | `Cheat.Permission.Admin` |
| Input (global) | `Input.*` | `Input.Numpad.0` |

### 5-Step Protocol for Adding New Tags

**STEP 1: Register in DefaultGameplayTags.ini**
```ini
; Location: Config/DefaultGameplayTags.ini
; Add under appropriate "; --- Plugin: Category ---" comment
+GameplayTags=(Tag="Category.Subcategory.Name",DevComment="Description")
```

**STEP 2: Define in WW_TagLibrary.cpp (WW_Internal namespace)**
```cpp
// Location: WW_TagLibrary.cpp → namespace WW_Internal { }
UE_DEFINE_GAMEPLAY_TAG(Category_Subcategory_Name, "Category.Subcategory.Name");
```

**STEP 3: Declare accessor in WW_TagLibrary.h**
```cpp
// Location: WW_TagLibrary.h → appropriate section
static const FGameplayTag& Category_Subcategory_Name();
```

**STEP 4: Implement accessor in WW_TagLibrary.cpp**
```cpp
// Location: WW_TagLibrary.cpp → after namespace
const FGameplayTag& FWWTagLibrary::Category_Subcategory_Name()
{
    static const FGameplayTag& Tag = WW_Internal::Category_Subcategory_Name;
    return Tag;
}
```

**STEP 5: Use via WW_TagLibrary accessor**
```cpp
// Usage
FWWTagLibrary::Category_Subcategory_Name()
// Include
#include "Lib/Data/Tags/WW_TagLibrary.h"
```

### Naming Conventions

| Element | Convention | Example |
|---------|------------|---------|
| Tag String | `Category.Subcategory.Name` | `Simulator.MiniGame.Type.Lockpick` |
| Function Name | `Category_Subcategory_Name` | `Simulator_MiniGame_Type_Lockpick()` |
| DevComment | Brief description | `"Lockpick mini-game type"` |

### Common Mistakes

❌ Using `FGameplayTag::RequestGameplayTag("Tag.Name")` directly
✅ Using `FWWTagLibrary::Tag_Name()`

❌ Adding tag to only one location
✅ Adding to BOTH ini AND WW_TagLibrary

❌ Mismatched tag strings between locations
✅ Copy-paste exact string, verify match in all 4 locations

### Validation Checklist (Before Commit)

- [ ] Tag exists in `DefaultGameplayTags.ini`
- [ ] Tag defined in `WW_Internal` namespace
- [ ] Accessor declared in `WW_TagLibrary.h`
- [ ] Accessor implemented in `WW_TagLibrary.cpp`
- [ ] Tag string matches EXACTLY in all 4 locations
- [ ] Function name matches tag hierarchy (dots → underscores)
- [ ] No `RequestGameplayTag()` calls in new code

---

## 📁 WORKFLOW PROTOCOL FILES

**Location:** Project root (`D:\Unreal Projects (2nd Place)\CPPDrugLordClone\`)

### File Structure

| File | Purpose | When Used | Token Cost |
|------|---------|-----------|------------|
| `WW_SESSION_STARTER.md` | Detect leftover task, plan session | Every session start | ~200 |
| `WW_CLAUDE_CODE_PROMPTS.md` | Copy-paste prompts for Claude Code | During implementation | ~800 |
| `WW_END_OF_SESSION.md` | Generate next-session briefing | Every session end | ~150 |
| `WW_LEARNING_MODE.md` | Deep-dive C++ explanations | Off-days / low energy | ~300 |

**Total overhead per session:** ~1.5K tokens (protocol files only)

---

### WW_SESSION_STARTER.md Content

```markdown
# SESSION INITIALIZATION

I'm continuing Windwalker Framework work. I've uploaded:
- WINDWALKER_FRAMEWORK_ARCHITECTURE_V2_13_REVISED.md
- WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md

**Read both, then:**

1. **Check for leftover task** - Search past 2 chats for incomplete work
2. **If leftover exists** - Resume that task (tell me what it is + current state)
3. **If no leftover** - Consult TODO file, recommend next task based on:
   - Priority (P0 > P1 > P2 > P3 > P4)
   - Dependencies (blocked tasks skip)
   - My stated energy level (if I mention it)

**Output format:**
LEFTOVER DETECTED: [task name]
STATUS: [what's done, what remains]
NEXT STEP: [exact action to take]

Or:

NO LEFTOVER
RECOMMENDED: [task from TODO]
REASON: [why this task now]
ESTIMATED TIME: [X hours]

**Then ask:** "Approve to proceed, or select different task?"

**Rules Embedded:** Golden Rule #34 (search past chats), #36 (ADD before implementation)
```

---

### WW_CLAUDE_CODE_PROMPTS.md Content

```markdown
# CLAUDE CODE PROMPTS - COPY/PASTE LIBRARY

## GENERIC SYSTEM PROMPT
Implement [SYSTEM_NAME] for Windwalker Framework V2.13.1 following ADD approved in claude.ai.

RULES:
- Performance: <0.02ms overhead, use spatial hashing/caching
- Networking: ALWAYS add Server RPCs, OnRep functions, COND_OwnerOnly
- Dependencies: L2→L0.5 only (no lateral L2→L2)
- Communication: UP via delegates (EventBus or direct)
- Data: Pure structs + IsValid() only. Logic in Helpers.
- Interfaces: ImplementsInterface() + Execute_, mandatory getter
- Tags: Cache as UPROPERTY, Plugin.Category.Sub format
- Includes: Own→SharedDefaults→MSB→Engine→.generated.h LAST

FILES TO CREATE: [list from ADD]
OUTPUT: Summary of files created + any architectural decisions made
```

---

### WW_END_OF_SESSION.md Content

```markdown
# END OF SESSION

Generate a briefing file for my next session.

**Include:**
1. **Task completed** - What was finished this session
2. **Task in progress** - What's partially done (if any)
3. **Next recommended task** - From TODO, with priority
4. **Files modified** - List of files changed this session
5. **Decisions made** - Any architectural choices
6. **Blockers** - Anything preventing progress

**Output format:** WW_SESSION_BRIEFING_[DATE].md

**I will save this file and upload it at next session start.**
```

---

### WW_LEARNING_MODE.md Content

```markdown
# LEARNING MODE

**Trigger:** Paste this when you want deep C++ explanations, not implementation.

**Input:** Upload Claude Code summary from performance session

**I will explain:**
1. **C++ Concepts Used** - Why TSet vs TArray, why lambda, why const ref
2. **UE5 Patterns** - UPROPERTY, UFUNCTION, RPC patterns, replication
3. **Framework Patterns** - Why this structure follows Golden Rules
4. **Junior Pitfalls** - What would break and why
5. **Senior Insights** - Performance implications, memory layout, cache coherency

**Format:** Natural prose, teach like mentor explaining over coffee.
**Energy required:** Minimal - passive learning, no decisions.
**After explanation, ask:** "What else from this summary needs clarification?"
```

---

### Workflow: Performance Mode

```
START (claude.ai)
├─ Upload: ARCHITECTURE + TODO files
├─ Paste: SESSION_STARTER content
├─ I detect leftover or recommend next task
├─ You approve → I write ADD
└─ I output Claude Code prompt

IMPLEMENTATION (Claude Code terminal)
├─ Paste prompt → Claude Code implements
├─ Use /compact at 70% context
└─ Claude Code outputs summary

VALIDATION (claude.ai)
├─ Paste summary → I verify against ADD
├─ Flag violations, confirm compilation
└─ Mark task complete

END (claude.ai)
├─ Paste: END_OF_SESSION content
└─ I generate briefing for next session
```

### Workflow: Learning Mode

```
1. Paste WW_LEARNING_MODE.md content
2. Upload Claude Code summary from performance session
3. I explain: C++ concepts, UE5 patterns, why each decision
4. Senior-level depth (140 IQ teaching style)
5. Ask "What else needs clarification?"
```

---

## 🔌 PLUGIN ARCHITECTURE

### Layer Definitions

**Layer 0 (L0): Foundation**
- SharedDefaults only
- No dependencies
- Contains: Interfaces, delegates, structs, enums, tags
- Location: `Windwalker_Productions_SharedDefaults/`

**Layer 0.5 (L0.5): Shared Infrastructure**
- ModularSystemsBase
- Depends on: L0
- Contains: Helpers, base components, shared subsystems
- Location: `ModularSystemsBase/`

**Layer 2 (L2): Feature Plugins**
- All other plugins
- Depends on: L0, L0.5
- No lateral L2 → L2 dependencies
- Communication UP via delegates
- Locations: Individual plugin folders

### Dependency Matrix

| Plugin | Depends On | Can Be Deleted? | File Location |
|--------|------------|-----------------|---------------|
| Windwalker_Productions_SharedDefaults | None | ❌ (Foundation) | `/Windwalker_Productions_SharedDefaults/` |
| ModularSystemsBase | L0 | ❌ (Core) | `/ModularSystemsBase/` |
| ModularInventorySystem | L0, L0.5 | ✅ | `/ModularInventorySystem/` |
| ModularInteractionSystem | L0, L0.5 | ✅ | `/ModularInteractionSystem/` |
| CraftingPlugin | L0, L0.5 | ✅ | `/CraftingPlugin/` |
| SimulatorFramework | L0, L0.5 | ✅ | `/SimulatorFramework/` |
| ModularSaveGameSystem | L0, L0.5 | ✅ | `/ModularSaveGameSystem/` |
| ModularPlayerController | L0, L0.5 | ✅ | `/ModularPlayerController/` |
| AdvancedWidgetFramework | L0, L0.5 | ✅ | `/AdvancedWidgetFramework/` |
| ModularSpawnSystem | L0, L0.5 | ✅ | `/ModularSpawnSystem/` |
| ModularCheatManager | L0, L0.5 | ✅ | `/ModularCheatManager/` |

### Communication Patterns

**Downward (Dependencies):**
```cpp
// L2 Plugin → Calls Helper (L0.5)
#include "Utilities/Helpers/Item/ItemHelpers.h"
UItemHelpers::GetItemData(ItemID);

// L2 Plugin → Calls Interface (L0)
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"
IInventoryInterface::Execute_AddItem(Component, ItemID, 1);
```

**Upward (Communication):**
```cpp
// L2 Component → Broadcasts Delegate (L0)
#include "Delegates/ModularInventorySystem/InventoryDelegates.h"
OnItemAdded.Broadcast(ItemID, Quantity);

// L0.5 Subsystem → Listens to Delegate
#include "Subsystems/EventBusSubsystem.h"
EventBus->OnInventoryChanged.AddDynamic(this, &UMySubsystem::HandleInventoryChanged);

// L2 Plugin → Listens to Delegate
Component->OnItemRemoved.AddDynamic(this, &AMyActor::HandleItemRemoved);
```

**Lateral (FORBIDDEN):**
```cpp
// ❌ WRONG: L2 Plugin A → Calls L2 Plugin B directly
#include "ModularInventorySystem/Components/InventoryComponent.h"  // FORBIDDEN!
UInventoryComponent* InvComp = Cast<UInventoryComponent>(Comp);  // VIOLATES RULE #30

// ✅ CORRECT: L2 Plugin A → Broadcasts Delegate → L2 Plugin B listens
#include "Delegates/CraftingDelegates/CraftingDelegates.h"
OnCraftingComplete.Broadcast(RecipeID);  // Plugin A broadcasts
// Plugin B listens to delegate (no direct dependency)
```

---

## 🔗 INTERFACE SYSTEM

### Complete Interface List (8 Interfaces)

| Interface | File Location | Mandatory Getter | Functions | Purpose |
|-----------|---------------|------------------|-----------|---------|
| IInventoryInterface | `Interfaces/ModularInventorySystem/InventoryInterface.h` | GetInventoryAsActorComponent() | 28 | Item management |
| IInteractableInterface | `Interfaces/ModularInteractionSystem/InteractableInterface.h` | GetInteractableAsActor() | 9 | Interaction, pickup |
| ICraftingInterface | `Interfaces/ModularInventorySystem/CraftingInterface.h` | GetCrafterAsActorComponent() | 7 | Crafter capabilities |
| IMiniGameStationInterface | `Interfaces/SimulatorFramework/MiniGameStationInterface.h` | GetStationAsActor() | 6 | Mini-game lifecycle |
| IDurabilityInterface | `Interfaces/SimulatorFramework/DurabilityInterface.h` | GetDurabilityAsActorComponent() | 7 | Durability operations |
| ISaveableInterface | `Interfaces/ModularSaveGameSystem/SaveableInterface.h` | GetSaveableAsObject() | 7 | Save/load state |
| ICameraControlInterface | `Interfaces/ModularPlayerController/CameraControlInterface.h` | GetCameraControllerAsActor() | 5 | Camera modes |
| IPhysicalInteractionInterface | `Interfaces/SimulatorFramework/PhysicalInteractionInterface.h` | GetPhysicalInteractableAsActor() | 6 | Physics grab |

### Interface Creation Rules

**Create interface when TWO OR MORE conditions met:**
- Cross-plugin access (2+ plugins call it)
- Multiple implementations exist
- Blueprint override required
- Polymorphic calls needed

**Anti-patterns (don't create interface):**
- Single implementation only
- Internal-only calls
- Pure data access (use getters)
- Static helper functions

### Interface Scope

**INCLUDE in interface:**
- ALL public entry points
- Core system logic other plugins need
- Functions other plugins COULD call (future-proof)
- MANDATORY: Getter for underlying UObject

**EXCLUDE from interface:**
- `Internal_` prefixed functions
- `Server_` RPC functions
- `OnRep_` replication callbacks
- Private implementation details

### Interface Implementation Pattern

```cpp
// SharedDefaults/Interfaces/ModularInventorySystem/InventoryInterface.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "InventoryInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UInventoryInterface : public UInterface
{
    GENERATED_BODY()
};

class IInventoryInterface
{
    GENERATED_BODY()

public:
    /**
     * Get underlying actor component for engine functions
     * MANDATORY GETTER for type-safe access without casting
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory")
    UActorComponent* GetInventoryAsActorComponent() const;
    
    /**
     * Add item to inventory
     * 
     * ATOMIC CONTRACT:
     * - Returns true if item added successfully
     * - Returns false if inventory full or invalid item
     * - Handles networking internally (no Server_ prefix)
     * - < 0.02ms execution time
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Inventory")
    bool AddItem(FGameplayTag ItemID, int32 Quantity);
    
    // ... more interface functions
};
```

```cpp
// ModularInventorySystem/Components/InventoryComponent.h
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"  // L0 interface
#include "InventoryComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MODULARINVENTORYSYSTEM_API UInventoryComponent : public UActorComponent, public IInventoryInterface
{
    GENERATED_BODY()

public:
    // Mandatory getter implementation
    virtual UActorComponent* GetInventoryAsActorComponent_Implementation() const override
    {
        return const_cast<UInventoryComponent*>(this);
    }
    
    // Public API implementation
    virtual bool AddItem_Implementation(FGameplayTag ItemID, int32 Quantity) override
    {
        // Authority check + networking handled internally
        if (GetOwnerRole() < ROLE_Authority)
        {
            Server_AddItem(ItemID, Quantity);
            return PredictAddItem(ItemID, Quantity);  // Client prediction
        }
        
        return Internal_AddItem(ItemID, Quantity);
    }

private:
    // Server RPC (NOT in interface)
    UFUNCTION(Server, Reliable, WithValidation)
    void Server_AddItem(FGameplayTag ItemID, int32 Quantity);
    
    // Internal implementation (NOT in interface)
    bool Internal_AddItem(FGameplayTag ItemID, int32 Quantity);
    
    // Client prediction (NOT in interface)
    bool PredictAddItem(FGameplayTag ItemID, int32 Quantity);
};
```

### Strict No-Casting Rule (Priority Cascade)

```
1. Try interface FIRST (no casting)
   ✅ if (Comp->ImplementsInterface(UInventoryInterface::StaticClass()))
   
   ↓ If interface doesn't exist/work...
   
2. Check: Is this for optimization? (profiled performance need)
   ✅ if (PROFILED as bottleneck) → Cast OK
   
   ↓ If not optimization...
   
3. Check: Is target an engine class? (AActor, UActorComponent)
   ✅ AActor* Actor = Cast<AActor>(Object);  // Engine class OK
   
   ↓ If not engine class...
   
4. Check: Are we within same plugin? (internal casting OK)
   ✅ UInventoryComponent* InvComp = Cast<UInventoryComponent>(Comp);  // Same plugin OK
   
   ↓ If crossing plugin boundary...
   
5. DON'T CAST (violates independence rule)
   ❌ Cast<UInventoryComponent>(Comp)  // Cross-plugin = FORBIDDEN
```

---

## 💾 SAVE SYSTEM ARCHITECTURE

### Two-Tier Delegate Pattern (Rule #37)

```
Components (L2)
    ↓ depends on (include path)
    ↓ #include "Subsystems/SaveableRegistrySubsystem.h"
    ↓
USaveableRegistrySubsystem (L0.5) — Foundation Layer
    ↑ broadcasts delegates
    ↑ OnSaveableRegistered, OnSaveableUnregistered
    ↑
USaveGameSubsystem (L2) — Feature Layer (optional, deletable)
```

**File Locations:**
- Interface: `Windwalker_Productions_SharedDefaults/Interfaces/ModularSaveGameSystem/SaveableInterface.h`
- Data Struct: `Windwalker_Productions_SharedDefaults/Lib/Data/ModularSaveGameSystem/SaveData.h`
- Delegates: `Windwalker_Productions_SharedDefaults/Delegates/ModularSaveGameSystem/SaveDelegates.h`
- Registry: `ModularSystemsBase/Subsystems/SaveableRegistrySubsystem.h` (L0.5)
- Save System: `ModularSaveGameSystem/MasterSaveSubsystem.h` (L2)

### Why Delegate Pattern

**✅ Benefits:**
- Modularity: SaveGameSystem deletable (roguelikes, arcade games don't need it)
- Marketplace: SaveGameSystem sellable separately
- Architectural purity: Perfect UP/DOWN flow, no lateral dependencies
- Plugin independence: Delete SaveGameSystem → components still compile
- Framework Goal #5: "Delete any plugin → others still compile"

### ISaveableInterface (Complete)

```cpp
// File: Windwalker_Productions_SharedDefaults/Interfaces/ModularSaveGameSystem/SaveableInterface.h

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Lib/Data/ModularSaveGameSystem/SaveData.h"
#include "SaveableInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class USaveableInterface : public UInterface
{
    GENERATED_BODY()
};

class ISaveableInterface
{
    GENERATED_BODY()

public:
    /**
     * Get underlying UObject (polymorphic getter)
     * MANDATORY GETTER for type-safe access
     * 
     * ATOMIC CONTRACT:
     * - Returns this object as UObject*
     * - Never returns nullptr
     * - Used for save system registration
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
    UObject* GetSaveableAsObject() const;
    
    /**
     * Get save data from this object
     * 
     * ATOMIC CONTRACT (Rule #40):
     * - Serializes current state to FSaveData
     * - Clears dirty flag after successful save
     * - Must be deterministic (same state = same data)
     * - < 0.02ms execution time
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
    FSaveData GetSaveData() const;
    
    /**
     * Load save data into this object
     * 
     * ATOMIC CONTRACT:
     * - Deserializes FSaveData into current state
     * - Validates data before applying
     * - Marks dirty if state changed
     * - < 0.02ms execution time
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
    void LoadSaveData(const FSaveData& Data);
    
    /**
     * Get globally unique save ID (Rule #38)
     * 
     * ATOMIC CONTRACT:
     * - Format: "Actor.Component.Instance" for components
     * - Format: "Class.Name" for actors
     * - Must be deterministic (same object = same ID)
     * - Max 256 characters
     * - Never empty string
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
    FString GetSaveID() const;
    
    /**
     * Check if object state changed since last save (Rule #40)
     * 
     * ATOMIC CONTRACT:
     * - Returns true if state modified
     * - Returns false if unchanged
     * - Prevents unnecessary serialization
     * - Updated by MarkDirty() calls
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
    bool IsDirty() const;
    
    /**
     * Get save priority for load order (Rule #39)
     * 
     * ATOMIC CONTRACT:
     * - Actors: 0-49 (load first)
     * - Subsystems: 50-99
     * - Components: 100-149
     * - Managers: 150-199
     * - UI: 200+ (load last)
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
    int32 GetSavePriority() const;
    
    /**
     * Check if child objects should be saved
     * 
     * ATOMIC CONTRACT:
     * - Returns true if children need saving
     * - Returns false to skip children
     * - Used for hierarchical save optimization
     */
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Save")
    bool ShouldSaveChildren() const;
};
```

### Component Implementation Pattern

```cpp
// File: ModularInventorySystem/Components/InventoryComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/ModularSaveGameSystem/SaveableInterface.h"  // L0 interface
#include "InventoryComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class MODULARINVENTORYSYSTEM_API UInventoryComponent : public UActorComponent, public ISaveableInterface
{
    GENERATED_BODY()

public:
    UInventoryComponent();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
    // ISaveableInterface implementation
    
    virtual UObject* GetSaveableAsObject_Implementation() const override
    {
        return const_cast<UInventoryComponent*>(this);
    }
    
    virtual FSaveData GetSaveData_Implementation() const override
    {
        FSaveData Data;
        Data.SaveID = GetSaveID_Implementation();
        Data.Priority = GetSavePriority_Implementation();
        
        // Serialize inventory state
        // ... serialization code ...
        
        // Clear dirty flag (Rule #40)
        bIsDirty = false;
        
        return Data;
    }
    
    virtual void LoadSaveData_Implementation(const FSaveData& Data) override
    {
        // Validate data
        if (!Data.IsValid())
        {
            UE_LOG(LogSave, Warning, TEXT("Invalid save data for: %s"), *GetSaveID_Implementation());
            return;
        }
        
        // Deserialize inventory state
        // ... deserialization code ...
        
        // Mark dirty after load
        MarkDirty();
    }
    
    virtual FString GetSaveID_Implementation() const override
    {
        // Rule #38: Globally unique format
        if (!GetOwner())
        {
            UE_LOG(LogSave, Error, TEXT("GetSaveID called on component without owner"));
            return FString();
        }
        
        return FString::Printf(TEXT("%s.%s.%s"),
            *GetOwner()->GetName(),
            *GetClass()->GetName(),
            *GetFName().ToString()
        );
    }
    
    virtual bool IsDirty_Implementation() const override
    {
        return bIsDirty;
    }
    
    virtual int32 GetSavePriority_Implementation() const override
    {
        // Rule #39: Components = 100-149
        return 100;
    }
    
    virtual bool ShouldSaveChildren_Implementation() const override
    {
        return false;  // Inventory has no child saveables
    }

private:
    mutable bool bIsDirty = false;
    
    void MarkDirty()
    {
        bIsDirty = true;
    }
};
```

```cpp
// File: ModularInventorySystem/Components/InventoryComponent.cpp

#include "InventoryComponent.h"
#include "Subsystems/SaveableRegistrySubsystem.h"  // L0.5 foundation

void UInventoryComponent::BeginPlay()
{
    Super::BeginPlay();
    
    // Rule #37: Announce to registry (communication UP to L0.5)
    if (UGameInstance* GI = GetWorld()->GetGameInstance())
    {
        if (USaveableRegistrySubsystem* Registry = GI->GetSubsystem<USaveableRegistrySubsystem>())
        {
            Registry->AnnounceSaveable(this);  // Depends DOWN on L0.5
        }
    }
}

void UInventoryComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    // Rule #37: Revoke from registry
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

### Save Priority System (Rule #39)

| Priority Range | Object Type | Load Order | Save Order | Examples |
|----------------|-------------|------------|------------|----------|
| 0-49 | Actors | 1st (first) | Last (cleanup after components) | AInteractableActor, AMPC_Pawn_Master |
| 50-99 | Subsystems | 2nd | 4th | URegionSubsystem, UObjectiveTrackerSubsystem |
| 100-149 | Components | 3rd | 3rd | UInventoryComponent, UCrafterComponent |
| 150-199 | Managers | 4th | 2nd | UApplicationManager, UWidgetManager |
| 200+ | UI/Widgets | 5th (last) | 1st (first) | Inventory widgets, HUD |

**Load Order:** Priority 0 → Higher (actors before components before UI)  
**Save Order:** Higher → 0 (UI before components before actors for cleanup)

**Rationale:** Actors must exist before components can attach. Components must exist before UI can reference them.

### SaveID Format (Rule #38)

```cpp
// Components
FString::Printf(TEXT("%s.%s.%s"),
    *GetOwner()->GetName(),        // Unique per actor instance
    *GetClass()->GetName(),        // Unique per component type
    *GetFName().ToString()         // Unique per component instance
);
// Example: "PlayerPawn_0.InventoryComponent.InventoryComponent_GEN_VARIABLE"

// Actors
FString::Printf(TEXT("%s.%s"),
    *GetClass()->GetName(),        // Unique per actor type
    *GetName()                     // Unique per actor instance
);
// Example: "InteractableActor_Pickup.InteractableActor_Pickup_2"

// Subsystems
FString::Printf(TEXT("%s"),
    *GetClass()->GetName()         // Subsystems are singletons
);
// Example: "RegionSubsystem"
```

**Validation:**
- Must be deterministic (same object always produces same ID)
- Must be globally unique (no two objects share same ID)
- Must use dot notation for hierarchy
- Max 256 characters
- Never empty string

### Dirty Tracking (Rule #40)

```cpp
class UInventoryComponent
{
private:
    mutable bool bIsDirty = false;
    
    void MarkDirty()
    {
        bIsDirty = true;
    }

public:
    virtual bool AddItem_Implementation(FGameplayTag ItemID, int32 Quantity) override
    {
        bool bSuccess = Internal_AddItem(ItemID, Quantity);
        
        // Mark dirty on state change
        if (bSuccess)
        {
            MarkDirty();
        }
        
        return bSuccess;
    }
    
    virtual FSaveData GetSaveData_Implementation() const override
    {
        FSaveData Data;
        // ... serialize state ...
        
        // Clear dirty flag after save (Rule #40)
        bIsDirty = false;
        
        return Data;
    }
    
    virtual bool IsDirty_Implementation() const override
    {
        return bIsDirty;
    }
};
```

**Performance impact:**
- Without dirty tracking: Save 200 objects every save = 200 serializations
- With dirty tracking: Save 20 changed objects = 20 serializations
- **10x performance improvement**

### Deletion Test (Rule #5)

```
Delete ModularSaveGameSystem plugin:
    
    Components still call:
    Registry->AnnounceSaveable(this) in BeginPlay
        ↓
    Registry has no listeners subscribed to OnSaveableRegistered delegate
        ↓
    Delegate broadcast = no-op (graceful degradation)
        ↓
    ✅ All plugins still compile
    ✅ Framework continues functioning
    ✅ No save/load, but no crashes
```

**This validates:**
- Rule #5: Delete any plugin → others still compile
- Rule #7: Communication flows UP via delegates
- Rule #37: Two-tier architecture with optional feature layer

---

## 🔄 WORKFLOW SYSTEMS

### Workflow V1: User Proposal (4-Phase Validation)

**Approach:** Stub → Skeleton → Atomic → Complete  
**Validations:** 4 per system  
**Focus:** Maximum early error detection

**Phases:**
1. **Stubs** — Empty class declarations
2. **Skeletons** — Function signatures only
3. **Atomic Functions** — Small, isolated implementations
4. **Complete** — Full integration

**Metrics:**
- Validations: 4
- Messages: 6-8
- Time: ~2 hours
- Cognitive load: High (4 context switches)

**Use when:** System is completely new, user wants maximum control, correctness > speed

---

### Workflow V2: Claude Proposal (Maximum Output) ✅ RECOMMENDED

**Approach:** Architecture Lock-In → Auto-Implementation  
**Validations:** 1 per system  
**Focus:** Maximum output, minimum cognitive load

**Phase 1: Architecture Decision Document (ADD)**

User requests: "Implement save system using delegate pattern"

Claude provides ADD:
```markdown
## SAVE SYSTEM — ARCHITECTURE LOCK-IN

### Summary
Two-tier delegate pattern: Registry (L0.5) + SaveGame (L2)

### Files to Create (8 total)
1. SaveableInterface.h → Windwalker_Productions_SharedDefaults/Interfaces/ModularSaveGameSystem/
2. SaveData.h → Windwalker_Productions_SharedDefaults/Lib/Data/ModularSaveGameSystem/
3. SaveDelegates.h → Windwalker_Productions_SharedDefaults/Delegates/ModularSaveGameSystem/
4. SaveableRegistrySubsystem.h → ModularSystemsBase/Subsystems/
5. SaveableRegistrySubsystem.cpp → ModularSystemsBase/Private/Subsystems/
6. MasterSaveSubsystem.h → ModularSaveGameSystem/
7. MasterSaveSubsystem.cpp → ModularSaveGameSystem/Private/
8. Update InventoryComponent, CrafterComponent, DurabilityComponent

### Dependency Flow
✅ L2 Components → L0.5 Registry (dependencies DOWN)
✅ L0.5 Registry → L2 SaveGame (communication UP via delegates)
❌ No L2 → L2 lateral dependencies

### Performance Budget
Registry: < 0.001ms per announcement
Save: < 0.02ms per object (with dirty tracking)
Load: < 0.05ms per object

### Validation Criteria
✅ Delete ModularSaveGameSystem → others compile
✅ SaveID uniqueness enforced
✅ Dirty tracking prevents unnecessary saves
✅ Load order respects priority (actors before components)

### Golden Rules Applied
Rule #37: Two-tier delegate architecture
Rule #38: SaveID globally unique format
Rule #39: Save priority determines load order
Rule #40: Dirty tracking for performance

**USER: Approve to proceed or request changes**
```

User validates: **"Approved"** or **"Change X to Y"**

---

**Phase 2-N: Auto-Implementation**

Claude produces everything in 1-3 messages:

**Message 1: Foundation (300 LOC)**
- SaveableInterface.h with all 7 functions
- SaveData.h struct definition
- SaveDelegates.h declarations
- SaveableRegistrySubsystem.h/.cpp complete

**Message 2: Features (250 LOC)**
- MasterSaveSubsystem.h/.cpp complete
- SaveGame/LoadGame implementations
- Dirty tracking logic
- Priority sorting

**Message 3: Integration (200 LOC)**
- InventoryComponent BeginPlay/EndPlay
- CrafterComponent implementation
- DurabilityComponent implementation

**User does NOTHING during implementation**

---

**Final: Quality Certificate & Integration Checklist**

```markdown
✅ QUALITY GUARANTEE CERTIFICATE

System: Save System (Delegate Pattern)
Files: 8 total, 950 LOC

VALIDATED GUARANTEES:
✅ Compiles first time (includes validated)
✅ Framework compliant (Rules #37-40 verified)
✅ Performance budget met (< 0.02ms per object)
✅ Plugin independent (deletion test passed)

INTEGRATION CHECKLIST:
1. Copy SaveableInterface.h to SharedDefaults/Interfaces/ModularSaveGameSystem/
2. Copy SaveData.h to SharedDefaults/Lib/Data/ModularSaveGameSystem/
3. Copy SaveDelegates.h to SharedDefaults/Delegates/ModularSaveGameSystem/
4. Copy SaveableRegistrySubsystem.h/.cpp to ModularSystemsBase/Subsystems/
5. Copy MasterSaveSubsystem.h/.cpp to ModularSaveGameSystem/
6. Compile SharedDefaults
7. Compile ModularSystemsBase
8. Compile ModularSaveGameSystem
9. Update component plugins (InventoryComponent, etc)
10. Test: Create actor → Save → Destroy → Load → Verify restored

CONFIDENCE: 95%
SLEEP SOUNDLY: This code is solid.
```

**Metrics:**
- Validations: 1
- Messages: 3-4
- Time: ~30 minutes
- Output per message: 200-300 LOC
- Cognitive load: Minimal

---

## 🎨 DESIGN PATTERNS

### Pattern 1: Atomic Composition (Rule #33)

**Source:** MiniGame System Design  
**File locations:** `SharedDefaults/Lib/Data/Core/` and `SharedDefaults/Lib/Data/SimulatorFramework/`

**When to use:** Building complex systems with hierarchical data

**Layer 0: Atomics**
```cpp
// File: Windwalker_Productions_SharedDefaults/Lib/Data/Core/InputConfigData.h

USTRUCT(BlueprintType)
struct FAxisInputConfig
{
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, Category = "Input")
    bool bEnabled = true;
    
    UPROPERTY(EditAnywhere, Category = "Input")
    EInputSource Source = EInputSource::Both;
    
    UPROPERTY(EditAnywhere, Category = "Input")
    float Sensitivity = 1.0f;
    
    UPROPERTY(EditAnywhere, Category = "Input")
    bool bInvert = false;
    
    UPROPERTY(EditAnywhere, Category = "Input")
    bool bClamp = false;
    
    UPROPERTY(EditAnywhere, Category = "Input", meta = (EditCondition = "bClamp"))
    float ClampMin = -1.0f;
    
    UPROPERTY(EditAnywhere, Category = "Input", meta = (EditCondition = "bClamp"))
    float ClampMax = 1.0f;
    
    UPROPERTY(EditAnywhere, Category = "Input")
    EAxisReference Reference = EAxisReference::View;
    
    // Only validation logic allowed in structs
    bool IsValid() const 
    { 
        return bEnabled && Sensitivity > 0.0f; 
    }
};
```

**Layer 1: Composites**
```cpp
// File: Windwalker_Productions_SharedDefaults/Lib/Data/SimulatorFramework/MiniGameData.h

USTRUCT(BlueprintType)
struct FManipulationConfig
{
    GENERATED_BODY()
    
    // Composed of 6 atomics
    UPROPERTY(EditAnywhere, Category = "Movement")
    FAxisInputConfig MovementX;
    
    UPROPERTY(EditAnywhere, Category = "Movement")
    FAxisInputConfig MovementY;
    
    UPROPERTY(EditAnywhere, Category = "Movement")
    FAxisInputConfig MovementZ;
    
    UPROPERTY(EditAnywhere, Category = "Rotation")
    FAxisInputConfig RotationPitch;
    
    UPROPERTY(EditAnywhere, Category = "Rotation")
    FAxisInputConfig RotationYaw;
    
    UPROPERTY(EditAnywhere, Category = "Rotation")
    FAxisInputConfig RotationRoll;
    
    UPROPERTY(EditAnywhere, Category = "Grab")
    float MaxGrabDistance = 300.0f;
    
    // Helper functions (no business logic)
    bool HasMovement() const 
    { 
        return MovementX.bEnabled || MovementY.bEnabled || MovementZ.bEnabled; 
    }
    
    bool HasRotation() const 
    { 
        return RotationPitch.bEnabled || RotationYaw.bEnabled || RotationRoll.bEnabled; 
    }
};
```

**Layer 2: Shared Systems**
```cpp
// File: Windwalker_Productions_SharedDefaults/Lib/Data/Core/ObjectiveData.h

USTRUCT(BlueprintType)
struct FObjectiveCondition
{
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, Category = "Objective")
    FGameplayTag ObjectiveTag;
    
    UPROPERTY(EditAnywhere, Category = "Objective")
    ECompareOp Operator = ECompareOp::GreaterEqual;
    
    UPROPERTY(EditAnywhere, Category = "Objective")
    float TargetValue = 1.0f;
    
    bool IsValid() const 
    { 
        return ObjectiveTag.IsValid(); 
    }
};

USTRUCT(BlueprintType)
struct FObjectiveSet
{
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, Category = "Objectives")
    TArray<FObjectiveEntry> Entries;
    
    UPROPERTY(EditAnywhere, Category = "Objectives")
    int32 OptionalRequiredCount = 0;
    
    bool IsValid() const 
    { 
        return Entries.Num() > 0; 
    }
};
```

**Layer 3: System Definitions**
```cpp
// File: Windwalker_Productions_SharedDefaults/Lib/Data/SimulatorFramework/MiniGameData.h

USTRUCT(BlueprintType)
struct FMiniGameData : public FTableRowBase
{
    GENERATED_BODY()
    
    UPROPERTY(EditAnywhere, Category = "MiniGame")
    FGameplayTag MiniGameID;
    
    UPROPERTY(EditAnywhere, Category = "Camera")
    FGameplayTag CameraModeTag;
    
    // Layer 1: Composites (which contain Layer 0 atomics)
    UPROPERTY(EditAnywhere, Category = "Manipulation")
    FManipulationConfig ManipulationRules;
    
    UPROPERTY(EditAnywhere, Category = "Lockpick")
    FLockpickConfig LockpickRules;
    
    // Layer 2: Shared systems
    UPROPERTY(EditAnywhere, Category = "Objectives")
    FObjectiveSet Objectives;
    
    // Handler reference
    UPROPERTY(EditAnywhere, Category = "Handler")
    TSubclassOf<UMiniGameHandlerBase> HandlerClass;
    
    bool IsValid() const 
    { 
        return MiniGameID.IsValid() && HandlerClass != nullptr; 
    }
};
```

**Benefits:**
- Reusability: FAxisInputConfig used in mini-games, vehicles, cameras, UI
- Maintainability: Change FAxisInputConfig once → affects all uses
- Testability: Test atomics in isolation, composites inherit correctness
- Designer-friendly: Clean DataTable columns with collapsed structs

---

### Pattern 2: Research Methodology (Rule #35)

**Source:** MiniGame System Research (13 games analyzed)

**5-Step Process:**

**Step 1: Identify Target Games**

Before starting research, ask user:
> "Any additional specific game mechanics or games you want included in the research?"

Wait for user response.

Then select 5+ successful games across diverse genres:
- Schedule I (drug crafting hands-on mechanics)
- Bellwright (crafting stations, settlements)
- My Summer Car (assembly, bolt tightening)
- Skyrim/Fallout (lockpicking sweetspot)
- Splinter Cell (lockpicking feedback)
- Stardew Valley (fishing)
- Overcooked (cooking timing)
- Valheim (mining/chopping rhythm)
- Deus Ex/Bioshock (hacking patterns)

**Step 2: Decompose Mechanics**

Create comparison table:

| Game | Mechanic | Input | Feedback | Completion | Failure | Scaling |
|------|----------|-------|----------|------------|---------|---------|
| Skyrim | Lockpicking | Rotate pick | Pick wobbles | Lock opens | Pick breaks | Sweetspot size |
| My Summer Car | Assembly | Mouse scroll | Visual "OK" | Part snaps | None | Bolt count |
| Stardew | Fishing | Hold/release | Bar position | Progress fills | Fish escapes | Fish behavior |

**Step 3: Categorize by Primitives**

Group mechanics by shared atomic components:

```
SWEETSPOT MECHANICS:
- Skyrim lockpicking
- Splinter Cell lockpicking
- Safe dial codes
→ Common Atomic: FSweetspotConfig

TIMING MECHANICS:
- Oblivion tumblers
- Rhythm games
- QTE prompts
→ Common Atomic: FTimingWindowConfig

MANIPULATION MECHANICS:
- My Summer Car assembly
- Sons of Forest building
→ Common Atomic: FAxisInputConfig (reused 6x)
```

**Step 4: Identify Missing Mechanics**

Check coverage:
- ✅ Covered: Lockpicking, timing, manipulation, temperature, calibration
- ❌ Missing: Fishing (future), hacking (future)

**Step 5: Extract Design Principles**

Document why designs work:
- "Make tedious tasks feel like gameplay" (Schedule I)
- "Input should mirror real-world action" (My Summer Car)
- "Challenge = hidden target + gradual revelation" (Skyrim)

---

## 📚 LEARNING SYSTEM

### Pattern Recognition Mode (Default, Always On)

**Zero overhead learning:**

```cpp
// ✅ PATTERN: TSet for uniqueness + O(1) lookup
TSet<TWeakObjectPtr<UObject>> RegisteredSaveables;

// ❌ BAD PATTERN (junior mistake):
// TArray<TWeakObjectPtr<UObject>> RegisteredSaveables;
// Why bad: O(n) Contains(), no auto-dedup, 200x slower

// 📊 PATTERN RULE: TSet when uniqueness + Contains() checks
```

**Time added:** 0 seconds  
**Retention:** 80%  
**Works:** Any energy level

**Mastery Timeline:**
- Week 1: 5 core patterns
- Week 4: 20 patterns = Senior intuition
- Week 8: 40+ patterns = Framework expert

---

### Deep Learning Mode (On-Demand)

**Trigger:**
> "Deep dive: TSet vs TArray"

**Claude provides:** 20-30 minute comprehensive lesson with:
- Performance analysis
- When to use each
- Practice problems
- Senior-level patterns

**Time:** 20-30 minutes  
**Energy:** High (only when fresh)  
**Retention:** 90%+

---

### Review Mode (Evening, Tired)

**Trigger:**
> "Review mode"

**Claude provides:** 5-minute active recall quiz

**Time:** 5-10 minutes  
**Energy:** Minimal  
**Retention:** 70-75%

---

## ✅ QUALITY ASSURANCE SYSTEM

### 5-Layer Validation (Before Every Delivery)

**Layer 1: COMPILATION GUARANTEE**
- All includes present
- All types declared
- Function signatures match
- Properties in headers
- Macros correct

**Layer 2: FRAMEWORK COMPLIANCE**
- Golden Rules #1-40 checked
- No L2→L2 lateral dependencies
- Networking included
- Performance < 0.02ms

**Layer 3: ATOMIC CONTRACTS**
- Every function has contract
- Requirements met
- Edge cases handled

**Layer 4: PERFORMANCE**
- Hot paths < 0.02ms
- No sync operations
- Containers optimized
- Tags cached

**Layer 5: INTEGRATION**
- Checklist generated
- File locations correct
- Deletion test passed

---

### Quality Certificate

```markdown
✅ QUALITY GUARANTEE CERTIFICATE

System: [System Name]
Files: [Count] total, [LOC] LOC

VALIDATED GUARANTEES:
✅ Compiles first time
✅ Framework compliant (Rules verified)
✅ Performance budget met
✅ Plugin independent

CONFIDENCE: 95%
SLEEP SOUNDLY: This code is solid.
```

---

## 🔄 GIT REPOSITORY RULES

### Two-Repo Architecture

```
D:\Unreal Projects (2nd Place)\CPPDrugLordClone\  (Game repo: CPPDrugLordTycoonClone)
├── .git/                    ← Game repo root
├── Plugins/                 ← Framework repo: WWSimulatorFramework
│   └── .git/                ← Separate repo (nested, NOT submodule)
├── Source/
├── Content/
├── CLAUDE.md               ← Lives in GAME repo
├── WINDWALKER_FRAMEWORK_*.md  ← Lives in GAME repo
└── WW_*.md                 ← Lives in GAME repo
```

### Directory Mapping

| Repo | GitHub | Local Path | Contains |
|------|--------|------------|----------|
| WWSimulatorFramework | github.com/x11Windwalker11x/WWSimulatorFramework | `Plugins/` | 11 plugins ONLY |
| CPPDrugLordTycoonClone | github.com/x11Windwalker11x/CPPDrugLordTycoonClone | Project root | ALL content at root (Source/, Content/, Config/, *.md, etc.) |

**Note:** Game repo tracks everything at project root. Plugins/ folder is excluded because it has its own .git (nested Framework repo).

### MD Files Location Rule

**ALL documentation files live in GAME repo (project root), NOT in Framework repo (Plugins/):**
- CLAUDE.md
- WINDWALKER_FRAMEWORK_ARCHITECTURE_V2_13_REVISED.md
- WINDWALKER_FRAMEWORK_PROGRESS_TODO_V2_13.md
- WW_SESSION_STARTER.md, WW_CLAUDE_CODE_PROMPTS.md, WW_END_OF_SESSION.md, WW_LEARNING_MODE.md

### Push Commands

**Framework changes (plugins only):**
```bash
cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git add . && git commit -m "msg" && git push
```

**Game/Docs changes (INCLUDING all MD files):**
```bash
cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone" && git add . && git commit -m "msg" && git push
```

**Both repos (when both changed):**
```bash
# Framework first
cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git add . && git commit -m "framework: msg" && git push
# Then Game
cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone" && git add . && git commit -m "game: msg" && git push
```

### Pull Commands (Daily Use)

**Framework:**
```bash
cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone\Plugins" && git pull
```

**Game:**
```bash
cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone" && git pull
```

### Fresh Clone (New Machine)

```bash
cd "D:\Unreal Projects (2nd Place)"
git clone https://github.com/x11Windwalker11x/CPPDrugLordTycoonClone.git CPPDrugLordClone
cd CPPDrugLordClone
git clone https://github.com/x11Windwalker11x/WWSimulatorFramework.git Plugins
# Done. Full project.
```

### Recovery Commands

**Plugins missing/corrupted:**
```bash
cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone"
rm -rf Plugins
git clone https://github.com/x11Windwalker11x/WWSimulatorFramework.git Plugins
```

**Game files corrupted, keep plugins:**
```bash
cd "D:\Unreal Projects (2nd Place)\CPPDrugLordClone"
git fetch origin
git reset --hard origin/main
```

### NEVER Rules

- ❌ Push MD files to Framework repo (they belong in Game repo at project root)
- ❌ Push plugin code to Game repo (plugins have their own repo in Plugins/)
- ❌ Assume `git add .` in Game repo catches Plugins/ changes (nested repo requires separate commit)
- ❌ Forget to push both repos when both have changes
- ❌ Put .gitignore exclusions that block root content from Game repo (root content belongs in Game repo)

---

## 🎯 APPENDIX: QUICK REFERENCE

### Common Include Patterns

```cpp
// SharedDefaults interfaces
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"
#include "Interfaces/ModularSaveGameSystem/SaveableInterface.h"

// SharedDefaults data
#include "Lib/Data/Core/ObjectiveData.h"
#include "Lib/Data/ModularSaveGameSystem/SaveData.h"

// ModularSystemsBase helpers
#include "Utilities/Helpers/Item/ItemHelpers.h"

// ModularSystemsBase subsystems  
#include "Subsystems/EventBusSubsystem.h"
```

### File Creation Checklist

**New Interface:**
- [ ] 2+ conditions met (Rule #27)
- [ ] Created in SharedDefaults/Interfaces/[PluginName]/
- [ ] UINTERFACE + Interface class
- [ ] Mandatory getter included (Rule #29)
- [ ] No Server_/Internal_/OnRep_ (Rule #28)
- [ ] All functions < 0.02ms (Rule #31)

**New Component:**
- [ ] Created in [Plugin]/Components/
- [ ] Networking added (Rule #13)
- [ ] Performance optimized (Rule #14)
- [ ] Implements relevant interfaces
- [ ] BeginPlay/EndPlay for save system (Rule #32, #37)

---

## 📋 VERSION HISTORY

**V2.13.2** (February 2, 2026)
- ✅ Added Git Repository Rules section (Two-repo architecture)
- ✅ Documented Framework vs Game repo separation
- ✅ Added push/pull/clone/recovery commands
- ✅ Added NEVER rules for git workflow

**V2.13.1** (February 2, 2026)
- ✅ Added Golden Rules #41-47 (Widget & UI System)
- ✅ Added AWF Architecture section (Option B decision)
- ✅ Added Workflow Protocol Files section
- ✅ Documented AWF 4 deferred features with delegate pattern
- ✅ IValidWidgetInterface merged into IManagedWidgetInterface (COMPLETE)
- ✅ Added Golden Rule #47: Widgets belong in owning plugin's UI/ folder
- ✅ Updated Golden Rules count to 47

**V2.13 Revised** (January 27, 2026)
- ✅ Added complete repository structure (200+ files mapped)
- ✅ Added actual file paths for all plugins
- ✅ Added save system implementation rules (#37-40)
- ✅ Added file location to all code examples
- ✅ Updated Golden Rules count to 40
- ✅ Added detailed save system architecture with file paths
- ✅ Added include path reference with actual locations
- ✅ Complete integration ready for production

**V2.13** (January 27, 2026)
- Initial comprehensive architecture document
- 36 Golden Rules
- All 6 MD documents integrated

---

## 🎓 FRAMEWORK COMPLETE

**Production Status:** ✅ Ready

**Documentation:** ✅ Complete with file paths + workflow protocols

**Rules:** ✅ 48 Golden Rules (#1-47)

**Plugins:** ✅ 11 plugins mapped

**Files:** ✅ 200+ files documented

**Protocols:** ✅ 4 workflow files documented

**Git Workflow:** ✅ Two-repo architecture documented

---

**END OF WINDWALKER FRAMEWORK ARCHITECTURE V2.13 (REVISED)**
