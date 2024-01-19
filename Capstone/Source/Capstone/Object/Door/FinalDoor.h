// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ObjectBase.h"
#include "FinalDoor.generated.h"

/**
 * 
 */
UCLASS()
class CAPSTONE_API AFinalDoor : public AObjectBase
{
	GENERATED_BODY()
	
public:
	AFinalDoor();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void Init() override;

	virtual bool OnClicked(class ACapstoneMyPlayer* Player) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Door;

	void SendPacket(class ACapstoneMyPlayer* Player);
};
