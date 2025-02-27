// Copyright Maanav Rao 2020

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDING_ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void OpenDoor(float DeltaTime);
	void CloseDoor(float DeltaTime);
	float TotalMassOfActors() const;
	void FindAudio();
	void PressurePlateCheck();
	
	// Tracks whether the sound has been played
	bool OpenDoorSoundPlayed = false;
	bool CloseDoorSoundPlayed = true;

private:
	float InitialYaw;
	float CurrentYaw;
	
	UPROPERTY(EditAnywhere)
	float MassToOpenDoor = 65.f;

	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;

	float DoorLastOpened = 0;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = .5f;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate = nullptr;

	UPROPERTY()
	UAudioComponent* AudioComponent = nullptr;
};
