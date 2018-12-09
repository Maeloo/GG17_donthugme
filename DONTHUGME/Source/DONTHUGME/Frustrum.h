// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Frustrum.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DONTHUGME_API UFrustrum : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFrustrum();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

		
	UFUNCTION(BlueprintCallable, Category = "Frustrum")
		bool IsInFrustum(AActor* Actor);

};
