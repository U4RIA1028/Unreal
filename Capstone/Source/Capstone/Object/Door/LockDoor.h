// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorObject.h"
//#include "../Key/ItemKey.h"
#include "LockDoor.generated.h"

class AItemKey;
/**
 *
 */
UCLASS()
class CAPSTONE_API ALockDoor : public ADoorObject
{
	GENERATED_BODY()

public:

	ALockDoor();

	UPROPERTY(EditAnywhere)
	TSubclassOf<AItemKey> ValueKeyType;

protected:

	virtual void Init() override;

	virtual bool OnClicked(class ACapstoneMyPlayer* Player) override;


private:

	bool bIsLocked;
};
