// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveWall.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEDEMO_API UMoveWall : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMoveWall();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FVector StartLocation;
	FVector TargetLocation;

	UPROPERTY(EditAnywhere)
	float MoveTime = 4.0f;

	UPROPERTY(EditAnywhere)
	FVector MoveOffset;

	void SetShouldMove(bool NewShouldMove);
	bool GetShouldMove();

	UPROPERTY(VisibleAnywhere)
	bool ReachedTarget = false;

private:
	UPROPERTY(EditAnywhere)
	bool ShouldMove = false;
};
