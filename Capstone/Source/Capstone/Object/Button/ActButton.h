// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ObjectBase.h"
#include "Key/ItemKey.h"
//#include "Key/FinalKey.h"
#include "ActButton.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_API AActButton : public AObjectBase
{
	GENERATED_BODY()
	
public:
	AActButton();

protected:
	virtual void BeginPlay() override;

	virtual void Init() override;

	virtual bool OnClicked(class ACapstoneMyPlayer* Player) override;

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* ButtonMesh;

	int count;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	bool bIsClicked = false;
};
