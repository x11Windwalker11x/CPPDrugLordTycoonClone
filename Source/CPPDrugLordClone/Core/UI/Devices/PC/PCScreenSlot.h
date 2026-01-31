#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PCScreenSlot.generated.h"

class UBorder;
class UImage;
class UTextBlock;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPCScreenSlotClicked, class UPCScreenSlot*, ClickedSlot);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPCScreenSlotDoubleClicked, class UPCScreenSlot*, DoubleClickedSlot);

/**
 * Desktop icon/shortcut widget
 * Handles mouse interactions: hover (light blue), click (blue), double-click (open app)
 */
UCLASS()
class CPPDRUGLORDCLONE_API UPCScreenSlot : public UUserWidget
{
    GENERATED_BODY()

public:
    // Lifecycle
    virtual void NativeConstruct() override;
    virtual void NativeDestruct() override;

    // Mouse Events
    virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseButtonUp(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual FReply NativeOnMouseButtonDoubleClick(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
    virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

    // Bind to Blueprint widgets (names MUST match exactly in WBP_PCScreenSlot)
    UPROPERTY(meta = (BindWidget))
    UBorder* Border_Selection;

    UPROPERTY(meta = (BindWidget))
    UImage* Image_Icon;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* TextBlock_79;

    // Icon Data
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon Data")
    FText DisplayName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon Data")
    UTexture2D* IconTexture;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon Data")
    FName ApplicationID;

    // Visual Colors (Windows XP style)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
    FLinearColor NormalBorderColor = FLinearColor(0.0f, 0.0f, 0.0f, 0.0f); // Transparent

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
    FLinearColor HoverBorderColor = FLinearColor(0.314f, 0.549f, 0.784f, 0.3f); // Light blue

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
    FLinearColor SelectedBorderColor = FLinearColor(0.314f, 0.549f, 0.784f, 1.0f); // Blue

    // State
    UPROPERTY(BlueprintReadOnly, Category = "State")
    bool bIsSelected = false;

    UPROPERTY(BlueprintReadOnly, Category = "State")
    bool bIsHovered = false;

    // Events
    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnPCScreenSlotClicked OnSlotClicked;

    UPROPERTY(BlueprintAssignable, Category = "Events")
    FOnPCScreenSlotDoubleClicked OnSlotDoubleClicked;

    // Public Functions
    UFUNCTION(BlueprintCallable, Category = "PCScreenSlot")
    void SetIconData(FText InDisplayName, UTexture2D* InIconTexture, FName InApplicationID);

    UFUNCTION(BlueprintCallable, Category = "PCScreenSlot")
    void SetSelected(bool bInSelected);

    UFUNCTION(BlueprintCallable, Category = "PCScreenSlot")
    void UpdateVisuals();

protected:
    // Internal state for click detection
    bool bIsPressed = false;
    FTimerHandle DoubleClickTimer;
    int32 ClickCount = 0;
    float DoubleClickTimeThreshold = 0.4f;

    void HandleSingleClick();
    void HandleDoubleClick();
};