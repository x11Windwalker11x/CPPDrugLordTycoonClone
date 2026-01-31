# WINDWALKER MODULAR FRAMEWORK ARCHITECTURE V2.13 (REVISED)

**Comprehensive Framework Documentation**  
**Date:** January 27, 2026  
**Status:** Production Ready  
**Revision:** Complete repository structure + Save system rules added

---

## 📚 TABLE OF CONTENTS

1. [Framework Overview](#framework-overview)
2. [Complete Repository Structure](#complete-repository-structure)
3. [Include Path Reference](#include-path-reference)
4. [Golden Rules (Complete #1-46)](#golden-rules)
5. [Plugin Architecture](#plugin-architecture)
6. [Interface System](#interface-system)
7. [Save System Architecture](#save-system-architecture)
8. [Workflow Systems](#workflow-systems)
9. [Design Patterns](#design-patterns)
10. [Learning System](#learning-system)
11. [Quality Assurance](#quality-assurance)

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
│   │   │   ├── ManagedWidgetInterface.h
│   │   │   └── ValidWidgetInterface.h
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
│   ├── InteractablePriorityStruct.h
│   ├── InteractionSubsystem.h
│   ├── ModularInteractionSystem.h
│   └── SpatialHashGrid.h
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
│   │   ├── InventoryGridWidget.h
│   │   ├── InventoryResizableWindowWidget.h
│   │   ├── InventorySlotWidget.h
│   │   └── RootWidget.h
│   ├── Subsystems/
│   │   └── InventoryWidgetManager.h
│   ├── ModularInventoryInteractableSystem.h
│   └── PickUpActor.h
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
```

### AdvancedWidgetFramework (L2)

```
AdvancedWidgetFramework/
├── Source/AdvancedWidgetFramework/Public/
│   ├── Interaction/
│   │   ├── BoxSelectionWidget.h
│   │   ├── Widget_InteractionPrompt.h
│   │   └── Widget_PreInteraction.h
│   ├── MasterWidgets/
│   │   └── ManagedWidget_Master.h
│   ├── Operations/
│   │   └── AWF_DragDropOperation.h
│   └── AdvancedWidgetFramework.h

NOTE: UWidgetManagerBase moved to ModularSystemsBase/Subsystems/AdvancedWidgetFramework/
NOTE: UInventoryWidgetManager in ModularInventorySystem/Subsystems/
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
```

### ModularSpawnSystem (L2)

```
ModularSpawnSystem/
├── Source/ModularSpawnSystem/Public/
│   ├── Subsystems/
│   │   └── UniversalSpawnManager.h
│   └── ModularSpawnSystem.h
```

### ModularCheatManager (L2)

```
ModularCheatManager/
├── Source/ModularCheatManager/Public/
│   ├── DeveloperWhiteListAsset.h
│   ├── ECheatPermissionLevel.h
│   ├── ModularCheatManager.h
│   └── ModularCheatManager_Master.h
```

---

## 📋 INCLUDE PATH REFERENCE

### UE Convention: .generated.h Files

`.generated.h` files are auto-generated by Unreal Header Tool (UHT) and placed in `Intermediate/Build/`. **Never document or list these files** - they are build artifacts.

**Standard Pattern:** Always include the `.generated.h` as the **last include** in your header file:
```cpp
// MyComponent.h
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyComponent.generated.h"  // ALWAYS LAST

UCLASS()
class MYPLUGIN_API UMyComponent : public UActorComponent
```

### Standard Include Patterns

**1. SharedDefaults Interfaces (18 total):**
```cpp
// ModularInventorySystem (4)
#include "Interfaces/ModularInventorySystem/InventoryInterface.h"
#include "Interfaces/ModularInventorySystem/CraftingInterface.h"
#include "Interfaces/ModularInventorySystem/SlottableInteface.h"
#include "Interfaces/ModularInventorySystem/ItemSpawnerInterface.h"

// ModularInteractionSystem (2)
#include "Interfaces/ModularInteractionSystem/InteractableInterface.h"
#include "Interfaces/ModularInteractionSystem/InteractorInterface.h"

// ModularPlayerController (2)
#include "Interfaces/ModularPlayerController/CameraControlInterface.h"
#include "Interfaces/ModularPlayerController/ModularInputReceiver.h"

// SimulatorFramework (5)
#include "Interfaces/SimulatorFramework/DurabilityInterface.h"
#include "Interfaces/SimulatorFramework/DegradableInterface.h"
#include "Interfaces/SimulatorFramework/DeviceInterface.h"
#include "Interfaces/SimulatorFramework/PhysicalInteractionInterface.h"
#include "Interfaces/SimulatorFramework/MiniGameStationInterface.h"

// ModularSaveGameSystem (1)
#include "Interfaces/ModularSaveGameSystem/SaveableInterface.h"

// ModularSpawnSystem (1)
#include "Interfaces/ModularSpawnSystem/SaveableInteface.h"

// ModularQuestSystem (1)
#include "Interfaces/ModularQuestSystem/GameplayEventHandlerInteface.h"

// AdvancedWidgetFramework (2)
#include "Interfaces/AdvancedWidgetFramework/ValidWidgetInterface.h"
#include "Interfaces/AdvancedWidgetFramework/ManagedWidgetInterface.h"
```

**2. SharedDefaults Delegates (8 total):**
```cpp
#include "Delegates/ModularInventorySystem/InventoryDelegates.h"
#include "Delegates/ModularInteractionSystem/InteractionDelegates.h"
#include "Delegates/CraftingDelegates/CraftingDelegates.h"
#include "Delegates/SimulatorFramework/SimulatorDelegates.h"
#include "Delegates/ModularSaveGameSystem/SaveDelegates.h"
#include "Delegates/ModularSpawnSystem/SpawnDelegates.h"
#include "Delegates/ModularQuestSystem/GameplayEventDelegates.h"
#include "Delegates/AdvancedWidgetFramework/WW_WidgetDelegates.h"
```

**3. SharedDefaults Data Structs (14 total):**
```cpp
// Core (3)
#include "Lib/Data/Core/InputConfigData.h"
#include "Lib/Data/Core/ObjectiveData.h"
#include "Lib/Data/Core/WorldObjectData.h"

// ModularInventorySystem (1)
#include "Lib/Data/ModularInventorySystem/InventoryData.h"

// ModularInteractionSystem (3)
#include "Lib/Data/ModularInteractionSystem/InteractionData.h"
#include "Lib/Data/ModularInteractionSystem/InteractionDefaultsConstants.h"
#include "Lib/Data/ModularInteractionSystem/InteractionPredictionState.h"

// ModularCraftingData (1)
#include "Lib/Data/ModularCraftingData/CraftingData.h"

// SimulatorFramework (1)
#include "Lib/Data/SimulatorFramework/MiniGameData.h"

// ModularSaveGameSystem (1)
#include "Lib/Data/ModularSaveGameSystem/SaveData.h"

// ModularSpawnSystem (1)
#include "Lib/Data/ModularSpawnSystem/SpawnData.h"

// ModularQuestSystem (2)
#include "Lib/Data/ModularQuestSystem/GameplayEventData.h"
#include "Lib/Data/ModularQuestSystem/CameraEvents.h"
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
#include "Subsystems/AdvancedWidgetFramework/WidgetManagerBase.h"  // Generic widget lifecycle
```

**7. ModularInventorySystem Subsystems (Inventory-Specific):**
```cpp
#include "Subsystems/InventoryWidgetManager.h"  // Inventory-specific widget management
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

## 📋 INTERFACE REGISTRY (18 Interfaces)

All interfaces live in `SharedDefaults/Public/Interfaces/<PluginName>/`. Use `SHAREDDEFAULTS_API` export macro.

| Interface | Plugin Folder | Include Path | Purpose |
|-----------|---------------|--------------|---------|
| IInventoryInterface | ModularInventorySystem | `Interfaces/ModularInventorySystem/InventoryInterface.h` | Inventory operations (Add, Remove, Drop, Equip) |
| ICraftingInterface | ModularInventorySystem | `Interfaces/ModularInventorySystem/CraftingInterface.h` | Crafting capability queries |
| ISlottableInterface | ModularInventorySystem | `Interfaces/ModularInventorySystem/SlottableInteface.h` | Items that can occupy slots |
| IItemSpawnerInterface | ModularInventorySystem | `Interfaces/ModularInventorySystem/ItemSpawnerInterface.h` | Actors that spawn items |
| IInteractableInterface | ModularInteractionSystem | `Interfaces/ModularInteractionSystem/InteractableInterface.h` | Objects that can be interacted with |
| IInteractorInterface | ModularInteractionSystem | `Interfaces/ModularInteractionSystem/InteractorInterface.h` | Actors that perform interactions |
| ICameraControlInterface | ModularPlayerController | `Interfaces/ModularPlayerController/CameraControlInterface.h` | Camera mode switching |
| IModularInputReceiver | ModularPlayerController | `Interfaces/ModularPlayerController/ModularInputReceiver.h` | Input routing to pawns |
| IDurabilityInterface | SimulatorFramework | `Interfaces/SimulatorFramework/DurabilityInterface.h` | Durability queries and modifications |
| IDegradableInterface | SimulatorFramework | `Interfaces/SimulatorFramework/DegradableInterface.h` | Objects with degradation over time |
| IDeviceInterface | SimulatorFramework | `Interfaces/SimulatorFramework/DeviceInterface.h` | Device state and power management |
| IPhysicalInteractionInterface | SimulatorFramework | `Interfaces/SimulatorFramework/PhysicalInteractionInterface.h` | Physics grab/manipulation |
| IMiniGameStationInterface | SimulatorFramework | `Interfaces/SimulatorFramework/MiniGameStationInterface.h` | Mini-game host actors |
| ISaveableInterface | ModularSaveGameSystem | `Interfaces/ModularSaveGameSystem/SaveableInterface.h` | Objects with persistent state |
| ISaveableInterface (Spawn) | ModularSpawnSystem | `Interfaces/ModularSpawnSystem/SaveableInteface.h` | Spawn system save support |
| IGameplayEventHandlerInterface | ModularQuestSystem | `Interfaces/ModularQuestSystem/GameplayEventHandlerInteface.h` | Gameplay event receivers |
| IValidWidgetInterface | AdvancedWidgetFramework | `Interfaces/AdvancedWidgetFramework/ValidWidgetInterface.h` | Widget validation |
| IManagedWidgetInterface | AdvancedWidgetFramework | `Interfaces/AdvancedWidgetFramework/ManagedWidgetInterface.h` | Widget lifecycle management |

---

## 📋 DELEGATE REGISTRY (8 Delegate Files)

All delegates live in `SharedDefaults/Public/Delegates/<PluginName>/`. Delegates enable UP communication.

| Delegate File | Plugin | Include Path | Key Delegates |
|---------------|--------|--------------|---------------|
| InventoryDelegates.h | ModularInventorySystem | `Delegates/ModularInventorySystem/InventoryDelegates.h` | OnItemAdded, OnItemRemoved, OnSlotChanged |
| InteractionDelegates.h | ModularInteractionSystem | `Delegates/ModularInteractionSystem/InteractionDelegates.h` | OnInteractionStarted, OnInteractionEnded |
| CraftingDelegates.h | CraftingPlugin | `Delegates/CraftingDelegates/CraftingDelegates.h` | OnCraftingStarted, OnCraftingComplete |
| SimulatorDelegates.h | SimulatorFramework | `Delegates/SimulatorFramework/SimulatorDelegates.h` | OnDeviceStateChanged, OnMiniGameEnded |
| SaveDelegates.h | ModularSaveGameSystem | `Delegates/ModularSaveGameSystem/SaveDelegates.h` | OnSaveRequested, OnLoadComplete |
| SpawnDelegates.h | ModularSpawnSystem | `Delegates/ModularSpawnSystem/SpawnDelegates.h` | OnActorSpawned, OnActorDespawned |
| GameplayEventDelegates.h | ModularQuestSystem | `Delegates/ModularQuestSystem/GameplayEventDelegates.h` | OnGameplayEvent, OnObjectiveUpdated |
| WW_WidgetDelegates.h | AdvancedWidgetFramework | `Delegates/AdvancedWidgetFramework/WW_WidgetDelegates.h` | OnWidgetShown, OnWidgetHidden |

---

## 📋 DATA STRUCT REGISTRY

All data structs live in `SharedDefaults/Public/Lib/Data/<Category>/`.

| Data File | Category | Include Path | Key Structs |
|-----------|----------|--------------|-------------|
| InventoryData.h | ModularInventorySystem | `Lib/Data/ModularInventorySystem/InventoryData.h` | FInventorySlot, FItemInstance |
| InteractionData.h | ModularInteractionSystem | `Lib/Data/ModularInteractionSystem/InteractionData.h` | FInteractionData |
| InteractionPredictionState.h | ModularInteractionSystem | `Lib/Data/ModularInteractionSystem/InteractionPredictionState.h` | FInteractionPredictionState |
| CraftingData.h | ModularCraftingData | `Lib/Data/ModularCraftingData/CraftingData.h` | FRecipeData, FCraftingResult |
| MiniGameData.h | SimulatorFramework | `Lib/Data/SimulatorFramework/MiniGameData.h` | FMiniGameData, FSnapPointData |
| SaveData.h | ModularSaveGameSystem | `Lib/Data/ModularSaveGameSystem/SaveData.h` | FSaveData, FSaveSlotInfo |
| SpawnData.h | ModularSpawnSystem | `Lib/Data/ModularSpawnSystem/SpawnData.h` | FSpawnRequest, FDropTableEntry |
| GameplayEventData.h | ModularQuestSystem | `Lib/Data/ModularQuestSystem/GameplayEventData.h` | FGameplayEventData |
| CameraEvents.h | ModularQuestSystem | `Lib/Data/ModularQuestSystem/CameraEvents.h` | FCameraEventData |
| InputConfigData.h | Core | `Lib/Data/Core/InputConfigData.h` | FInputConfig |
| ObjectiveData.h | Core | `Lib/Data/Core/ObjectiveData.h` | FObjectiveData |
| WorldObjectData.h | Core | `Lib/Data/Core/WorldObjectData.h` | FWorldObjectData |
| WW_Enums.h | Enums | `Lib/Data/Enums/WW_Enums.h` | All operator enums |
| WW_TagLibrary.h | Tags | `Lib/Data/Tags/WW_TagLibrary.h` | Cached GameplayTags |

---

## 🔧 MODULE CREATION PROTOCOL

### When Creating a New Interface

**Step 1: Create Interface File**
```
Location: SharedDefaults/Public/Interfaces/<PluginName>/<InterfaceName>.h
```

**Step 2: Interface Template**
```cpp
// <InterfaceName>.h
#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"  // If using tags
#include "<InterfaceName>.generated.h"

// Forward declarations for structs
struct FMyData;

UINTERFACE(MinimalAPI, Blueprintable)
class U<InterfaceName> : public UInterface
{
    GENERATED_BODY()
};

class SHAREDDEFAULTS_API I<InterfaceName>
{
    GENERATED_BODY()

public:
    // MANDATORY: Type-safe getter (Rule #29)
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "<Category>")
    UActorComponent* Get<System>Component();
    // OR: AActor* Get<System>Actor();
    // OR: UObject* Get<System>Object();

    // Interface functions (< 0.02ms each, Rule #31)
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "<Category>")
    bool DoSomething(FName ID);
};
```

**Step 3: Update Documentation**
1. Add to Interface Registry table in this file
2. Add include path to Standard Include Patterns section
3. Update SharedDefaults directory tree

**Step 4: Commit Message Format**
```
Add I<InterfaceName> interface for <purpose>

- Create SharedDefaults/Interfaces/<Plugin>/<Name>.h
- Add mandatory Get<X>Component() getter
- Update Architecture: Interface Registry, Include Paths
```

---

### When Creating a New Delegate File

**Step 1: Create Delegate File**
```
Location: SharedDefaults/Public/Delegates/<PluginName>/<DelegateName>Delegates.h
```

**Step 2: Delegate Template**
```cpp
// <System>Delegates.h
#pragma once

#include "CoreMinimal.h"

// Forward declarations
struct FMyData;

// Signature: Old, New order (Rule: Delegate Parameter Order)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOn<Event>Changed,
    const FMyData&, OldValue,
    const FMyData&, NewValue);

// Fire AFTER the fact (Rule: Delegate Timing)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOn<Event>Completed,
    bool, bSuccess);
```

**Step 3: Update Documentation**
1. Add to Delegate Registry table in this file
2. Add include path to Standard Include Patterns section

---

### When Creating a New Data Struct File

**Step 1: Create Struct File**
```
Location: SharedDefaults/Public/Lib/Data/<PluginName>/<StructName>Data.h
```

**Step 2: Struct Template**
```cpp
// <System>Data.h
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "<System>Data.generated.h"

// Atomic struct (Layer 0): 3-8 fields, single purpose
USTRUCT(BlueprintType)
struct SHAREDDEFAULTS_API F<Atomic>Config
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Value = 0.f;

    // Only IsValid() allowed in structs (Rule #12)
    bool IsValid() const { return Value > 0.f; }
};

// Composite struct (Layer 1): Combines atomics
USTRUCT(BlueprintType)
struct SHAREDDEFAULTS_API F<Composite>Data
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    F<Atomic>Config Config;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FGameplayTag TypeTag;

    bool IsValid() const { return Config.IsValid() && TypeTag.IsValid(); }
};
```

**Step 3: Update Documentation**
1. Add to Data Struct Registry table in this file
2. Add include path to Standard Include Patterns section

---

### When Creating a New Subsystem

**Step 1: Determine Layer**
- L0.5 (ModularSystemsBase): Shared by 2+ L2 plugins
- L2 (Feature Plugin): Plugin-specific only

**Step 2: Create Subsystem File**
```
L0.5 Location: ModularSystemsBase/Public/Subsystems/<Category>/<SubsystemName>.h
L2 Location: <PluginName>/Public/Subsystems/<SubsystemName>.h
```

**Step 3: Subsystem Template**
```cpp
// <SubsystemName>.h
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"  // or GameInstanceSubsystem
#include "<SubsystemName>.generated.h"

UCLASS()
class <MODULE>_API U<SubsystemName> : public ULocalPlayerSubsystem
{
    GENERATED_BODY()

public:
    // Static accessor pattern
    static U<SubsystemName>* Get(const APlayerController* PC)
    {
        if (!PC) return nullptr;
        return PC->GetLocalPlayer()->GetSubsystem<U<SubsystemName>>();
    }

    // For GameInstanceSubsystem:
    // static U<SubsystemName>* Get(const UObject* WorldContext)
    // {
    //     UGameInstance* GI = UGameplayStatics::GetGameInstance(WorldContext);
    //     return GI ? GI->GetSubsystem<U<SubsystemName>>() : nullptr;
    // }
};
```

**Step 4: Update Documentation**
1. Add to plugin directory tree in Repository Structure
2. Add include path to ModularSystemsBase Subsystems section (if L0.5)

---

### When Creating a New Component

**Step 1: Create Component File**
```
L0.5 Location: ModularSystemsBase/Public/Components/<ComponentName>.h
L2 Location: <PluginName>/Public/Components/<ComponentName>.h
```

**Step 2: Component Template**
```cpp
// <ComponentName>.h
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/UnrealNetwork.h"  // ALWAYS include (Rule #13)
#include "<ComponentName>.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class <MODULE>_API U<ComponentName> : public UActorComponent
{
    GENERATED_BODY()

public:
    U<ComponentName>();

protected:
    virtual void BeginPlay() override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    // Cached subsystem access (Rule #41)
private:
    UPROPERTY()
    TObjectPtr<UWidgetManagerBase> CachedWidgetManager = nullptr;

protected:
    UWidgetManagerBase* GetWidgetManager() const;
};
```

**Step 3: Update Documentation**
1. Add to plugin directory tree in Repository Structure

---

## ⚡ GOLDEN RULES (Complete #1-46)

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

### Subsystem Access Pattern

**41. Cache subsystem references in components** — When a component needs a subsystem (WidgetManagerBase, etc.), cache the reference as a private `TObjectPtr<>` member with a `const` getter. Use `GetSubsystem<>()` in the getter, cache on first access.

```cpp
// PATTERN: Cached subsystem access in component
private:
    UPROPERTY()
    TObjectPtr<UWidgetManagerBase> CachedWidgetManager = nullptr;

protected:
    UWidgetManagerBase* GetWidgetManager() const
    {
        if (CachedWidgetManager) return CachedWidgetManager;

        APlayerController* PC = /* get player controller */;
        if (!PC) return nullptr;

        // Cache for future access
        UMyComponent* MutableThis = const_cast<UMyComponent*>(this);
        MutableThis->CachedWidgetManager = UWidgetManagerBase::Get(PC);
        return CachedWidgetManager;
    }
```

---

### Module Creation Protocol

**42. Every new interface requires documentation update** — When creating an interface: (1) Add to Interface Registry table, (2) Add include path to Standard Include Patterns, (3) Update SharedDefaults directory tree. No interface exists without registry entry.

**43. Every new delegate file requires documentation update** — When creating delegates: (1) Add to Delegate Registry table, (2) Add include path to Standard Include Patterns. Delegate parameter order: always `Old, New`. Fire AFTER the fact.

**44. Every new data struct file requires documentation update** — When creating structs: (1) Add to Data Struct Registry table, (2) Add include path to Standard Include Patterns. Structs have ZERO logic except `IsValid()`.

**45. Every new subsystem/component requires directory tree update** — When creating subsystems or components: (1) Add to plugin directory tree in Repository Structure, (2) Add include path if L0.5 shared module. Follow Module Creation Protocol templates.

---

### Widget Creation

**46. Tiered widget inheritance approach** — Use tiered approach for widget base classes:

| Tier | Widget Type | Inherit From | Example |
|------|-------------|--------------|---------|
| **Tier 1: Modal/Fullscreen** | Menus, dialogs, inventory | `UManagedWidget_Master` | Inventory, pause menu, crafting |
| **Tier 2: HUD Elements** | Persistent UI | `UManagedWidget_Master` | Health bar, minimap, crosshair |
| **Tier 3: Transient** | Short-lived feedback | `UUserWidget` (never managed) | Tooltips, damage numbers, spinners |

**Rationale:**
- Tier 1: Needs ESC-to-close, stack management, category tracking
- Tier 2: MUST use managed for visibility control, show/hide via WidgetManager, consistent API
- Tier 3: Creates overhead without benefit; appear/disappear too fast for registration

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
- Golden Rules #1-46 checked
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

**Documentation:** ✅ Complete with file paths

**Rules:** ✅ 46 Golden Rules (#1-46)

**Plugins:** ✅ 11 plugins mapped

**Files:** ✅ 200+ files documented

---

**END OF WINDWALKER FRAMEWORK ARCHITECTURE V2.13 (REVISED)**
