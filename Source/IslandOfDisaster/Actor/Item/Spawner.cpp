// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner.h"
#include "../../Manager/Managers.h"
#include "../../Manager/DataLoadManager.h"
#include "Item.h"

void ASpawner::Spawn()
{
	if (!IsSpawned) {
		SpawnedItem = UManagers::Get(GetWorld())->DataLoad()->SpawnItemActor(GetWorld(), Id);
		SpawnedItem->SetActorLocation(GetActorLocation());
		SpawnedItem->SetWorldLocation(GetActorLocation());
		SpawnedItem->Spawner = this;
		IsSpawned = true;
	}
}
