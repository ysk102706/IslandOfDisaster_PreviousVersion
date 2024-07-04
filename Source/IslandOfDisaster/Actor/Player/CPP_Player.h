// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Item/Item.h"
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

	UPROPERTY(EditAnywhere, Category=Input)
	class UInputMappingContext* IMC_Default;
	UPROPERTY(EditAnywhere, Category=Input)
	class UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, Category=Input)
	class UInputAction* IA_Camera;
	UPROPERTY(EditAnywhere, Category=Input)
	class UInputAction* IA_Pick;

	UPROPERTY(EditAnywhere, Category = Ray)
	float RayLength;

	UFUNCTION()
	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void Camera(const FInputActionValue& Value);
	UFUNCTION()
	void PickItem(const FInputActionValue& Value);

	UFUNCTION()
	void ItemCheckRayCast();

private:
	TObjectPtr<class UCameraComponent> PlayerCamera;
	
	TObjectPtr<AItem> SelectedItem;

};