// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ItemObjectBase.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "ItemKey.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_API AItemKey : public AItemObjectBase
{
	GENERATED_BODY()
public:
	AItemKey();

	virtual bool OnClicked(class ACapstoneMyPlayer* Player) override { return true; }

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Mesh")
	class UStaticMesh* DefaultMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Key;

	UPROPERTY(EditAnywhere)
	USceneComponent* HoldingComp;

	UFUNCTION()
	void Pickup();

	bool bHolding;
	bool bGravity;

	FRotator ControlRotation;
	ACharacter* MyCharacter;
	UCameraComponent* PlayerCamera;
	FVector ForwardVector;
};
