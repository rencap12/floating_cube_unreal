// FloatingActor.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingActor.generated.h"

UCLASS()
class QUICKSTART_API AFloatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;
	
	// Expose parameters to the editor for easy tweaking
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Floating Movement")
	float FloatSpeed = 20.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Floating Movement")
	float RotationSpeed = 20.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};