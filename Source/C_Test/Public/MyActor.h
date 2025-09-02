// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class C_TEST_API AMyActor : public AActor
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties
	AMyActor();

	int32 X_Location;
	int32 Y_Location;
	float totalDistance;
	int32 evtCount;

	UFUNCTION(BlueprintCallable, Category = "Spawn") //블루프린트에서 노드로 생성가능
		void spawnActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void move();
	int32 step();

	float Distance(FVector curLocation, FVector NewLocation);
	int32 createEvent();

	UPROPERTY(EditAnywhere, Category = "Actor To Spawn") //블루프린트에서 클래스 디폴트 설정창에서 'Actor To Spawn'이라는 카테고리에서 확인 가능
		TSubclassOf<AActor> actorToSpawn;

	UPROPERTY(EditAnywhere, Category = "Actor To Spawn") //블루프린트에서 클래스 디폴트 설정창에서 'Actor To Spawn'이라는 카테고리에서 확인 가능
		FTransform SpawnLocation;
};
