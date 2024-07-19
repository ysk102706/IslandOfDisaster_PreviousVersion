// Fill out your copyright notice in the Description page of Project Settings.


#include "DisasterManager.h"
#include "Kismet/GameplayStatics.h"
#include "../Actor/Player/CPP_PlayerState.h"

void UDisasterManager::Effect1()
{
	switch (Type) {
	case DisasterType::Tsunami:

		break;
	case DisasterType::Volcano:
		break;
	case DisasterType::Epidemic:
		break;
	case DisasterType::Asteroid:
		break;
	case DisasterType::Typhoon:
		break;
	}
}

void UDisasterManager::Effect2()
{
	switch (Type) {
	case DisasterType::Tsunami:
		break;
	case DisasterType::Volcano:
		Cast<ACPP_PlayerState>(UGameplayStatics::GetPlayerState(GetWorld(), 0))->ChangeAdditionalTemperature();
		break;
	case DisasterType::Epidemic:
		break;
	case DisasterType::Asteroid:
		break;
	case DisasterType::Typhoon:
		Cast<ACPP_PlayerState>(UGameplayStatics::GetPlayerState(GetWorld(), 0))->ChangeAdditionalHumidity();
		break;
	}
}

void UDisasterManager::Effect3()
{
	switch (Type) {
	case DisasterType::Tsunami:
		break;
	case DisasterType::Volcano:
		break;
	case DisasterType::Epidemic:
		break;
	case DisasterType::Asteroid:
		break;
	case DisasterType::Typhoon:
		break;
	}
}
