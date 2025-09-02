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

	UE_LOG(LogTemp, Warning, TEXT("Initial Position: (%d,%d)"), X_Location, Y_Location); //초기 위치 (0,0) 출력

	for (int32 i = 0; i < 10; ++i)
	{
		move(); // 이동

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
	
	X_Location += step();  //x 좌표 이동
	Y_Location += step();  //y 좌표 이동

	AMyActor::SetActorLocation(FVector(X_Location, Y_Location, 0));

	float distance = Distance(CurLocation, FVector(X_Location, Y_Location, 0)); //이동 거리
	totalDistance += distance; //총 이동거리
	
	UE_LOG(LogTemp, Warning, TEXT("(%d,%d) Distance: %f"), X_Location, Y_Location, distance); //x y 좌표 출력
}

int32 AMyActor::step()
{
	return FMath::RandRange(0, 1);
}

float AMyActor::Distance(FVector curLocation, FVector NewLocation)
{
	return FVector::Dist(curLocation, NewLocation); //두 벡터 사이의 거리
}

int32 AMyActor::createEvent()
{
	if (FMath::RandRange(0, 1)) //50% 확률의 랜덤 -> 1이 나오면 true
	{
		UE_LOG(LogTemp, Warning, TEXT("Random Event!"));
		
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("50% Event!")); //화면 왼쪽 위 로그 창에 출력
		}

		spawnActor(); //이벤트 발생시 액터 스폰

		return 1;
	}
	else
	{
		return 0;
	}
	
}

void AMyActor::spawnActor() //액터 스폰 함수
{
	FActorSpawnParameters spawnPara;
	spawnPara.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn; //액터 생성시 콜리전 설정
	
	GetWorld()->SpawnActor<AActor>(actorToSpawn, SpawnLocation, spawnPara); //실제 액터 스폰 코드
}