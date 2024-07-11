// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "../../Manager/Managers.h"
#include "../Player/CPP_Player.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	Mesh = FindComponentByClass<UStaticMeshComponent>();
	

	NotFocused();
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::Focused()
{
	if (!IsFocused) {
		IsFocused = true;
		IsNotFocused = false;
		
		Mesh->bRenderCustomDepth = true;
		Mesh->SetMaterial(0, FocusedMaterial);
	}
}

void AItem::NotFocused()
{
	if (!IsNotFocused) {
		IsNotFocused = true;
		IsFocused = false;

		Mesh->bRenderCustomDepth = false;
		Mesh->SetMaterial(0, DefaultMaterial);
	}
}

void AItem::Picked()
{
	if (UManagers::Get(GetWorld())->Player()->Inventory->AddItem(this)) {
		SetActorLocation(FVector(0, 0, -100));
		Mesh->SetWorldLocation(FVector(0, 0, -100));
		Mesh->SetSimulatePhysics(false);
	}
}

void AItem::Droped()
{
	auto Player = UManagers::Get(GetWorld())->Player();
	FVector Pos = Player->GetActorLocation() + FVector(0, 0, 60);
	SetActorLocation(Pos);
	Mesh->SetSimulatePhysics(true);
	Mesh->SetWorldLocation(Pos);
	Mesh->AddVelocityChangeImpulseAtLocation(UManagers::Get(GetWorld())->Player()->GetForwardVector() * 500, Pos);
}
