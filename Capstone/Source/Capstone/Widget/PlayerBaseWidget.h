// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerBaseWidget.generated.h"

class UTextBlock;
class UImage;
/**
 * 
 */
UCLASS()
class CAPSTONE_API UPlayerBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPlayerBaseWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeOnInitialized() override;

	void Init();

	void FindActorVisible(bool IsFind);

	friend class ACapstoneMyPlayer;

private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayerNameText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* RoomIdText;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* FindActorText;

	UPROPERTY(meta = (BindWidget))
	UImage* PointImage;
};
