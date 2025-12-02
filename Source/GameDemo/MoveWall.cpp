// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveWall.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMoveWall::UMoveWall()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveWall::BeginPlay()
{
	Super::BeginPlay();

	// ...
	AActor* MyOwner = GetOwner();

	StartLocation = MyOwner->GetActorLocation();

	SetShouldMove(false);
	
}


// Called every frame
void UMoveWall::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	FVector CurrentLocation = GetOwner()->GetActorLocation();

	ReachedTarget = CurrentLocation.Equals(TargetLocation);

	

	if (!ReachedTarget)
	{
		FVector NewLocation;

		float Speed = MoveOffset.Length() / MoveTime;

		NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);

		GetOwner()->SetActorLocation(NewLocation);
	}

	
}

void UMoveWall::SetShouldMove(bool NewShouldMove)
{
	ShouldMove = NewShouldMove;

	if (ShouldMove)
	{
		//TargetLocation is equal to StartLocation add MoveOffset
		TargetLocation = StartLocation + MoveOffset;
	}
	else
	{
		//TargetLocation is equal to StartLocation
		TargetLocation = StartLocation;
	}
}

bool UMoveWall::GetShouldMove()
{
	return ShouldMove;
}

