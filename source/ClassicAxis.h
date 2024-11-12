#pragma once
#define GINPUT_COMPILE_CROSSCOMPATIBLE_VERSION
#include "GInputAPI.h"

#include "Settings.h"

class ClassicAxis {
public:
	enum eAnimationId
	{
		ANIM_WEAPON_FIRE = 205,
		ANIM_WEAPON_CROUCHFIRE = 206,
		ANIM_WEAPON_RELOAD = 207,
		ANIM_WEAPON_CROUCHRELOAD = 208,
	};

	class IGInputPad* pXboxPad;
	bool isAiming;
	bool wasPointing;
	bool wasCrouching;
	bool ignoreRotation;
	bool forceRealMoveAnim;
	Settings settings;
	RwV3d lastLockOnPos;
	int timeLockOn;

	bool bWeaponEnablePointAt;
	bool bFiringAnimRemoveTimestep;
	bool bPlayStartingFiringAnimation;
	bool bPlayEndingFiringAnimation;
	float StartingFiringAnimationMaxTime;
	float EndingFiringAnimationMaxTime;

	float FiringAnimStartTime;
	float FiringAnimEndTime;

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

	int StringToKey(std::string str);
	bool GetKeyDown(int key, bool old = false);
	bool WalkKeyDown();
	void ProcessPlayerPedControl(CPlayerPed* ped);
	float Find3rdPersonQuickAimPitch(float y);
	void Find3rdPersonMouseTarget(CPlayerPed* ped);

	void SetupAim(CPlayerPed* playa, const bool bPlayAnimation = true);
	static void OnAnimFinished(CAnimBlendAssociation* anim, void* data);

#ifdef GTA3
	bool DuckKeyDown();
	void SetDuck(CPlayerPed* ped);
	void ClearDuck(CPlayerPed* ped);
	void AdjustWeaponInfoForCrouch(CPlayerPed* ped);
	void ResetWeaponInfo(CPlayerPed* ped);
#endif
};

extern ClassicAxis classicAxis;
