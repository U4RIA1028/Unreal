// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ObjectBase.h"
#include "ItemObjectBase.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_API AItemObjectBase : public AObjectBase
{
	GENERATED_BODY()

public:
	AItemObjectBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Init
	virtual void Init();

	void SetMoveInfo();

	virtual bool OnClicked(class ACapstoneMyPlayer* Player) override { return true; }

private:
	TObjectPtr<class CapstonePlayer> Owner = nullptr;
};
