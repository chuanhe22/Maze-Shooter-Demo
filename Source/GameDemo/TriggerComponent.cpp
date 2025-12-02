// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (MoverActor)
	{
		MoveWall = MoverActor->GetComponentByClass<UMoveWall>();
		if (MoveWall)
		{
			UE_LOG(LogTemp, Display, TEXT("MoveWall component found in TriggerComponent"));

		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("MoveWall component not found in MoverActor in TriggerComponent"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MoverActor is not set in TriggerComponent"));
	}

	if (IsPressurePlate)
	{
		UE_LOG(LogTemp, Display, TEXT("TriggerComponent is set as Pressure Plate"));
		OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
		OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
	}
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::Trigger(bool NewTriggerValue)
{
	IsTriggered = NewTriggerValue;
	if (MoveWall)
	{

		MoveWall->SetShouldMove(IsTriggered);
	}
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		ActivatedCount++;

		if (!IsTriggered)
		{

			Trigger(true);
		}


	}
	
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		ActivatedCount--;

		if (IsTriggered && (ActivatedCount == 0))
		{

			Trigger(false);

		}

	}
	
}
