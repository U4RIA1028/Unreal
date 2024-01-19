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

	/* //�÷��̾� �� �޾ƿ��� �ڵ�
	MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (!MyCharacter)
	{
		// ó���� ���� �߰�
		return;
	}

	PlayerCamera = MyCharacter->FindComponentByClass<UCameraComponent>();
	if (!PlayerCamera)
	{
		// ó���� ���� �߰�
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

	/* �տ� ��ġ�ϵ��� �ϴ� �ڵ�(3��Ī�϶�)
	if (bHolding && HoldingComp)
	{
		SetActorLocationAndRotation(HoldingComp->GetComponentLocation(), HoldingComp->GetComponentRotation());
	}
	*/
}

void APickupObject::PickupObject()
{
	//�߷�, �浹 ����
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

	/* e 2��° ������ �� ������ �ϴ� �ڵ�
	if (!bHolding)
	{
		ForwardVector = PlayerCamera->GetForwardVector();
		Key->AddForce(ForwardVector * 100000 * Key->GetMass());
	}
	*/
}