// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Button/NormalButton.h"
#include "Kismet/GameplayStatics.h"
#include "Capstone.h"
#include "CapstoneMyPlayer.h"

ANormalButton::ANormalButton()
{
	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh"));

	ButtonMesh->SetupAttachment(RootComponent);
}

void ANormalButton::BeginPlay()
{
	Super::BeginPlay();
}

void ANormalButton::Init()
{
	ObjectInfo->set_object_type(Protocol::ObjectType::OBJECT_IDLE);

	Super::Init();
}