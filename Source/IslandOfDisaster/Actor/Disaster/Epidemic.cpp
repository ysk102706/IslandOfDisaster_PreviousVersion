// Fill out your copyright notice in the Description page of Project Settings.


#include "Epidemic.h"

void AEpidemic::Effect1()
{
	Super::Effect1();

	if (IsChangeDay) 1;
}

void AEpidemic::Effect2()
{
	if (IsChangeDay) 1;
}

void AEpidemic::Effect3()
{
	if (!(Hours % 48)) 1;

	IsChangeDay = false;
}
