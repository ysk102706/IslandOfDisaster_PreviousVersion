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

	void Effect1();
	void Effect2();
	void Effect3();

};
