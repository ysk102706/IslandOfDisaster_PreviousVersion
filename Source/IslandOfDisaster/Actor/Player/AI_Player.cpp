// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Player.h"

UAI_Player::UAI_Player()
{
	IsWalk = false;
}

void UAI_Player::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (auto* player = GetOwningActor()) {
		IsWalk = (bool)player->GetVelocity().Length();
	}
}
