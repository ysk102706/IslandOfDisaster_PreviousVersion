// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIManager.generated.h"

UENUM(BlueprintType)
enum class WidgetType : uint8 {
	PlayerInfo      UMETA(DisplayName="PlayerInfo")
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ISLANDOFDISASTER_API UUIManager : public UObject
{
	GENERATED_BODY()
	
public:
	UUserWidget* GetWidget(WidgetType Type);
	void ShowWidget(WidgetType Type);
	void HideWidget(WidgetType Type);

	UPROPERTY(EditAnywhere, Category=Widget)
	TSubclassOf<class UPlayerInfoUI> PlayerInfoWidget;

	TObjectPtr<UUserWidget> PlayerInfoObject;

};
