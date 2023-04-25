// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rocket.generated.h"

UCLASS()
class L230425_API ARocket : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARocket();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnyWhere,BlueprintReadOnly,Category ="Components")
	class UBoxComponent* Box;
	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Components")
	class UProjectileMovementComponent* Movement;
};
