// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Spawner.generated.h"

class AItem;

UCLASS()
class ISLANDOFDISASTER_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	void Spawn();

	UPROPERTY(EditAnywhere, Category=Item)
	int Id;

	bool IsSpawned;
	TObjectPtr<AItem> SpawnedItem;

};
