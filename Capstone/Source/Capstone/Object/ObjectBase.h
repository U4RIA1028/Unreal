// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Protocol.pb.h"
#include "Enum.pb.h"
#include "ObjectBase.generated.h"

UCLASS()
class CAPSTONE_API AObjectBase : public AActor, public TSharedFromThis<AObjectBase>
{
	GENERATED_BODY()

	friend class ACapstoneMyPlayer;
public:
	// Sets default values for this actor's properties
	AObjectBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Init
	virtual void Init();

	void SetMoveInfo();

	UFUNCTION(BlueprintCallable)
	virtual bool OnClicked(class ACapstoneMyPlayer* Player) { return true; }

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	class Protocol::ObjectInfo* ObjectInfo;
	class Protocol::MoveInfo* MoveInfo;

public:
	UPROPERTY(EditAnywhere)
	int ObjectId = 0;
};
