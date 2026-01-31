// PC.cpp - FIXED VERSION with proper inheritance
#include "PC.h"

// ============================================================================
// CONSTRUCTOR
// ============================================================================

APC::APC()
{
	// Parent constructor (AInteractableActor_Master) already handles:
	// - Creating CollisionComponent (SphereComponent)
	// - Creating StaticMeshComponent (for PC mesh - use this instead of SM_GFX!)
	// - Creating SkeletalMeshComponent
	// - Creating InteractableComponent
	// - Creating InventoryComponent (if bHasInventory)
	// - Setting up collision responses
	// - Configuring component attachments
	// - Initializing asset loading system
	
	// ========================================
	// PC-SPECIFIC COMPONENT: Camera
	// ========================================
	// Only create components that are PC-specific (not inherited from parent)
	Camera_ControllerView = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera_ControllerView"));
	Camera_ControllerView->SetupAttachment(RootComponent);
	Camera_ControllerView->SetActive(false);
	
	// ========================================
	// PC-SPECIFIC SETTINGS
	// ========================================
	bIsCurrentlyInteractable = true;
	
	// ========================================
	// REMOVED: SM_GFX creation
	// ========================================
	// DO NOT DO THIS:
	// SM_GFX = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_GFX"));
	// 
	// REASON: Parent already created StaticMeshComponent!
	// 
	// USE THIS INSTEAD:
	// StaticMeshComponent (inherited from parent)
	// 
	// To set the mesh, either:
	// 1. Set ItemDataTable + ItemID in editor (recommended - automatic loading)
	// 2. Manually set: StaticMeshComponent->SetStaticMesh(YourMesh);
}

// ============================================================================
// LIFECYCLE
// ============================================================================

void APC::BeginPlay()
{
	Super::BeginPlay();
	
	// Parent's BeginPlay() already handles:
	// - Hiding preview meshes
	// - Registering with InteractionSubsystem
	// - Caching basic item info from DataTable (if ItemID is set)
	// - Checking for existing player overlaps
	// - Setting up debug system
	// - Loading PC mesh from DataTable (if configured)
	
	// Add any PC-specific initialization here if needed
}

// ============================================================================
// OVERRIDE: PROXIMITY HANDLING
// ============================================================================

void APC::OnPlayerNearbyInit_Implementation(APawn* PlayerPawn, const bool bIsNearby)
{
	// When computer interface is active, prevent asset unloading
	if (!bIsNearby && bIsComputerOn)
	{
		UDebugSubsystem* DebugSys = GetDebugSubsystem();
		if (DebugSys)
		{
			UDebugSubsystem::PrintDebug(
				this,
				FGameplayTag::RequestGameplayTag(FName("Debug.Interaction")),
				TEXT("Prevented asset unload - computer interface is active"),
				false
			);
		}
		return;
	}
	
	// Call parent implementation for normal proximity handling
	Super::OnPlayerNearbyInit_Implementation(PlayerPawn, bIsNearby);
}

// ============================================================================
// INTERACTION IMPLEMENTATION
// ============================================================================

void APC::OnInteract_Implementation(AController* InstigatorController)
{
	// Call parent's interaction logic first
	// This handles:
	// - Logging the interaction
	// - Calling InteractableComponent->OnInteract()
	// - Any other base interaction behavior
	Super::OnInteract_Implementation(InstigatorController);
	
	// Add PC-specific interaction behavior
	if (InstigatorController)
	{
		OnOpenComputerInterface(InstigatorController);
	}
}

// ============================================================================
// PC-SPECIFIC FUNCTIONS
// ============================================================================

void APC::OnOpenComputerInterface(AController* User)
{
	bIsComputerOn = true;
	
	// Log to LogInventoryInteractableSystem
	UE_LOG(LogInventoryInteractableSystem, Log, TEXT("Interacted with pc, setting up new camera and applying widget pc screen..."));
	
	// Switch camera to PC view
	if (Camera_ControllerView && User)
	{
		if (APlayerController* PC = Cast<APlayerController>(User))
		{
			PC->SetViewTargetWithBlend(this, 0.5f);
		}
	}
	
	// Debug logging using inherited GetDebugSubsystem() method
	// This method is protected in parent, so we can access it here
	UDebugSubsystem* DebugSys = GetDebugSubsystem();
	if (DebugSys)
	{
		// Note: Using the static PrintDebug method
		UDebugSubsystem::PrintDebug(
			this,
			FGameplayTag::RequestGameplayTag(FName("Debug.Interaction")),
			TEXT("Computer interface opened"),
			false
		);
	}
}

void APC::OnCloseComputerInterface()
{
	bIsComputerOn = false;
	
	// Add any cleanup logic here
	// For example: Stop any animations, clear UI, etc.
}

void APC::RequestCloseDesktopUI()
{
	// Close the computer interface
	OnCloseComputerInterface();
	
	// Return camera to player
	APawn* PlayerPawn = nullptr;
	if (UWorld* World = GetWorld())
	{
		if (APlayerController* PC = World->GetFirstPlayerController())
		{
			PlayerPawn = PC->GetPawn();
			if (PlayerPawn)
			{
				PC->SetViewTargetWithBlend(PlayerPawn, 0.5f);
			}
		}
	}
	
	// Re-check proximity after closing to ensure proper asset management
	if (PlayerPawn)
	{
		// Calculate distance to determine if player is still nearby
		float Distance = FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
		float LoadDistance = GetGlobalLoadDistance();
		
		bool bStillNearby = Distance <= LoadDistance;
		
		// Update proximity state properly
		OnPlayerNearbyInit_Implementation(PlayerPawn, bStillNearby);
		
		UDebugSubsystem* DebugSys = GetDebugSubsystem();
		if (DebugSys)
		{
			UDebugSubsystem::PrintDebug(
				this,
				FGameplayTag::RequestGameplayTag(FName("Debug.Interaction")),
				FString::Printf(TEXT("Computer closed - Distance: %.1f, LoadDistance: %.1f, StillNearby: %s"), 
					Distance, LoadDistance, bStillNearby ? TEXT("true") : TEXT("false")),
				false
			);
		}
	}
	
	// Debug logging
	UDebugSubsystem* DebugSys = GetDebugSubsystem();
	if (DebugSys)
	{
		UDebugSubsystem::PrintDebug(
			this,
			FGameplayTag::RequestGameplayTag(FName("Debug.Interaction")),
			TEXT("Computer interface closed"),
			false
		);
	}
}

// ============================================================================
// NOTES ON INHERITED FUNCTIONALITY
// ============================================================================

/*
 * MESH HANDLING:
 * 
 * The parent class (AInteractableActor_Master) already provides StaticMeshComponent.
 * You have several options for setting the PC mesh:
 * 
 * OPTION 1 (RECOMMENDED): Use DataTable with proximity loading
 * --------------------------------------------------------------
 * 1. Create/use an ItemDataTable (FItemData rows)
 * 2. Add a row for your PC (e.g., ItemID = "PC_Desktop")
 * 3. Set Soft_SM_Mesh to your PC static mesh
 * 4. In editor, set this actor's:
 *    - ItemDataTable = YourDataTable
 *    - ItemID = "PC_Desktop"
 * 5. Mesh loads automatically when player approaches!
 * 6. Mesh unloads when player leaves (memory optimization)
 * 
 * OPTION 2: Manual mesh assignment in BeginPlay
 * ----------------------------------------------
 * void APC::BeginPlay()
 * {
 *     Super::BeginPlay();
 *     
 *     // Load mesh manually
 *     UStaticMesh* PCMesh = LoadObject<UStaticMesh>(nullptr, TEXT("/Game/Path/To/PC_Mesh"));
 *     if (PCMesh && StaticMeshComponent)
 *     {
 *         StaticMeshComponent->SetStaticMesh(PCMesh);
 *         StaticMeshComponent->SetVisibility(true);
 *     }
 * }
 * 
 * OPTION 3: Set in Blueprint
 * ---------------------------
 * Create Blueprint from APC class, set StaticMeshComponent's mesh in editor.
 * 
 * 
 * COLLISION HANDLING:
 * 
 * The parent already created CollisionComponent (USphereComponent).
 * It's configured for:
 * - Overlap detection with Pawns
 * - Interaction radius
 * - Already registered with InteractionSubsystem
 * 
 * You don't need to set up collision - it's already working!
 * 
 * 
 * INTERACTION FLOW:
 * 
 * 1. Player approaches PC
 * 2. CollisionComponent detects overlap
 * 3. Parent calls OnPlayerNearbyInit_Implementation(true)
 * 4. Parent loads assets from DataTable (if configured)
 * 5. Parent applies mesh to StaticMeshComponent
 * 6. Player presses interact button
 * 7. Parent calls OnInteract_Implementation()
 * 8. This class's OnInteract_Implementation() executes:
 *    - Calls Super::OnInteract_Implementation() (parent logic)
 *    - Calls OnOpenComputerInterface() (PC-specific logic)
 * 9. Camera switches to PC view
 * 10. UI shows (handled by your widget)
 * 
 * 
 * ASSET LOADING:
 * 
 * If you use the DataTable approach (Option 1), the parent automatically:
 * - Loads PC mesh when player is nearby (async, non-blocking)
 * - Applies mesh to StaticMeshComponent
 * - Manages visibility
 * - Unloads when player leaves (saves memory)
 * - Handles all error cases
 * - Provides debug logging
 * 
 * You don't need to write any loading code!
 */