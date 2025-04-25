#pragma once
#define GINPUT_COMPILE_CROSSCOMPATIBLE_VERSION
#include "GInputAPI.h"

#include "Settings.h"
#include "Utility.h"

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

	bool bCanShootCrouch = false;
	bool bWeaponEnablePointAt;
	bool bRemoveTimestepFromFiringAnim;
	bool bResetCrouchWhenReloading;
	bool bCustomCrouchLogic;
	bool bSkipAllShotingCustomLogic;

	float FiringAnimStartTime;
	float FiringAnimEndTime;

	int weaponPreviousAnimId = -1;
	CWeaponInfo weaponPreviousInfo{};

	CVector preFindingLockTargetForward = {0.0f, 0.0f, 0.0f};
	
	bool bEnableResetAimTimer = false;
	bool isResetAimTimerActive = false;
	int resetAimDelayTime = 100;
	int resetAimFrame = 0.;
	int resetAimTime = 0;

	ePedState lastState = PEDSTATE_IDLE;
	bool wasShootPressed = false;

	float weaponVerticalAngleOffset = 0.0f;
	float playerRotationOffset = 0.0f;
	float playerAimRotationOffset = 0.0f;
	
	CAnimBlendAssociation* currentAnim;
	float currentAnimLastTime;

	CRGBA lastLockOnColor;
	CPed* thirdPersonMouseTarget;
	float previousHorAngle;
	float previousVerAngle;
	bool camUseCurrentAngle;
	short previousCamMode;
	bool switchTransitionSpeed;
	short savedCamMode;
	float cameraHorizontalAngleMultiplier = -0.3f;
	float test = 0.0f;
	
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
	bool CanWeaponAimWhileWalking(CPed* ped);
#ifdef GTA3
	bool CanDuckWithThisWeapon(eWeaponType weapon);
#endif
	bool IsTypeMelee(CPed* ped);
	bool IsTypeTwoHanded(CPed* ped);
	void DrawCrosshair();
	void DrawAutoAimTarget();
	void DrawTriangleForMouseRecruitPed();
	void ClearWeaponTarget(CPlayerPed* ped);
	void AdjustWeaponShootingAnimation(CPlayerPed* ped);
	void AdjustWeaponAnimationAfterShooting(CPlayerPed* ped);
	void AdjustWeaponAngleOffsets(const CPlayerPed* ped, float horizontalOffset, float verticalOffset);

	int StringToKey(std::string str);
	bool GetKeyDown(int key, bool old = false);
	bool GetIsMouseButtonDown(RsKeyCodes keycode);
	bool GetIsMouseButtonUp(RsKeyCodes keycode);

	bool WalkKeyDown();
	bool AnyWalkKeyDown();
	void ResetWalkInputs(CPlayerPed* playa);
	void ProcessPlayerPedControl(CPlayerPed* ped);
	float Find3rdPersonQuickAimPitch(float y);
	void Find3rdPersonMouseTarget(CPlayerPed* ped);

	void SetupAim(CPlayerPed* playa, const bool bPlayAnimation = true, float newCurrentTime = 0.0f);
	void TriggerResetAimTimer(CPlayerPed* playa);
	float AngleBetween(const CVector& a, const CVector& b) const;

	void SearchForNewLockTargetRecursive(CPlayerPed* ped);
	bool FindWeaponLockTargetWithRotation(CPlayerPed* ped);
	bool IsFirstPersonAssaultRifleWeapon(CPlayerPed* ped) const;
	
#ifdef GTA3
	bool DuckKeyDown();
	void SetDuck(CPlayerPed* ped);
	void ClearDuck(CPlayerPed* ped);
	void AdjustWeaponInfoForCrouch(CPlayerPed* ped);
	void ResetWeaponInfo(CPlayerPed* ped);
#endif
};


extern ClassicAxis classicAxis;
