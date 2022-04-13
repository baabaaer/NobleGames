// Fill out your copyright notice in the Description page of Project Settings.


#include "ClockAndDayNightCycle.h"

// Sets default values
AClockAndDayNightCycle::AClockAndDayNightCycle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AClockAndDayNightCycle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AClockAndDayNightCycle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	MoveTheSunAcrossTheSky(sunAcrossSky, DeltaTime*sunSpeedAcrossSky, lightSource);
}

void AClockAndDayNightCycle::MoveTheSunAcrossTheSky(AActor* sun, float sunSpeed, ADirectionalLight* light)
{
	if (light) 
	{
		light->AddActorLocalRotation(FRotator((sunSpeed), 0, 0));
		if (sunSpeed == 360) {
			sunSpeed = 0;
		}
	}
	if (sun) {
		FOutputDeviceNull ar;
		sun->CallFunctionByNameWithArguments(TEXT("Update Sun Direction"), ar, NULL, true);
	}
}