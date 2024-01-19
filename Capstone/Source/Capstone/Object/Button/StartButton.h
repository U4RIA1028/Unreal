// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ObjectBase.h"
#include "StartButton.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_API AStartButton : public AObjectBase
{
	GENERATED_BODY()

public:
	AStartButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Init
	virtual void Init() override;

	virtual bool OnClicked(class ACapstoneMyPlayer* Player) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool bIsClicked = false;
};