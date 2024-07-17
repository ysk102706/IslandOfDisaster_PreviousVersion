// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Managers.generated.h"

class UUIManager; 
class UDataLoadManager;
class ACPP_Player;

/**
 * 
 */
UCLASS()
class ISLANDOFDISASTER_API UManagers : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UManagers();
	void InitManager();
	
	UUIManager* UI();
	UDataLoadManager* DataLoad();

	void SetPlayer(ACPP_Player* Player);
	ACPP_Player* Player();

	static UManagers* Get(const UWorld* World);

private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUIManager> UIManagerClass;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UDataLoadManager> DataLoadManagerClass;
	
	TObjectPtr<UUIManager> UIManagerObject;
	TObjectPtr<UDataLoadManager> DataLoadManagerObject;
	TObjectPtr<ACPP_Player> PlayerObject;

};
