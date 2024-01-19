// Fill out your copyright notice in the Description page of Project Settings.


#include "StartButton.h"
#include "Capstone.h"
#include "CapstoneMyPlayer.h"

AStartButton::AStartButton()
{
	
}

void AStartButton::BeginPlay()
{
	Super::BeginPlay();
}

void AStartButton::Init()
{
	ObjectInfo->set_object_type(Protocol::ObjectType::OBJECT_IDLE);

	Super::Init();
}

void AStartButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AStartButton::OnClicked(ACapstoneMyPlayer* Player)
{
	UE_LOG(LogTemp, Warning, TEXT("On Button Clicked"));
	
	if (Player->GetPlayerInfo()->is_host())
	{
		Protocol::C_GAME_START StartPkt;
		StartPkt.mutable_host_player()->CopyFrom(*Player->GetPlayerInfo());
		StartPkt.set_stage_number(Protocol::StageNumber::STAGE_ONE);

		SEND_PACKET(StartPkt);
	}

	return true;
}
