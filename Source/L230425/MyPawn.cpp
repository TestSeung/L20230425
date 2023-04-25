// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "PropellerComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	//mesh loading
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_P38_Body(TEXT("/Script/Engine.StaticMesh'/Game/P38/Mesh/SM_P38_Body.SM_P38_Body'"));
	//예외처리
	if (SM_P38_Body.Succeeded())
	{
		Body->SetStaticMesh(SM_P38_Body.Object);
	}
	
	Left = CreateDefaultSubobject<UPropellerComponent>(TEXT("Left"));
	Left->SetupAttachment(Body);

	Right = CreateDefaultSubobject<UPropellerComponent>(TEXT("Right"));
	Right->SetupAttachment(Body);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_P38_Propeller(TEXT("/Script/Engine.StaticMesh'/Game/P38/Mesh/SM_P38_Propeller.SM_P38_Propeller'"));
	if (SM_P38_Propeller.Succeeded())
	{
		Left->SetStaticMesh(SM_P38_Propeller.Object);
		Left->AddLocalOffset(FVector(37.5f, -21.0f, 1.17f));
		Right->SetStaticMesh(SM_P38_Propeller.Object);
		Right->AddLocalOffset(FVector(37.5f, 21.0f, 1.17f));
	}

	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	Arrow->SetupAttachment(Box);


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpritngArm"));
	SpringArm->SetupAttachment(Box);
	SpringArm->TargetArmLength = 150.0f;
	//bool
	SpringArm->bEnableCameraLag = true;
	SpringArm->bEnableCameraRotationLag = true;


	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);

	//ActorComponent
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));
	Movement->MaxSpeed = 2000.0f;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//틱마다 앞으로 이동시킴
	AddMovementInput(GetActorForwardVector());
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

