// Fill out your copyright notice in the Description page of Project Settings.


#include "Tsunami.h"

void ATsunami::Effect1()
{
	Super::Effect1();

	if (!(Hours % 48)) 1;
}

void ATsunami::Effect2()
{
	if (!(Hours % 5)) 1;
}

void ATsunami::Effect3()
{
	if (IsChangeDay) 1;

	IsChangeDay = false;
}
