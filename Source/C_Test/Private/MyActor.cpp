// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	X_Location = 0;
	Y_Location = 0;

	AMyActor::SetActorLocation(FVector(X_Location, Y_Location, 0));

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("Initial Position: (%d,%d)"), X_Location, Y_Location); //�ʱ� ��ġ (0,0) ���

	for (int32 i = 0; i < 10; ++i)
	{
		move(); // �̵�

		evtCount += createEvent();
	}

	UE_LOG(LogTemp, Warning, TEXT("Total Distance: %f, Event Count: %d"), totalDistance, evtCount);

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::move()
{
	FVector CurLocation(X_Location, Y_Location, 0);
	
	X_Location += step();  //x ��ǥ �̵�
	Y_Location += step();  //y ��ǥ �̵�

	AMyActor::SetActorLocation(FVector(X_Location, Y_Location, 0));

	float distance = Distance(CurLocation, FVector(X_Location, Y_Location, 0)); //�̵� �Ÿ�
	totalDistance += distance; //�� �̵��Ÿ�
	
	UE_LOG(LogTemp, Warning, TEXT("(%d,%d) Distance: %f"), X_Location, Y_Location, distance); //x y ��ǥ ���
}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::Distance(FVector curLocation, FVector NewLocation)
{
	return FVector::Dist(curLocation, NewLocation); //�� ���� ������ �Ÿ�
}

int32 AMyActor::createEvent()
{
	if (FMath::RandRange(0, 1)) //50% Ȯ���� ���� -> 1�� ������ true
	{
		UE_LOG(LogTemp, Warning, TEXT("Random Event!"));
		
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("50% Event!")); //ȭ�� ���� �� �α� â�� ���
		}

		spawnActor(); //�̺�Ʈ �߻��� ���� ����

		return 1;
	}
	else
	{
		return 0;
	}
	
}

void AMyActor::spawnActor() //���� ���� �Լ�
{
	FActorSpawnParameters spawnPara;
	spawnPara.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn; //���� ������ �ݸ��� ����
	
	GetWorld()->SpawnActor<AActor>(actorToSpawn, SpawnLocation, spawnPara); //���� ���� ���� �ڵ�
}