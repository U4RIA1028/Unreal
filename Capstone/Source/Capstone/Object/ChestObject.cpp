// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ChestObject.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AChestObject::AChestObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    // Create the static mesh component
    UStaticMeshComponent* StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TargetMesh"));
    RootComponent = StaticMeshComponent;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/SICKA_mansion/StaticMeshes/SM_TillFrame_Double.SM_TillFrame_Double"));
    if (MeshAsset.Succeeded())
    {
        DefaultMesh = MeshAsset.Object;
        StaticMeshComponent->SetStaticMesh(DefaultMesh);
    }
}

// Called when the game starts or when spawned
void AChestObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChestObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChestObject::ChangeStaticMesh()
{

}
