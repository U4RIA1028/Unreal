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
			// 원하는 추가적인 설정이 있다면 여기에서 설정
			// 예를 들어, 위치 조정, 속성 설정 등

			NewActor->SetActorLocation(GetActorLocation());
			// 액터를 현재 레벨에 추가
			NewActor->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);

			UE_LOG(LogTemp, Warning, TEXT("Spawn FinalKey"));
			// 혹은 원하는 다른 방식으로 액터를 추가할 수도 있습니다.
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
			// 원하는 추가적인 설정이 있다면 여기에서 설정
			// 예를 들어, 위치 조정, 속성 설정 등
			
			NewActor->SetActorLocation(GetActorLocation());
			// 액터를 현재 레벨에 추가
			NewActor->AttachToActor(this, FAttachmentTransformRules::KeepWorldTransform);
			
			UE_LOG(LogTemp, Warning, TEXT("Spawn Key"));
			// 혹은 원하는 다른 방식으로 액터를 추가할 수도 있습니다.
			/*GetWorld()->SpawnActorDeferred<AItemKey>(AItemKey::StaticClass(), FTransform());
			NewActor->FinishSpawning(FTransform());*/
			count++;
		}
	}
	else { return true; }
	// 로그 출력
	UE_LOG(LogTemp, Warning, TEXT("Button Clicked"));
	return true;
}