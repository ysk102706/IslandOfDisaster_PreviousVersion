// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.h"
#include "Inventory.generated.h"

UCLASS()
class ISLANDOFDISASTER_API AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	AInventory();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	TObjectPtr<AItem> GetItem(int Idx);
	bool AddItem(TObjectPtr<AItem> Item);
	void DropItem();
	void SelectItem(int Idx);

	void SetWorld(UWorld* PlayerWorld);
	void SetNoneItemTexture(UTexture2D* Texture);


private:
	UWorld* World;

	TArray<TObjectPtr<AItem>> Contents[7];
	int SelectedItemIdx;

	TObjectPtr<UTexture2D> NoneItemTexture;

};
