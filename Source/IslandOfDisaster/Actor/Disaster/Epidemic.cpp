// Fill out your copyright notice in the Description page of Project Settings.


#include "Epidemic.h"

void AEpidemic::Effect1()
{
	Super::Effect1();

	if (IsChangeDay) 1;
}

void AEpidemic::Effect2()
{
	if (IsChangeDay) {
	}
}

void AEpidemic::Effect3()
{
	if (!(Hours % 48)) {
		FVector SpawnPos = RottenFishSpawnPos[Random(0, RottenFishSpawnPos.Num() - 1)];
		int SpawnCount = Random(3, 7);

		for (int i = 0; i < SpawnCount; i++) {
			FVector Position = RandomCircle(SpawnPos, 200);
			FRotator Rotation = FRotator(0, Random(0, 360), 0);

			GetWorld()->SpawnActor(RottenFish, &Position, &Rotation);
			GetWorld()->SpawnActor(RottenFish, &Position, &Rotation);
		} 
	}

	IsChangeDay = false;
}
