// Fill out your copyright notice in the Description page of Project Settings.


#include "Disaster.h"
#include <random>

ADisaster::ADisaster()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ADisaster::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADisaster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int ADisaster::Random(int MinInclusive, int MaxInclusive)
{
	std::random_device random;
	std::mt19937 engine(random());
	std::uniform_int_distribution<int> distribution(MinInclusive, MaxInclusive);
	return distribution(engine);
}