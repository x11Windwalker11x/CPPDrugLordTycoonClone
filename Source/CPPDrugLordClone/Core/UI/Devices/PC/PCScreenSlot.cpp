#include "PCScreenSlot.h"
#include "Components/Border.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "TimerManager.h"
#include "Engine/Texture2D.h"
#include "Logging/InteractableInventoryLogging.h"

void UPCScreenSlot::NativeConstruct()
{
    Super::NativeConstruct();

    // Ensure widget can receive mouse input
    SetVisibility(ESlateVisibility::Visible);

    // Initialize visuals
    UpdateVisuals();

    // Set initial data if provided
    if (IconTexture && Image_Icon)
    {
        Image_Icon->SetBrushFromTexture(IconTexture);
    }

    if (!DisplayName.IsEmpty() && TextBlock_79)
    {
        TextBlock_79->SetText(DisplayName);
    }

    UE_LOG(LogDebugSystem, Log, TEXT("PCScreenSlot constructed: %s"), *DisplayName.ToString());
}

void UPCScreenSlot::NativeDestruct()
{
    // Clean up timer
    if (UWorld* World = GetWorld())
    {
        World->GetTimerManager().ClearTimer(DoubleClickTimer);
    }

    Super::NativeDestruct();
}

FReply UPCScreenSlot::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
    {
        bIsPressed = true;
        
        // Visual feedback - blue border on press
        if (Border_Selection)
        {
            Border_Selection->SetBrushColor(SelectedBorderColor);
        }

        UE_LOG(LogDebugSystem, Log, TEXT("Mouse down on: %s"), *DisplayName.ToString());
        return FReply::Handled();
    }

    return FReply::Unhandled();
}

FReply UPCScreenSlot::NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
    {
        bIsPressed = false;

        ClickCount++;

        if (ClickCount == 1)
        {
            // Start timer for double-click detection
            if (UWorld* World = GetWorld())
            {
                World->GetTimerManager().SetTimer(
                    DoubleClickTimer,
                    this,
                    &UPCScreenSlot::HandleSingleClick,
                    DoubleClickTimeThreshold,
                    false
                );
            }
        }
        else if (ClickCount >= 2)
        {
            // Double-click detected
            if (UWorld* World = GetWorld())
            {
                World->GetTimerManager().ClearTimer(DoubleClickTimer);
            }
            HandleDoubleClick();
            ClickCount = 0;
        }

        UE_LOG(LogDebugSystem, Log, TEXT("Mouse up on: %s (Clicks: %d)"), *DisplayName.ToString(), ClickCount);
        return FReply::Handled();
    }

    return FReply::Unhandled();
}

FReply UPCScreenSlot::NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
    {
        // Clear pending single-click timer
        if (UWorld* World = GetWorld())
        {
            World->GetTimerManager().ClearTimer(DoubleClickTimer);
        }
        ClickCount = 0;

        HandleDoubleClick();
        return FReply::Handled();
    }

    return FReply::Unhandled();
}

void UPCScreenSlot::NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseEnter(InGeometry, InMouseEvent);

    bIsHovered = true;

    // Show light blue hover effect if not selected
    if (!bIsSelected && Border_Selection)
    {
        Border_Selection->SetBrushColor(HoverBorderColor);
    }

    UE_LOG(LogDebugSystem, Verbose, TEXT("Mouse enter: %s"), *DisplayName.ToString());
}

void UPCScreenSlot::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
    Super::NativeOnMouseLeave(InMouseEvent);

    bIsHovered = false;
    bIsPressed = false;

    // Restore proper color
    UpdateVisuals();

    UE_LOG(LogDebugSystem, Verbose, TEXT("Mouse leave: %s"), *DisplayName.ToString());
}

void UPCScreenSlot::HandleSingleClick()
{
    ClickCount = 0;

    UE_LOG(LogDebugSystem, Log, TEXT("Single-click: %s"), *DisplayName.ToString());

    // Toggle selection
    SetSelected(!bIsSelected);

    // Broadcast event
    OnSlotClicked.Broadcast(this);
}

void UPCScreenSlot::HandleDoubleClick()
{
    UE_LOG(LogDebugSystem, Warning, TEXT("Double-click - Opening: %s (ID: %s)"), 
        *DisplayName.ToString(), 
        *ApplicationID.ToString());

    // Broadcast double-click event
    OnSlotDoubleClicked.Broadcast(this);

    // TODO: Open application (will be implemented later)
}

void UPCScreenSlot::SetIconData(FText InDisplayName, UTexture2D* InIconTexture, FName InApplicationID)
{
    DisplayName = InDisplayName;
    IconTexture = InIconTexture;
    ApplicationID = InApplicationID;

    if (TextBlock_79)
    {
        TextBlock_79->SetText(DisplayName);
    }

    if (Image_Icon && IconTexture)
    {
        Image_Icon->SetBrushFromTexture(IconTexture);
    }

    UE_LOG(LogDebugSystem, Log, TEXT("Icon data set: %s"), *DisplayName.ToString());
}

void UPCScreenSlot::SetSelected(bool bInSelected)
{
    bIsSelected = bInSelected;
    UpdateVisuals();
}

void UPCScreenSlot::UpdateVisuals()
{
    if (!Border_Selection)
    {
        return;
    }

    FLinearColor TargetColor;

    if (bIsSelected)
    {
        TargetColor = SelectedBorderColor; // Blue
    }
    else if (bIsHovered)
    {
        TargetColor = HoverBorderColor; // Light blue
    }
    else
    {
        TargetColor = NormalBorderColor; // Transparent
    }

    Border_Selection->SetBrushColor(TargetColor);
}
