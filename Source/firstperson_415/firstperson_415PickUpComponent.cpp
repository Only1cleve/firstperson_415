// Copyright Epic Games, Inc. All Rights Reserved.

#include "firstperson_415PickUpComponent.h"

Ufirstperson_415PickUpComponent::Ufirstperson_415PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void Ufirstperson_415PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &Ufirstperson_415PickUpComponent::OnSphereBeginOverlap);
}

void Ufirstperson_415PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	Afirstperson_415Character* Character = Cast<Afirstperson_415Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
