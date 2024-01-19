// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseUserWidget.generated.h"

class UButton;
class UEditableTextBox;
class UTextBlock;
class UCanvasPanel;
/**
 * 
 */
UCLASS()
class CAPSTONE_API UBaseUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UBaseUserWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeOnInitialized() override;

	void Init();

protected:
	UFUNCTION()
	void OnStartGameButtonClicked();

	UFUNCTION()
	void OnInsideButtonClicked();
	
	UFUNCTION()
	void OnCreateGameButtonClicked();

	UFUNCTION()
	void OnBackToTheMainButtonClicked();

private:
	// Panel
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* InputPanel;

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* ModePanel;

	// InputTextBox
	UPROPERTY(meta=(BindWidget))
	UEditableTextBox* PlayerNameTextBox;

	UPROPERTY(meta=(BindWidget))
	UEditableTextBox* RoomIdTextBox;

	// Button
	UPROPERTY(meta=(BindWidget))
	UButton* StartGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* BackToTheMainButton;

	UPROPERTY(meta=(BindWidget))
	UButton* InsideGameButton;

	UPROPERTY(meta=(BindWidget))
	UButton* CreateGameButton;

	// Button Text
	UPROPERTY(meta=(BindWidget))
	UTextBlock* StartButtonText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* BackToTheMainButtonText;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* InsideButtonText;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* CreateButtonText;

private:
	bool IsCreateGame = true;
};
