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
	void Init(UTexture2D* ItemTexture, FString ItemName, FString ItemDescription, int ManufactureCount, bool IsItemErection, bool IsItemUsable, int ItemDurability, bool IsItemExit);

	
	UPROPERTY(EditAnywhere, Category=Materials)
	class UMaterialInterface* DefaultMaterial;
	UPROPERTY(EditAnywhere, Category = Materials)
	class UMaterialInterface* FocusedMaterial;
	UPROPERTY(EditAnywhere, Category = Materials)
	class UMaterialInterface* ConstructAvailableMaterial;
	UPROPERTY(EditAnywhere, Category = Materials)
	class UMaterialInterface* ConstructUnavailableMaterial;

	TObjectPtr<UTexture2D> Texture;

	UPROPERTY(EditAnywhere)
	int Id;

	FString Name;
	FString Description;
	int ManufacturedItemCount;
	bool IsConstruct;
	bool IsUsable;
	int Durability;
	bool IsExit;

	bool Constructed;
	bool IsConstructPoint;

	UPROPERTY(EditAnywhere)
	FString ConstructAvailablePlaceName;

	void Focused();
	void NotFocused();
	bool Picked();
	void Droped();
	void Construct(FVector Pos);
	void ConstructPoint(bool Value);

	void DestroyActor();
	
	void SetPhysics(bool Value);
	void SetWorldLocation(FVector Pos);

private:
	TObjectPtr<UStaticMeshComponent> Mesh;

	bool IsFocused;
	bool IsNotFocused;

	bool IsLoaded;

};
