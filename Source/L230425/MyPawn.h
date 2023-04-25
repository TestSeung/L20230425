// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

class UPropellerComponent;
class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;
class UArrowComponent;
class UStaticMeshComponent;

UCLASS()
class L230425_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//블루프린트에서 이 변수를 사용하겠다.
	//디테일패널 볼 수있다
	//전제조건 퍼블릭
	//컴포넌트는 쓰기로 하면 안됨
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,Category = "Components")
	UBoxComponent* Box;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category ="Components")
	UStaticMeshComponent* Body;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UPropellerComponent* Right;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UPropellerComponent* Left;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UArrowComponent* Arrow;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UFloatingPawnMovement* Movement;

};
