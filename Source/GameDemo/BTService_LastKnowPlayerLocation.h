// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_LastKnowPlayerLocation.generated.h"

/**
 * 
 */
UCLASS()
class GAMEDEMO_API UBTService_LastKnowPlayerLocation : public UBTService_BlackboardBase
{
	GENERATED_BODY()


public:

	UBTService_LastKnowPlayerLocation();

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};
