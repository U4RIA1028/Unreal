// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ObjectBase.h"
#include "NormalButton.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_API ANormalButton : public AObjectBase
{
	GENERATED_BODY()
	
public:
	ANormalButton();

protected:
	virtual void BeginPlay() override;

	virtual void Init() override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ButtonMesh;
};
