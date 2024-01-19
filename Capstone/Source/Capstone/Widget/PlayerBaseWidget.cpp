// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/PlayerBaseWidget.h"
#include "CapstoneGameInstance.h"
#include "Components/TextBlock.h"

UPlayerBaseWidget::UPlayerBaseWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UPlayerBaseWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

}

void UPlayerBaseWidget::Init()
{
	if (UCapstoneGameInstance* Instance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance()))
	{
		RoomIdText->SetText(FText::FromString("RoomID : " + Instance->MyRoomId));
		PlayerNameText->SetText(FText::FromString("PlayerName : " + Instance->MyPlayerName));
		FindActorText->SetText(FText::FromString("Use E"));
		FindActorText->SetVisibility(ESlateVisibility::Hidden);
	}
}

void UPlayerBaseWidget::FindActorVisible(bool IsFind)
{
	if (IsFind)
		FindActorText->SetVisibility(ESlateVisibility::Visible);
	else
		FindActorText->SetVisibility(ESlateVisibility::Hidden);
}
