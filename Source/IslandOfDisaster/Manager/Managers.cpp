// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers.h"
#include "UIManager.h"
#include "Kismet/GameplayStatics.h"

UManagers::UManagers() {
	UIManagerClass = UUIManager::StaticClass();
}

UUIManager* UManagers::UI() {
	return UIManagerObject;
}

UManagers* UManagers::Get(const UWorld* World)
{
	auto a = UGameplayStatics::GetGameInstance(World);
	return Cast<UManagers>(UGameplayStatics::GetGameInstance(World));
}

void UManagers::SetPlayer(ACPP_Player* Player)
{
	PlayerObject = Player;
}

ACPP_Player* UManagers::Player()
{
	return PlayerObject;
}

void UManagers::InitManager() {
	if (UIManagerClass->StaticClass()) UIManagerObject = NewObject<UUIManager>(this, UIManagerClass);
	else UIManagerObject = UIManagerClass.GetDefaultObject();
}