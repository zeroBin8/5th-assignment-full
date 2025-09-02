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

	UFUNCTION(BlueprintCallable, Category = "Spawn") //�������Ʈ���� ���� ��������
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

	UPROPERTY(EditAnywhere, Category = "Actor To Spawn") //�������Ʈ���� Ŭ���� ����Ʈ ����â���� 'Actor To Spawn'�̶�� ī�װ����� Ȯ�� ����
		TSubclassOf<AActor> actorToSpawn;

	UPROPERTY(EditAnywhere, Category = "Actor To Spawn") //�������Ʈ���� Ŭ���� ����Ʈ ����â���� 'Actor To Spawn'�̶�� ī�װ����� Ȯ�� ����
		FTransform SpawnLocation;
};
