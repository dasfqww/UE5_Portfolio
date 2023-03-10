// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Weapon.generated.h"

class USoundBase;
class UBoxComponent;
class USceneComponent;

/**
 * 
 */
UCLASS()
class UE5_PORTFOLIO_API AWeapon : public AItem
{
	GENERATED_BODY()
public:
	AWeapon();
	void PlayEquipSound();
	void DisableSphereCollision();
	void Equip(USceneComponent* InParent, FName InSocketName, 
	           AActor* newOwner, APawn* newInstigator);
	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName);

	TArray<AActor*> ignoreActors;
protected:
	virtual void BeginPlay() override;
	void ExcuteGetHit(FHitResult& BoxHit);

	/*virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;*/

	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void CreateFields(const FVector& fieldLocation);
private:

	void BoxTrace(FHitResult& BoxHit);

	UPROPERTY(EditAnywhere, Category="Weapon Properties")
	FVector BoxTraceExtent = FVector(5.f);

	UPROPERTY(EditAnywhere, Category = "Weapon Properties")
	bool bShowBoxDebug = false;

	UPROPERTY(EditAnywhere, Category="Weapon Properties")
	USoundBase* EquipSound;

	UPROPERTY(VisibleAnywhere, Category="WeaponProperties")
	UBoxComponent* WeaponBox;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceStart;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* BoxTraceEnd;

	UPROPERTY(EditAnywhere, Category = "WeaponProperties")
	float Damage = 25.f;
public:
	FORCEINLINE UBoxComponent* GetWeaponBox() const { return WeaponBox; }
};