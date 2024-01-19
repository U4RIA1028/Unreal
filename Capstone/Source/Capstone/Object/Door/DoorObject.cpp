// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Door/DoorObject.h"
#include "CapstoneMyPlayer.h"
#include "Capstone.h"

ADoorObject::ADoorObject()
{
	PrimaryActorTick.bCanEverTick = true;

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	Box->SetupAttachment(RootComponent);
	Door->SetupAttachment(Box);

	Door->SetCollisionProfileName(TEXT("BlockAll"));
	Box->SetCollisionProfileName(TEXT("Trigger"));

	bIsClosed = true;
}

void ADoorObject::BeginPlay()
{
	Super::BeginPlay();

	if (DoorTimelineFloatCurve)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindDynamic(this, &ADoorObject::OpenDoor);
		Timeline.AddInterpFloat(DoorTimelineFloatCurve, TimelineProgress);
	}
}

void ADoorObject::Init()
{
	ObjectInfo->set_object_type(Protocol::ObjectType::OBJECT_DOOR);

	Super::Init();
}

void ADoorObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timeline.TickTimeline(DeltaTime);
}

void ADoorObject::OpenDoor(float Value)
{
	FRotator DoorNewRotation = FRotator(0.0f, Value, 0.f);
	Door->SetRelativeRotation(DoorNewRotation);
}

bool ADoorObject::OnClicked(class ACapstoneMyPlayer* Player)
{
	OpenClosedDoor(bIsClosed);
	//SendPacket(Player->GetPlayerInfo()->object_id());

	bIsClosed = !bIsClosed;
	return true;
}

void ADoorObject::OpenClosedDoor(bool IsClosed)
{
	UE_LOG(LogTemp, Warning, TEXT("Interact!"));

	if (IsClosed)
	{
		UE_LOG(LogTemp, Warning, TEXT("Open!"));
		Timeline.Play();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Close!"));
		Timeline.Reverse();
	}
}

void ADoorObject::SendPacket(const uint64 PlayerId)
{
	Protocol::C_PLAYER_ACTION PlayerAction;
	PlayerAction.set_action_type(Protocol::ActionType::DOOR_OPEN);
	PlayerAction.set_player_id(PlayerId);
	PlayerAction.set_object_id(ObjectId);
	PlayerAction.set_is_open_door(bIsClosed);

	SEND_PACKET(PlayerAction);
}