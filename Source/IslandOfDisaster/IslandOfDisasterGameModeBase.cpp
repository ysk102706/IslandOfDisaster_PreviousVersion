// Copyright Epic Games, Inc. All Rights Reserved.


#include "IslandOfDisasterGameModeBase.h"
#include "Actor/Player/CPP_Player.h"

AIslandOfDisasterGameModeBase::AIslandOfDisasterGameModeBase()
{
	DefaultPawnClass = ACPP_Player::StaticClass();
}
