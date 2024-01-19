// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NoteBaseWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class CAPSTONE_API UNoteBaseWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UNoteBaseWidget(const FObjectInitializer& ObjectInitializer);

	virtual void NativeOnInitialized() override;

	friend class ACapstoneMyPlayer;


};
