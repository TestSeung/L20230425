// Fill out your copyright notice in the Description page of Project Settings.


#include "PropellerComponent.h"
#include "Kismet/GameplayStatics.h"
//컴포넌트는 틱설정을하고 컴포넌트틱을 활성화시켜줘야한다.

//CDO초기화
UPropellerComponent::UPropellerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UPropellerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	AddLocalRotation(FRotator(0, 0, 3600.0f * UGameplayStatics::GetWorldDeltaSeconds(GetWorld())));
}

