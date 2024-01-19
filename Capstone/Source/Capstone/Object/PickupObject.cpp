// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/PickupObject.h"
#include "GameFramework/Character.h"

APickupObject::APickupObject()
{
	PrimaryActorTick.bCanEverTick = true;

	Object = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key"));
	Object->SetSimulatePhysics(true);
	RootComponent = Object;

	bHolding = false;
	bGravity = true;
}

void APickupObject::BeginPlay()
{
	Super::BeginPlay();

	/* //플레이어 값 받아오는 코드
	MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (!MyCharacter)
	{
		// 처리할 내용 추가
		return;
	}

	PlayerCamera = MyCharacter->FindComponentByClass<UCameraComponent>();
	if (!PlayerCamera)
	{
		// 처리할 내용 추가
		return;
	}

	TArray<USceneComponent*> Components;

	MyCharacter->GetComponents(Components);

	if (Components.Num() > 0)
	{
		for (auto& Comp : Components)
		{
			if (Comp->GetName() == "HoldingComponent")
			{
				HoldingComp = Cast<UStaticMeshComponent>(Comp);
			}
		}
	}
	*/
}

void APickupObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* 손에 위치하도록 하는 코드(3인칭일때)
	if (bHolding && HoldingComp)
	{
		SetActorLocationAndRotation(HoldingComp->GetComponentLocation(), HoldingComp->GetComponentRotation());
	}
	*/
}

void APickupObject::PickupObject()
{
	//중력, 충돌 설정
	bHolding = !bHolding;
	bGravity = !bGravity;
	if (!bHolding)
	{
		Object->SetEnableGravity(bGravity);
		Object->SetSimulatePhysics(true);
		Object->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);
	}
	else
	{
		Object->SetEnableGravity(bGravity);
		Object->SetSimulatePhysics(false);
	}

	//Destroy();

	/* e 2번째 눌렀을 때 던지게 하는 코드
	if (!bHolding)
	{
		ForwardVector = PlayerCamera->GetForwardVector();
		Key->AddForce(ForwardVector * 100000 * Key->GetMass());
	}
	*/
}