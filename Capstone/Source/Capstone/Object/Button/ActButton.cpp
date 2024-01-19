// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Button/ActButton.h"
#include "Kismet/GameplayStatics.h"
#include "Capstone.h"
#include "CapstoneMyPlayer.h"

AActButton::AActButton()
{
	PrimaryActorTick.bCanEverTick = true;

	ButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ButtonMesh"));

	ButtonMesh->SetupAttachment(RootComponent);
	

	count = 0;
}

void AActButton::BeginPlay()
{
	Super::BeginPlay();
}

void AActButton::Init()
{
	ObjectInfo->set_object_type(Protocol::ObjectType::OBJECT_IDLE);

	Super::Init();
}

void AActButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool AActButton::OnClicked(ACapstoneMyPlayer* Player)
{
	if (count == 0 && Player->GetRoomCount() == 2)
	{
		AFinalKey* NewActor = GetWorld()->SpawnActor<AFinalKey>(AFinalKey::StaticClass(), GetActorLocation(), GetActorRotation());
		if (NewActor)
		{
			// ���ϴ� �߰����� ������ �ִٸ� ���⿡�� ����
			// ���� ���, ��ġ ����, �Ӽ� ���� ��

			NewActor->SetActorLocation(GetActorLocation());
			// ���͸� ���� ������ �߰�
			NewActor->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

			UE_LOG(LogTemp, Warning, TEXT("Spawn FinalKey"));
			// Ȥ�� ���ϴ� �ٸ� ������� ���͸� �߰��� ���� �ֽ��ϴ�.
			/*GetWorld()->SpawnActorDeferred<AItemKey>(AItemKey::StaticClass(), FTransform());
			NewActor->FinishSpawning(FTransform());*/
			count++;
		}
	}
	if (count == 0)
	{
		AItemKey* NewActor = GetWorld()->SpawnActor<AItemKey>(AItemKey::StaticClass(), GetActorLocation(), GetActorRotation());
		if (NewActor)
		{
			// ���ϴ� �߰����� ������ �ִٸ� ���⿡�� ����
			// ���� ���, ��ġ ����, �Ӽ� ���� ��
			
			NewActor->SetActorLocation(GetActorLocation());
			// ���͸� ���� ������ �߰�
			NewActor->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			
			UE_LOG(LogTemp, Warning, TEXT("Spawn Key"));
			// Ȥ�� ���ϴ� �ٸ� ������� ���͸� �߰��� ���� �ֽ��ϴ�.
			/*GetWorld()->SpawnActorDeferred<AItemKey>(AItemKey::StaticClass(), FTransform());
			NewActor->FinishSpawning(FTransform());*/
			count++;
		}
	}
	else { return true; }
	// �α� ���
	UE_LOG(LogTemp, Warning, TEXT("Button Clicked"));
	return true;
}