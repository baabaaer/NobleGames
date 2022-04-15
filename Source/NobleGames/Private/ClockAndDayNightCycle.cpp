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

	//hoursOfDay = sunSpeed / 15 ;
	//minutesOfDay = ((sunSpeed * 15) - hoursOfDay) * 60;
	if (light) 
	{
		light->AddActorLocalRotation(FRotator((sunSpeed), 0, 0));
		yawOfLight = light->GetActorRotation().Yaw;
		pitchOfLight = light->GetActorRotation().Pitch;
		absYawOfLight = abs(yawOfLight);

		if (pitchOfLight < 0) {
			if (absYawOfLight == 180 ) 
			{
				rotCircleDeg = abs(pitchOfLight);
			}
			else 
			{
				rotCircleDeg = 180 + pitchOfLight;
			}

		}
		else if (pitchOfLight >= 0) {
			if(absYawOfLight == 180)
			{
				rotCircleDeg = 360 - pitchOfLight;
			}
			else
			{
				rotCircleDeg = 180 + pitchOfLight;
			}
		}

		
		
		if (sunSpeed >= 360) {
			sunSpeed = 0;
			numbersOfDay++;
		}
	}
	if (sun) {
		FOutputDeviceNull ar;
		sun->CallFunctionByNameWithArguments(TEXT("Update Sun Direction"), ar, NULL, true);
	}

	
}