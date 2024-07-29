// Fill out your copyright notice in the Description page of Project Settings.


#include "Typhoon.h"
#include "Kismet/GameplayStatics.h"
#include "../Player/CPP_PlayerState.h"

void ATyphoon::Effect1()
{
	Super::Effect1();

	if (!(Hours % 48)) 1;
}

void ATyphoon::Effect2()
{
	if (IsChangeDay) Cast<ACPP_PlayerState>(UGameplayStatics::GetPlayerState(GetWorld(), 0))->ChangeAdditionalHumidity();
}

void ATyphoon::Effect3()
{
	if (IsChangeDay) 1;

	IsChangeDay = false;
}
