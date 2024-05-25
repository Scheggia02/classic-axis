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
    void AdjustWeaponAnimationForCrouch(CPlayerPed* ped);
    void ResetWeaponAnimation(CPlayerPed* ped);
    int StringToKey(std::string str);
    bool GetKeyDown(int key, bool old = false);
    bool WalkKeyDown();
    void ProcessPlayerPedControl(CPlayerPed* ped);
    float Find3rdPersonQuickAimPitch(float y);
    void Find3rdPersonMouseTarget(CPlayerPed* ped);

#ifdef GTA3
    bool DuckKeyDown();
    void SetDuck(CPlayerPed* ped);
    void ClearDuck(CPlayerPed* ped);
    void AdjustWeaponInfoForCrouch(CPlayerPed* ped);
    void ResetWeaponInfo(CPlayerPed* ped);
#endif
};

extern ClassicAxis classicAxis;
