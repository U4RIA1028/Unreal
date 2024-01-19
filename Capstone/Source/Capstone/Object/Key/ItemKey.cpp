// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Key/ItemKey.h"
#include "GameFramework/Character.h"

AItemKey::AItemKey()
{
	PrimaryActorTick.bCanEverTick = true;

	Key = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Key"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/SICKA_mansion/StaticMeshes/SM_Cupcake.SM_Cupcake'"));
	if (MeshAsset.Succeeded())
	{
		DefaultMesh = MeshAsset.Object;
		Key->SetStaticMesh(DefaultMesh);
	}

	Key->SetSimulatePhysics(true);
	RootComponent = Key;

	bHolding = false;
	bGravity = true;
}

void AItemKey::BeginPlay()
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

void AItemKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/* �տ� ��ġ�ϵ��� �ϴ� �ڵ�(3��Ī�϶�)
	if (bHolding && HoldingComp)
	{
		SetActorLocationAndRotation(HoldingComp->GetComponentLocation(), HoldingComp->GetComponentRotation());
	}
	*/
}

void AItemKey::Pickup()
{
	// //�߷�, �浹 ����
	//bHolding = !bHolding;
	//bGravity = !bGravity;
	//if (!bHolding)
	//{
	//	Key->SetEnableGravity(bGravity);
	//	Key->SetSimulatePhysics(true);
	//	Key->SetCollisionEnabled(bHolding ? ECollisionEnabled::NoCollision : ECollisionEnabled::QueryAndPhysics);
	//}
	//else
	//{
	//	Key->SetEnableGravity(bGravity);
	//	Key->SetSimulatePhysics(false);
	//}
	
	Destroy();
	
	/* e 2��° ������ �� ������ �ϴ� �ڵ�
	if (!bHolding)
	{
		ForwardVector = PlayerCamera->GetForwardVector();
		Key->AddForce(ForwardVector * 100000 * Key->GetMass());
	}
	*/
}