// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DisasterManager.generated.h"

UENUM(BlueprintType)
enum DisasterType {
	Tsunami		UMETA(DisplayName="Tsunami"),
	Volcano		UMETA(DisplayName="Volcano"),
	Epidemic	UMETA(DisplayName="Epidemic"),
	Asteroid	UMETA(DisplayName="Asteroid"),
	Typhoon		UMETA(DisplayName="Typhoon"),
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ISLANDOFDISASTER_API UDisasterManager : public UObject
{
	GENERATED_BODY()
	
public:
	DisasterType Type;

	void Effect1();
	void Effect2();
	void Effect3();

};
