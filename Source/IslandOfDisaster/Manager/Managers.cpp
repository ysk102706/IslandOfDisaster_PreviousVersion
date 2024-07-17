// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers.h"
#include "UIManager.h"
#include "DataLoadManager.h"
#include "Kismet/GameplayStatics.h"

#define InifManager(Type) \
	if (Type##ManagerClass->StaticClass()) Type##ManagerObject = NewObject<U##Type##Manager>(this, Type##ManagerClass);\
	else Type##ManagerObject = Type##ManagerClass.GetDefaultObject();\

UManagers::UManagers() {
	UIManagerClass = UUIManager::StaticClass();
	DataLoadManagerClass = UDataLoadManager::StaticClass();
}

UUIManager* UManagers::UI() {
	return UIManagerObject;
}

UDataLoadManager* UManagers::DataLoad()
{
	return DataLoadManagerObject;
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
	InifManager(UI);
	InifManager(DataLoad);

}