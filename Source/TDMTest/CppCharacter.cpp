// Fill out your copyright notice in the Description page of Project Settings.


#include "CppCharacter.h"
#include "./MyCharacterMovementComponent.h"

// Sets default values
ACppCharacter::ACppCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UMyCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACppCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACppCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACppCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACppCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	MyCharacterMovementComponent = Cast<UMyCharacterMovementComponent>(Super::GetMovementComponent());
}

