// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/Key/ItemKey.h"
#include "FinalKey.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_API AFinalKey : public AItemKey
{
	GENERATED_BODY()
	
public:
	AFinalKey();

protected:
	virtual void Init() override;

	virtual void BeginPlay() override;

	void Pickup();

public:
	virtual void Tick(float DeltaTime) override;
};
