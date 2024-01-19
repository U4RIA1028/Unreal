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
        // �÷��̾ �ʿ��� ���� �Ǵ� ��Ÿ ������ ���߾����� Ȯ��
        if (Player->GetKeyCount() > 0 /*Player�� KeyCount�� 0�� �ƴҶ� ���� �߰� */)
        {
            // ���� ����
            bIsLocked = false;
            UE_LOG(LogTemp, Warning, TEXT("LockDoorOpen"));
            Player->SetKeyCount(0);
            Player->RoomCount();
            UE_LOG(LogTemp, Warning, TEXT("KeyCount %d"), Player->GetKeyCount());
            Super::OnClicked(Player); // �⺻ Ŭ���� ������ ȣ���Ͽ� ���� ���ų� �ݽ��ϴ�.
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("You need a Key"));
        }
    }
    else
    {
        // ���� ��� ���� ������ �⺻ ���� ����
        Super::OnClicked(Player);
    }

    return true;
}
