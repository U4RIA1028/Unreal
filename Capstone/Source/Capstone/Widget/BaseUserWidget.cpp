// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/BaseUserWidget.h"
#include "CapstoneGameInstance.h"
#include <Components/TextBlock.h>
#include <Components/EditableTextBox.h>
#include <Components/Button.h>
#include <Components/CanvasPanel.h>

UBaseUserWidget::UBaseUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

void UBaseUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Init();
}

void UBaseUserWidget::Init()
{
	PlayerNameTextBox->SetHintText(FText::FromString("Input Player Name"));
	RoomIdTextBox->SetHintText(FText::FromString("Input Room ID"));

	StartButtonText->SetText(FText::FromString("Start Button"));
	InsideButtonText->SetText(FText::FromString("Inside Button"));
	CreateButtonText->SetText(FText::FromString("Create Button"));
	BackToTheMainButtonText->SetText(FText::FromString("Back To the Main"));

	if (StartGameButton)
		StartGameButton->OnClicked.AddDynamic(this, &UBaseUserWidget::OnStartGameButtonClicked);

	if (InsideGameButton)
		InsideGameButton->OnClicked.AddDynamic(this, &UBaseUserWidget::OnInsideButtonClicked);

	if (CreateGameButton)
		CreateGameButton->OnClicked.AddDynamic(this, &UBaseUserWidget::OnCreateGameButtonClicked);

	if (BackToTheMainButton)
		BackToTheMainButton->OnClicked.AddDynamic(this, &UBaseUserWidget::OnBackToTheMainButtonClicked);
}

void UBaseUserWidget::OnStartGameButtonClicked()
{
	if (UCapstoneGameInstance* Instance = Cast<UCapstoneGameInstance>(GetWorld()->GetGameInstance()))
	{
		FString InputName = PlayerNameTextBox->GetText().ToString();
		if (InputName.IsEmpty())
			return;

		if (IsCreateGame)
		{
			Instance->CreateToGameRoom(InputName);
		}
		else
		{
			FString InputRoomId = RoomIdTextBox->GetText().ToString();
			if (InputRoomId.IsEmpty())
				return;

			Instance->InsideToGameRoom(InputName, InputRoomId);
		}
	}
}

void UBaseUserWidget::OnInsideButtonClicked()
{
	ModePanel->SetVisibility(ESlateVisibility::Hidden);
	InputPanel->SetVisibility(ESlateVisibility::Visible);
	RoomIdTextBox->SetVisibility(ESlateVisibility::Visible);
	IsCreateGame = false;
}

void UBaseUserWidget::OnCreateGameButtonClicked()
{
	ModePanel->SetVisibility(ESlateVisibility::Hidden);
	InputPanel->SetVisibility(ESlateVisibility::Visible);
	RoomIdTextBox->SetVisibility(ESlateVisibility::Hidden);
	IsCreateGame = true;
}

void UBaseUserWidget::OnBackToTheMainButtonClicked()
{
	ModePanel->SetVisibility(ESlateVisibility::Visible);
	InputPanel->SetVisibility(ESlateVisibility::Hidden);
}
