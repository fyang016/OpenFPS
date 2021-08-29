// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class TDMTEST_API UMyCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_UCLASS_BODY()
	
	class FSavedMove_FPSCharacter : public FSavedMove_Character
	{
	public:

		typedef FSavedMove_Character Super;

		virtual bool CanCombineWith(const FSavedMovePtr& NewMove, ACharacter* Character, float MaxDelta) const override;
		virtual void Clear() override;
		virtual uint8 GetCompressedFlags() const override;
		virtual void SetMoveFor(ACharacter* Character, float InDeltaTime, FVector const& NewAccel, class FNetworkPredictionData_Client_Character& ClientData) override;
		virtual void PrepMoveFor(class ACharacter* Character) override;

		//Walk Speed Update
		uint8 bSavedRequestMaxWalkSpeedChange : 1;

		//Dodge
		FVector SavedMoveDirection;
		uint8 bSavedWantsToDodge : 1;
	};

	class FNetworkPredictionData_Client_FPSCharacter : public FNetworkPredictionData_Client_Character
	{
	public:
		FNetworkPredictionData_Client_FPSCharacter(const UCharacterMovementComponent& ClientMovement);

		typedef FNetworkPredictionData_Client_Character Super;

		virtual FSavedMovePtr AllocateNewMove() override;
	};

public:

	virtual void UpdateFromCompressedFlags(uint8 Flags) override;
	virtual class FNetworkPredictionData_Client* GetPredictionData_Client() const override;
	void OnMovementUpdated(float DeltaTime, const FVector& OldLocation, const FVector& OldVelocity);


	
	//////// Set Max Walk Speed
	uint8 bRequestMaxWalkSpeedChange : 1;

	UFUNCTION(Unreliable, Server, WithValidation)
	void Server_SetMaxWalkSpeed(const float NewMaxWalkSpeed);

	float MyNewMaxWalkSpeed;

	//Set Max Walk Speed (Called from the owning client)
	UFUNCTION(BlueprintCallable, Category = "Max Walk Speed")
	void SetMaxWalkSpeed(float NewMaxWalkSpeed);

	///////
};
