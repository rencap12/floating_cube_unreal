// FloatingActor.cpp
#include "FloatingActor.h"

AFloatingActor::AFloatingActor()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;

	// Create and attach the static mesh component
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	
	// Find and assign a cube asset from the starter content
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	
	if (CubeVisualAsset.Succeeded())
	{
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
}

void AFloatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Calculate new position based on sine wave motion
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	
	// Apply the float speed parameter to control bobbing speed
	NewLocation.Z += DeltaHeight * FloatSpeed;
	
	// Apply the rotation speed parameter to control rotation speed
	float DeltaRotation = DeltaTime * RotationSpeed;
	NewRotation.Yaw += DeltaRotation;
	
	// Update the actor's position and rotation
	SetActorLocationAndRotation(NewLocation, NewRotation);
}