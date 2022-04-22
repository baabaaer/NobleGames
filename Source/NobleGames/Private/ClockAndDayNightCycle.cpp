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
		yawOfLight = light->GetActorRotation().Yaw;
		pitchOfLight = light->GetActorRotation().Pitch;
		absYawOfLight = abs(yawOfLight);

		if (pitchOfLight < 0) {
			
			if(absYawOfLight == 180)
			{
				// Q1
				rotCircleDeg = -pitchOfLight;
			}
			else if (absYawOfLight == 0)
			{
				// Q2
				rotCircleDeg = 180 + pitchOfLight;
			}

		}
		else {
			if (absYawOfLight == 0)
			{
				// Q3
				rotCircleDeg = 180 + pitchOfLight;
			}
			else if(absYawOfLight == 180) 
			{
				// Q4
				rotCircleDeg = 360 - pitchOfLight;
			}
			
		}

		totalSecondsOfDay = rotCircleDeg * 240;
		hoursOfDay = totalSecondsOfDay / 3600;
		minutesOfDay = (totalSecondsOfDay - (hoursOfDay * 3600)) / 60;
		secondsOfDay = totalSecondsOfDay - (hoursOfDay * 3600) - (minutesOfDay * 60);
		if (hoursOfDay == 23 && minutesOfDay == 59 && secondsOfDay == 59)
		{
			numbersOfDay++;
		}

	}
	if (sun) {
		FOutputDeviceNull ar;
		sun->CallFunctionByNameWithArguments(TEXT("Update Sun Direction"), ar, NULL, true);
	}

	
}