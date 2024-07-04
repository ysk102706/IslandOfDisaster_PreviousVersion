// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInfoUI.h"
#include "Components/ProgressBar.h"

void UPlayerInfoUI::SetHP(float MaxHP, float CurHP) {
	HPBar->SetPercent(CurHP / MaxHP);
}

void UPlayerInfoUI::SetHunger(float MaxHunger, float CurHunger)
{
	HungerBar->SetPercent(CurHunger / MaxHunger);
}

void UPlayerInfoUI::SetThirsty(float MaxThirsty, float CurThirsty)
{
	ThirstyBar->SetPercent(CurThirsty / MaxThirsty);
}

void UPlayerInfoUI::SetTemperature(float MaxTemperature, float CurTemperature)
{
	TemperatureBar->SetPercent(CurTemperature / MaxTemperature);
}

void UPlayerInfoUI::SetHumidity(float MaxHumidity, float CurHumidity)
{
	HumidityBar->SetPercent(CurHumidity / MaxHumidity);
}
