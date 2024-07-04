// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerInfoUI.generated.h"

/**
 * 
 */
UCLASS()
class ISLANDOFDISASTER_API UPlayerInfoUI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetHP(float MaxHP, float CurHP);
	void SetHunger(float MaxHunger, float CurHunger);
	void SetThirsty(float MaxThirsty, float CurThirsty);
	void SetTemperature(float MaxTemperature, float CurTemperature);
	void SetHumidity(float MaxHumidity, float CurHumidity);

private:
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HPBar;
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HungerBar;
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* ThirstyBar;
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* TemperatureBar;
	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HumidityBar;

};
