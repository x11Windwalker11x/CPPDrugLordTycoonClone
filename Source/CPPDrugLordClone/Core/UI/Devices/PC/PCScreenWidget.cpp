// #include "PCScreenWidget.h"
// #include "PCScreenSlot.h"
// #include "PCScreenWidget.h"
// #include "Components/GridPanel.h"
// #include "Components/Button.h"
// #include "Components/TextBlock.h"
//
// void UPCScreenWidget::NativeConstruct()
// {
//     Super::NativeConstruct();
//
//     SetVisibility(ESlateVisibility::Visible);
//     SetIsFocusable(true);
//     bIsFocusable = true;
//
//     // Bind Start button
//     if (Button)
//     {
//         Button->OnClicked.AddDynamic(this, &UPCScreenWidget::OnStartButtonClicked);
//     }
//
//     DesktopSlots.Empty();
//     CurrentlySelectedSlot = nullptr;
//
//     UE_LOG(LogTemp, Log, TEXT("PC Desktop Widget Constructed"));
// }
//
// void UPCScreenWidget::NativeDestruct()
// {
//     DesktopSlots.Empty();
//     Super::NativeDestruct();
// }
//
// FReply UPCScreenWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
// {
//     if (InKeyEvent.GetKey() == EKeys::Escape)
//     {
//         UE_LOG(LogTemp, Log, TEXT("ESC pressed - Closing PC"));
//         RequestClose();
//         return FReply::Handled();
//     }
//
//     return Super::NativeOnKeyDown(InGeometry, InKeyEvent);
// }
//
// FReply UPCScreenWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
// {
//     if (InMouseEvent.GetEffectingButton() == EKeys::LeftMouseButton)
//     {
//         UE_LOG(LogTemp, Verbose, TEXT("Empty desktop clicked - deselecting all"));
//         DeselectAllSlots();
//         return FReply::Handled();
//     }
//
//     return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
// }
//
// void UPCScreenWidget::InitializeDesktop(AInteractivePC* InOwningPC)
// {
//     OwningPC = InOwningPC;
//     UE_LOG(LogTemp, Log, TEXT("Desktop initialized"));
// }
//
// void UPCScreenWidget::AddDesktopIcon(FText DisplayName, UTexture2D* IconTexture, FName ApplicationID)
// {
//     if (!PCScreenSlotClass || !GridPanel_Icons)
//     {
//         UE_LOG(LogTemp, Error, TEXT("Cannot add icon - missing class or grid panel"));
//         return;
//     }
//
//     UPCScreenSlot* NewSlot = CreateWidget<UPCScreenSlot>(this, PCScreenSlotClass);
//     if (NewSlot)
//     {
//         NewSlot->SetIconData(DisplayName, IconTexture, ApplicationID);
//         NewSlot->OnSlotClicked.AddDynamic(this, &UPCScreenWidget::OnSlotClicked);
//         NewSlot->OnSlotDoubleClicked.AddDynamic(this, &UPCScreenWidget::OnSlotDoubleClicked);
//
//         // Add to grid (4 icons per row)
//         int32 NumSlots = DesktopSlots.Num();
//         int32 Column = NumSlots % 4;
//         int32 Row = NumSlots / 4;
//
//         GridPanel_Icons->AddChildToGrid(NewSlot, Row, Column);
//         DesktopSlots.Add(NewSlot);
//
//         UE_LOG(LogTemp, Log, TEXT("Added icon: %s at [%d,%d]"), *DisplayName.ToString(), Row, Column);
//     }
// }
//
// void UPCScreenWidget::DeselectAllSlots()
// {
//     for (UPCScreenSlot* Slot : DesktopSlots)
//     {
//         if (Slot && Slot->bIsSelected)
//         {
//             Slot->SetSelected(false);
//         }
//     }
//     CurrentlySelectedSlot = nullptr;
// }
//
// void UPCScreenWidget::OnSlotClicked(UPCScreenSlot* ClickedSlot)
// {
//     if (!ClickedSlot) return;
//
//     UE_LOG(LogTemp, Log, TEXT("Slot clicked: %s"), *ClickedSlot->DisplayName.ToString());
//
//     // Deselect all other slots
//     for (UPCScreenSlot* Slot : DesktopSlots)
//     {
//         if (Slot && Slot != ClickedSlot && Slot->bIsSelected)
//         {
//             Slot->SetSelected(false);
//         }
//     }
//
//     CurrentlySelectedSlot = ClickedSlot->bIsSelected ? ClickedSlot : nullptr;
// }
//
// void UPCScreenWidget::OnSlotDoubleClicked(UPCScreenSlot* DoubleClickedSlot)
// {
//     if (!DoubleClickedSlot) return;
//
//     UE_LOG(LogTemp, Warning, TEXT("Double-clicked: %s (ID: %s)"), 
//         *DoubleClickedSlot->DisplayName.ToString(),
//         *DoubleClickedSlot->ApplicationID.ToString());
//
//     // TODO: Open application (will implement later)
// }
//
// void UPCScreenWidget::OnStartButtonClicked()
// {
//     UE_LOG(LogTemp, Log, TEXT("Start button clicked"));
//     // TODO: Start menu
// }
//
// void UPCScreenWidget::RequestClose()
// {
//     if (OwningPC)
//     {
//         OwningPC->RequestCloseDesktopUI();
//     }
//     else
//     {
//         UE_LOG(LogTemp, Error, TEXT("Cannot close - OwningPC is null"));
//     }
// }