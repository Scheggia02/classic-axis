#pragma once
#define GINPUT_COMPILE_CROSSCOMPATIBLE_VERSION
#include "GInputAPI.h"

#include "Settings.h"

class ClassicAxis {
public:
	class IGInputPad* pXboxPad;
	bool isAiming;
	bool wasPointing;
	bool wasCrouching;
	bool ignoreRotation;
	bool forceRealMoveAnim;
	Settings settings;
	RwV3d lastLockOnPos;
	int timeLockOn;

	//Fire timer Logic
	int fireTimerStartTime;
	int fireTimerMaxTime;
	int weaponFireRate;
	bool isFiringTimeActive;
	bool bResetWeaponTimerOnReload;
	bool bWeaponEnablePointAt;
	bool bEnableCrouchAimAnimation;
	bool bCheckForAttackState;

	//Reload timer Logic
	int reloadTimerStartTIme;
	int reloadMaxTime;
	bool isReloadTimeActive;
	bool bUseReloadTimer;

	CRGBA lastLockOnColor;
	CPed* thirdPersonMouseTarget;
	float previousHorAngle;
	float previousVerAngle;
	bool camUseCurrentAngle;
	short previousCamMode;
	bool switchTransitionSpeed;
	short savedCamMode;
	bool isSwimming;

	bool bShouldResetWeaponAnimation;

	bool weaponInfoSet;
#ifdef GTA3
	bool wantsToResetWeaponInfo;
	class CWeaponInfo weaponInfo[WEAPONTYPE_HELICANNON + 1];
#endif

	class CWeaponInfo weaponInfo[WEAPONTYPE_ANYWEAPON + 1];
	class CWeaponInfo currentWeaponInfoBackup;


public:
	ClassicAxis();
	void RotatePlayer(CPed* ped, float angle, bool smooth);
	void Clear();
	bool IsAbleToAim(CPed* ped);
	bool IsType1stPerson(CPed* ped);
	bool IsWeaponPossiblyCompatible(CPed* ped);
#ifdef GTA3
	bool CanDuckWithThisWeapon(eWeaponType weapon);
#endif
	bool IsTypeMelee(CPed* ped);
	bool IsTypeTwoHanded(CPed* ped);
	void DrawCrosshair();
	void DrawAutoAimTarget();
	void DrawTriangleForMouseRecruitPed();
	void ClearWeaponTarget(CPlayerPed* ped);
	void AdjustWeaponAnimationForShooting(CPlayerPed* ped);
	void ResetWeaponTimers();

	int StringToKey(std::string str);
	bool GetKeyDown(int key, bool old = false);
	bool WalkKeyDown();
	bool ShootKeyUp();
	void ProcessPlayerPedControl(CPlayerPed* ped);
	float Find3rdPersonQuickAimPitch(float y);
	void Find3rdPersonMouseTarget(CPlayerPed* ped);

	void SetupAim(CPlayerPed* playa, const bool bPlayAnimation = true);

	void StartFiringTimer(CPlayerPed* playa);
	void UpdateFiringTimer(CPlayerPed* playa, bool& point);
	void StopFiringTimer(CPlayerPed* playa, bool& point);
	void StartReloadTimer();
	void UpdateReloadTimer(CPlayerPed* playa, bool& point);
	void StopReloadTimer(CPlayerPed* playa, bool& point);

#ifdef GTA3
	bool DuckKeyDown();
	void SetDuck(CPlayerPed* ped);
	void ClearDuck(CPlayerPed* ped);
	void AdjustWeaponInfoForCrouch(CPlayerPed* ped);
	void ResetWeaponInfo(CPlayerPed* ped);
#endif
};

extern ClassicAxis classicAxis;
