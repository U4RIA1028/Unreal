// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Key/FinalKey.h"

AFinalKey::AFinalKey()
{

}

void AFinalKey::Init()
{
	ObjectInfo->set_object_type(Protocol::ObjectType::OBJECT_KEY);
}

void AFinalKey::BeginPlay()
{
	Super::BeginPlay();
}

void AFinalKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFinalKey::Pickup()
{
	Destroy();
}