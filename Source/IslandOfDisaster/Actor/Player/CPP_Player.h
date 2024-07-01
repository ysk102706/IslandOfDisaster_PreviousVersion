// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPP_Player.generated.h"

UCLASS()
class ISLANDOFDISASTER_API ACPP_Player : public ACharacter
{
	GENERATED_BODY()

public:
	ACPP_Player();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Input
	UPROPERTY(EditAnywhere, Category=Input)
	class UInputMappingContext* IMC_Default;
	UPROPERTY(EditAnywhere, Category=Input)
	class UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, Category=Input)
	class UInputAction* IA_Camera;

	UFUNCTION()
	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void Camera(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=UI)
	TSubclassOf<class UPlayerInfoUI> PlayerInfoUI;

private:
	float CurHP;
	float MaxHP;
	
	float CurHunger;
	float MaxHunger;

	float CurThirsty;
	float MaxThirsty;

	UUserWidget* PlayerInfoWidget;
};