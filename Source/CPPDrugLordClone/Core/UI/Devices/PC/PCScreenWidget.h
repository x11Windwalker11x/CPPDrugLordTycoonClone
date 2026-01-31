// #pragma once
//
// #include "CoreMinimal.h"
// #include "Blueprint/UserWidget.h"
// #include "PCScreenWidget.generated.h"
//
// class UGridPanel;
// class UButton;
// class UTextBlock;
// class UPCScreenSlot;
// class AInteractivePC;
//
// /**
//  * Main PC Desktop Widget - Container for desktop icons and taskbar
//  */
// UCLASS()
// class CPPDRUGLORDCLONE_API UPCScreenWidget : public UUserWidget
// {
// 	GENERATED_BODY()
//
// public:
// 	virtual void NativeConstruct() override;
// 	virtual void NativeDestruct() override;
// 	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;
// 	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
// 	virtual bool NativeSupportsKeyboardFocus() const override { return true; }
//
// 	// Bind to Blueprint widgets (names must match exactly in WBP_PCDesktop)
// 	UPROPERTY(meta = (BindWidget))
// 	UGridPanel* GridPanel_Icons;
//
// 	UPROPERTY(meta = (BindWidget))
// 	UButton* Button; // Start button
//
// 	UPROPERTY(meta = (BindWidget))
// 	UTextBlock* Text_0; // Start button text
//
// 	// Settings
// 	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Desktop")
// 	TSubclassOf<UPCScreenSlot> PCScreenSlotClass;
//
// 	// Functions
// 	UFUNCTION(BlueprintCallable, Category = "Desktop")
// 	void InitializeDesktop(AInteractivePC* InOwningPC);
//
// 	UFUNCTION(BlueprintCallable, Category = "Desktop")
// 	void AddDesktopIcon(FText DisplayName, UTexture2D* IconTexture, FName ApplicationID);
//
// 	UFUNCTION(BlueprintCallable, Category = "Desktop")
// 	void DeselectAllSlots();
//
// protected:
// 	UFUNCTION()
// 	void OnStartButtonClicked();
//
// 	UFUNCTION()
// 	void OnSlotClicked(UPCScreenSlot* ClickedSlot);
//
// 	UFUNCTION()
// 	void OnSlotDoubleClicked(UPCScreenSlot* DoubleClickedSlot);
//
// 	void RequestClose();
//
// private:
// 	UPROPERTY()
// 	TArray<UPCScreenSlot*> DesktopSlots;
//
// 	UPROPERTY()
// 	UPCScreenSlot* CurrentlySelectedSlot;
//
// 	UPROPERTY()
// 	AInteractivePC* OwningPC;
// };