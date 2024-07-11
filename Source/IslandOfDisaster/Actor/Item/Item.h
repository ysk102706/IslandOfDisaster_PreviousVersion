// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UENUM(BlueprintType)
enum class EItem : uint8 {
	Temp	UMETA(DisplayName="Temp")
};

UCLASS()
class ISLANDOFDISASTER_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = Info)
	FString Name;
	UPROPERTY(EditAnywhere, Category=Info)
	FString Description;
	
	UPROPERTY(EditAnywhere, Category=Materials)
	class UMaterialInterface* DefaultMaterial;
	UPROPERTY(EditAnywhere, Category = Materials)
	class UMaterialInterface* FocusedMaterial;

	UPROPERTY(EditAnywhere, Category = Texture)
	TObjectPtr<UTexture2D> Texture;

	void Focused();
	void NotFocused();
	void Picked();
	void Droped();

private:
	TObjectPtr<UStaticMeshComponent> Mesh;

	bool IsFocused;
	bool IsNotFocused;

};
