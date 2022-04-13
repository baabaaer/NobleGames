// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/OutputDeviceNull.h"
#include "Engine/DirectionalLight.h"
#include "ClockAndDayNightCycle.generated.h"

UCLASS()
class NOBLEGAMES_API AClockAndDayNightCycle : public AActor
{
	GENERATED_BODY()
	
	
public:	
	// Sets default values for this actor's properties
	AClockAndDayNightCycle();
	
	void MoveTheSunAcrossTheSky(AActor* sun, float sunSpeed, ADirectionalLight* light);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky")
		float sunSpeedAcrossSky;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky")
		ADirectionalLight* lightSource;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sky")
		AActor* sunAcrossSky;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
