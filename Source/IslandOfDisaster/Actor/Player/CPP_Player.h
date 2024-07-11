// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Item/Item.h"
#include "../Item/Inventory.h"
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
	UPROPERTY(EditAnywhere, Category=Input)
	class UInputAction* IA_Drop;
	UPROPERTY(EditAnywhere, Category = Input)
	class UInputAction* IA_SelectItem;

	UPROPERTY(EditAnywhere, Category=Ray)
	float RayLength;

	UPROPERTY(EditAnywhere, Category=Texture)
	TObjectPtr<UTexture2D> NoneItemTexture;
	UPROPERTY(EditAnywhere, Category = Texture)
	TObjectPtr<UTexture2D> SelectedItemBGTexture;
	UPROPERTY(EditAnywhere, Category = Texture)
	TObjectPtr<UTexture2D> NotSelectedItemBGTexture;

	UFUNCTION()
	void Move(const FInputActionValue& Value);
	UFUNCTION()
	void Camera(const FInputActionValue& Value);
	UFUNCTION()
	void PickItem(const FInputActionValue& Value);
	UFUNCTION()
	void DropItem(const FInputActionValue& Value);
	UFUNCTION()
	void SelectItem(const FInputActionValue& Value);

	void ItemCheckRayCast();

	FVector GetForwardVector();

	TObjectPtr<UTexture2D> GetSelectedItemBG();
	TObjectPtr<UTexture2D> GetNotSelectedItemBG();

	TObjectPtr<AInventory> Inventory;

private:
	TObjectPtr<class UCameraComponent> PlayerCamera;
	TObjectPtr<AItem> FocusedItem;

};