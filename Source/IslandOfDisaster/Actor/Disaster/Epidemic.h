// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Disaster.h"
#include "Epidemic.generated.h"

class UMaterialInstanceDynamic;

/**
 * 
 */
UCLASS()
class ISLANDOFDISASTER_API AEpidemic : public ADisaster
{
	GENERATED_BODY()
	
public:
	virtual void Effect1() override;
	virtual void Effect2() override;
	virtual void Effect3() override;

	TObjectPtr<UMaterialInstanceDynamic> DynamicMaterial;

};
