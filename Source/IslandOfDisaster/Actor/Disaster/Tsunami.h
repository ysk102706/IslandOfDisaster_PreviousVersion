// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Disaster.h"
#include "Tsunami.generated.h"

/**
 * 
 */
UCLASS()
class ISLANDOFDISASTER_API ATsunami : public ADisaster
{
	GENERATED_BODY()
	
public:
	virtual void Effect1() override;
	virtual void Effect2() override;
	virtual void Effect3() override;

};
