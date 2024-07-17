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
	ContentMap = new TMap<FString, int>();
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
					(*ContentMap->Find(Item->Name))++;
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
				ContentMap->Add(Item->Name, 1);
			}
			return true;
		}
	}
	return false;
}

void AInventory::DropItem()
{
	auto& item = Contents[SelectedItemIdx];
	if (item[0]) {
		(*ContentMap->Find(item[0]->Name))--;
		if (!*ContentMap->Find(item[0]->Name)) ContentMap->Remove(item[0]->Name);

		item[0]->Droped();
		item.RemoveAt(0);

		SetInventoryUI(SelectedItemIdx, item);
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

void AInventory::SetInventoryUI(int Idx, TArray<TObjectPtr<AItem>>& Items)
{
	auto Widget = Cast<UPlayerInfoUI>(UManagers::Get(World)->UI()->GetWidget(EWidgetType::PlayerInfo));
	if (Widget) Widget->ChangeInventoryItemCnt(Idx, !Items.Num() ? "" : FString::Printf(TEXT("%d"), Items.Num()));
	if (!Items.Num()) {
		Items.Add(nullptr);
		if (Widget) Widget->ChangeInventoryItemTexture(Idx, NoneItemTexture);
	}
}

int32 AInventory::GetItemCount(FString Name)
{
	if (ContentMap->Contains(Name)) return *ContentMap->Find(Name);
	return 0;
}

void AInventory::Consume(FString Name, int Count)
{
	int ItemIdx = 0;

	for (int i = 0; i < 7; i++) {
		if (Contents[i][0] && Contents[i][0]->Name == Name) {
			ItemIdx = i;
			break;
		}
	}

	if (Name == TEXT("도끼") || Name == TEXT("망치") || Name == TEXT("바늘")) {
		Contents[ItemIdx][0]->Durability--;
		if (!Contents[ItemIdx][0]->Durability) Contents[ItemIdx].RemoveAt(0);
	}
	else while (Count--) Contents[ItemIdx].RemoveAt(0);
	(*ContentMap->Find(Name)) = Contents[ItemIdx].Num();
	if (!(*ContentMap->Find(Name))) ContentMap->Remove(Name);

	SetInventoryUI(ItemIdx, Contents[ItemIdx]);
}
