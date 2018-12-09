// Fill out your copyright notice in the Description page of Project Settings.

#include "DONTHUGME.h"
#include "Frustrum.h"


// Sets default values for this component's properties
UFrustrum::UFrustrum()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFrustrum::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFrustrum::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}


bool UFrustrum::IsInFrustum(AActor* Actor)
{
	ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	if (LocalPlayer != nullptr && LocalPlayer->ViewportClient != nullptr && LocalPlayer->ViewportClient->Viewport)
	{
		FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
			LocalPlayer->ViewportClient->Viewport,
			GetWorld()->Scene,
			LocalPlayer->ViewportClient->EngineShowFlags)
			.SetRealtimeUpdate(true));

		FVector ViewLocation;
		FRotator ViewRotation;
		FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, ViewLocation, ViewRotation, LocalPlayer->ViewportClient->Viewport);
		if (SceneView != nullptr)
		{
			return SceneView->ViewFrustum.IntersectSphere(
				Actor->GetActorLocation(), Actor->GetSimpleCollisionRadius());
		}
	}

	return false;
}

