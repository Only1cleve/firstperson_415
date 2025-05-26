// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "firstperson_415Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraSystem;

UCLASS(config = Game)
class Afirstperson_415Projectile : public AActor
{
	GENERATED_BODY()

public:
	Afirstperson_415Projectile();

protected:
	virtual void BeginPlay() override;

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category = "Projectile")
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(EditAnywhere, Category = "Visual")
	UStaticMeshComponent* ballMesh;

	UPROPERTY()
	FLinearColor randColor;

	UPROPERTY()
	UMaterialInstanceDynamic* dmiMat;

public:
	UPROPERTY(EditAnywhere, Category = "Effects")
	UNiagaraSystem* colorP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInterface* projMat;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Decal")
	UMaterialInterface* baseMat;

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject */
	USphereComponent* GetCollisionComp() const { return CollisionComp; }

	/** Returns ProjectileMovement subobject */
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};
