// PC.h - FIXED VERSION with proper inheritance
#pragma once

#include "CoreMinimal.h"
#include "ModularInventorySystem/Public/Actors/Interactables/InteractableActor_Master.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Debug/DebugSubsystem.h"
#include "PC.generated.h"

/**
 * PC (Computer) Actor - Interactable computer in the world.
 * Inherits all functionality from AInteractableActor_Master.
 * 
 * INHERITED COMPONENTS (do not redeclare or recreate):
 * - CollisionComponent (USphereComponent*) - Already set up for interaction
 * - StaticMeshComponent (UStaticMeshComponent*) - Use this for PC mesh (renamed from SM_GFX)
 * - SkeletalMeshComponent (USkeletalMeshComponent*) - Available if needed
 * - InteractableComponent (UInteractableComponent*) - Handles interaction logic
 * - InventoryComponent (UInventoryComponent*) - Available if bHasInventory is true
 * 
 * INHERITED ASSET LOADING:
 * - Parent handles all asset loading from DataTable via ItemID
 * - Parent handles proximity-based loading/unloading
 * - Set ItemDataTable and ItemID in editor to load PC mesh automatically
 * 
 * PC-SPECIFIC COMPONENTS:
 * - Camera_ControllerView (UCameraComponent*) - First-person view when using PC
 */
UCLASS(Abstract, Blueprintable)
class CPPDRUGLORDCLONE_API APC : public AInteractableActor_Master
{
	GENERATED_BODY()

public:
	// ============================================================================
	// CONSTRUCTOR & LIFECYCLE
	// ============================================================================
	
	APC();

	virtual void BeginPlay() override;
	
	// ============================================================================
	// INTERACTION OVERRIDE
	// ============================================================================
	
	/**
	 * Override of interaction behavior - opens computer interface.
	 * Parent class handles all asset loading and UI updates.
	 * This adds PC-specific behavior (camera switch, UI).
	 */
	virtual void OnInteract_Implementation(AController* InstigatorController) override;

	/**
	 * Override proximity handling to prevent asset unloading while computer is active.
	 * When the computer interface is open, we don't want to unload assets just because
	 * the player's collision sphere moves away (camera view changed).
	 */
	virtual void OnPlayerNearbyInit_Implementation(APawn* PlayerPawn, bool bIsNearby) override;

	// ============================================================================
	// PC-SPECIFIC COMPONENTS
	// ============================================================================
	
	/**
	 * Camera used for first-person PC view.
	 * This is PC-specific, so we create it here (not inherited).
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	UCameraComponent* Camera_ControllerView;

	// ============================================================================
	// NOTE: StaticMeshComponent is inherited from parent!
	// ============================================================================
	
	/*
	 * IMPORTANT: Do NOT create SM_GFX!
	 * 
	 * Use the inherited StaticMeshComponent instead:
	 * - Already created by parent (AInteractableActor_Master)
	 * - Already attached to RootComponent
	 * - Already configured for collision
	 * - Automatically loaded from DataTable when player approaches
	 * 
	 * To set the PC mesh:
	 * Option 1 (Recommended): Use DataTable
	 *   - Set ItemDataTable and ItemID in editor
	 *   - Add row to DataTable with PC mesh reference
	 *   - Mesh loads automatically on proximity
	 * 
	 * Option 2 (Manual): Access inherited component
	 *   - Use StaticMeshComponent directly (inherited from parent)
	 *   - StaticMeshComponent->SetStaticMesh(YourMesh);
	 * 
	 * DO NOT declare: UStaticMeshComponent* SM_GFX;
	 * INSTEAD USE: StaticMeshComponent (from parent)
	 */

	// ============================================================================
	// UI FUNCTIONS
	// ============================================================================
	
	/**
	 * Called by PCScreenWidget to close the desktop UI.
	 * Closes interface and returns camera to player.
	 */
	UFUNCTION(BlueprintCallable, Category = "UI")
	void RequestCloseDesktopUI();

protected:
	// ============================================================================
	// PC STATE
	// ============================================================================
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC Settings")
	bool bIsComputerOn = false;

	// ============================================================================
	// PC-SPECIFIC FUNCTIONS
	// ============================================================================
	
	/**
	 * Opens the computer interface and switches camera view.
	 */
	void OnOpenComputerInterface(AController* User);
	
	/**
	 * Closes the computer interface.
	 */
	void OnCloseComputerInterface();
};