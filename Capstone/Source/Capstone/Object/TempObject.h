// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ObjectBase.h"
#include "TempObject.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_API ATempObject : public AObjectBase
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ATempObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Init
	virtual void Init() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
