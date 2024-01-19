// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/Door/LockDoor.h"
#include "Object/Key/ItemKey.h"
#include "CapstoneMyPlayer.h"

ALockDoor::ALockDoor()
{
    bIsLocked = true;

    //ValueKeyType = AItemKey::StaticClass();
}

void ALockDoor::Init()
{
    ObjectInfo->set_object_type(Protocol::ObjectType::OBJECT_DOOR);

    Super::Init();
}


bool ALockDoor::OnClicked(class ACapstoneMyPlayer* Player)
{
    UE_LOG(LogTemp, Warning, TEXT("LockDoor Interact!"));

    if (bIsLocked)
    {
        // 플레이어가 필요한 열쇠 또는 기타 조건을 갖추었는지 확인
        if (Player->GetKeyCount() > 0 /*Player의 KeyCount가 0이 아닐때 조건 추가 */)
        {
            // 문을 열기
            bIsLocked = false;
            UE_LOG(LogTemp, Warning, TEXT("LockDoorOpen"));
            Player->SetKeyCount(0);
            Player->RoomCount();
            UE_LOG(LogTemp, Warning, TEXT("KeyCount %d"), Player->GetKeyCount());
            Super::OnClicked(Player); // 기본 클래스 구현을 호출하여 문을 열거나 닫습니다.
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("You need a Key"));
        }
    }
    else
    {
        // 문이 잠겨 있지 않으면 기본 동작 진행
        Super::OnClicked(Player);
    }

    return true;
}
