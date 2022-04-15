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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Clocking")
		float numbersOfDay;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Clocking")
		float hoursOfDay;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Clocking")
		float minutesOfDay;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Clocking")
		float yawOfLight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Clocking")
		float absYawOfLight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Clocking")
		float pitchOfLight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Clocking")
		float rotCircleDeg = 0.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

};
