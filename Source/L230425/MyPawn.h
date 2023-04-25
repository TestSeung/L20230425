// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

//#include "InputAction.h"

#include "MyPawn.generated.h"

class UPropellerComponent;
class UBoxComponent;
class USpringArmComponent;
class UCameraComponent;
class UFloatingPawnMovement;
class UArrowComponent;
class UStaticMeshComponent;
struct FInputActionValue;


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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	class UInputAction* FireAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	class UInputAction* PitchRollAction;

	//언리얼 내 함수
	//블루프린트를 할 수 있다.
	//UFUNCTION(BlueprintImplementableEvent,Category = "Custom Spawn")
	//C++과 블루프린트를 둘 다 할수있다/
	UFUNCTION(BlueprintNativeEvent, Category = "Custom Spawn")
	void PostSpawn();
	void PostSpawn_Implementation(void);

	void Fire(const FInputActionValue& Value);

	void PitchRoll(const FInputActionValue& Value);

	//지금은 로켓만 나가던 액터를 변경하여 사용가능하다
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	TSubclassOf<class AActor>Projectile;
};
