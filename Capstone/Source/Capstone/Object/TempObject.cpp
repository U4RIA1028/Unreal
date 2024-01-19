// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/TempObject.h"

ATempObject::ATempObject()
{
	
}

void ATempObject::BeginPlay()
{
	Super::BeginPlay();
}

void ATempObject::Init()
{
	ObjectInfo->set_object_type(Protocol::ObjectType::OBJECT_DOOR);

	Super::Init();
}

void ATempObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
