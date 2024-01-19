// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectBase.h"
#include "Capstone.h"
#include "struct.pb.h"

// Sets default values
AObjectBase::AObjectBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectInfo = new Protocol::ObjectInfo;
	MoveInfo = ObjectInfo->mutable_move_info();
}

// Called when the game starts or when spawned
void AObjectBase::BeginPlay()
{
	Super::BeginPlay();

#if UE_BUILD_DEBUG + UE_BUILD_DEVELOPMENT + UE_BUILD_TEST + UE_BUILD_SHIPPING >= 1
	Init();
	if (UCapstoneGameInstance* GameInstance = Cast<UCapstoneGameInstance>(GWorld->GetGameInstance()))
	{
		GameInstance->SetObject(this);
	}

#endif
}

void AObjectBase::Init()
{
	// Protocol¸¸ Á¤ÇÏ¸é µÊ
	// ObjectInfo->set_object_type(Protocol::ObjectType::~~);
	ObjectInfo->set_object_id(ObjectId);
	SetMoveInfo();
}

void AObjectBase::SetMoveInfo()
{
	FVector Location = GetActorLocation();

	MoveInfo->set_x(Location.X);
	MoveInfo->set_y(Location.Y);
	MoveInfo->set_z(Location.Z);
	MoveInfo->set_yaw(GetActorRotation().Yaw);
}

// Called every frame
void AObjectBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

