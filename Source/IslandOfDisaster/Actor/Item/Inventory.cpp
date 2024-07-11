// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"
#include "Item.h"
#include "../../Manager/Managers.h"
#include "../../Manager/UIManager.h"
#include "../Player/CPP_Player.h"
#include "../../UI/PlayerInfoUI.h"

AInventory::AInventory()
{
	PrimaryActorTick.bCanEverTick = true;

	for (int i = 0; i < 7; i++) Contents[i].Add(nullptr);
}

void AInventory::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TObjectPtr<AItem> AInventory::GetItem(int Idx)
{
	return Contents[Idx][0];
}

bool AInventory::AddItem(TObjectPtr<AItem> Item)
{
	for (int i = 0; i < 7; i++) {
		if (Contents[i][0]) {
			if (Contents[i][0]->Name == Item->Name) {
				Contents[i].Add(Item);
				if (auto Widget = Cast<UPlayerInfoUI>(UManagers::Get(World)->UI()->GetWidget(EWidgetType::PlayerInfo))) {
					Widget->ChangeInventoryItemCnt(i, FString::Printf(TEXT("%d"), Contents[i].Num()));
				}
				return true;
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		if (!Contents[i][0]) {
			Contents[i][0] = Item;
			if (auto Widget = Cast<UPlayerInfoUI>(UManagers::Get(World)->UI()->GetWidget(EWidgetType::PlayerInfo))) {
				Widget->ChangeInventoryItemTexture(i, Item->Texture);
				Widget->ChangeInventoryItemCnt(i, "1");
			}
			return true;
		}
	}
	return false;
}

void AInventory::DropItem()
{
	if (Contents[SelectedItemIdx][0]) {
		Contents[SelectedItemIdx][0]->Droped();
		Contents[SelectedItemIdx].RemoveAt(0);
		auto Widget = Cast<UPlayerInfoUI>(UManagers::Get(World)->UI()->GetWidget(EWidgetType::PlayerInfo));
		if (Widget) Widget->ChangeInventoryItemCnt(SelectedItemIdx, !Contents[SelectedItemIdx].Num() ? "" : FString::Printf(TEXT("%d"), Contents[SelectedItemIdx].Num()));
		if (!Contents[SelectedItemIdx].Num()) {
			Contents[SelectedItemIdx].Add(nullptr);
			if (Widget) Widget->ChangeInventoryItemTexture(SelectedItemIdx, NoneItemTexture);
		}
	}
}

void AInventory::SelectItem(int Idx)
{
	if (auto Widget = Cast<UPlayerInfoUI>(UManagers::Get(World)->UI()->GetWidget(EWidgetType::PlayerInfo))) {
		Widget->ChangeInventorySelectItem(SelectedItemIdx, Idx);
	}
	
	SelectedItemIdx = Idx;
}

void AInventory::SetWorld(UWorld* PlayerWorld)
{
	World = PlayerWorld;
}

void AInventory::SetNoneItemTexture(UTexture2D* Texture)
{
	NoneItemTexture = Texture;
}
