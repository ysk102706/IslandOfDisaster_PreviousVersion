// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Disaster.generated.h"

UCLASS()
class ISLANDOFDISASTER_API ADisaster : public AActor
{
	GENERATED_BODY()
	
public:	
	ADisaster();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	int Random(int MinInclusive, int MaxInclusive);

	virtual void Effect1() {
		Hours++; 
		if (!(Hours % 24)) { IsChangeDay = true; }
	};
	virtual void Effect2() {};
	virtual void Effect3() {};

protected:
	int Hours;
	bool IsChangeDay;

};
