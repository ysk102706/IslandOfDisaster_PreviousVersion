// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	Mesh = FindComponentByClass<UStaticMeshComponent>();
	

	NotSelected();
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::Selected()
{
	if (!IsSelected) {
		IsSelected = true;
		IsNotSelected = false;
		
		Mesh->bRenderCustomDepth = true;
		Mesh->SetMaterial(0, SelectedMaterial);
	}
}

void AItem::NotSelected()
{
	if (!IsNotSelected) {
		IsNotSelected = true;
		IsSelected = false;

		Mesh->bRenderCustomDepth = false;
		Mesh->SetMaterial(0, DefaultMaterial);
	}
}

void AItem::Picked()
{
	Destroy();
}