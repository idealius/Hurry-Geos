#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>
#include <assert.h>
#include <exception>

// nsLevelManager.LevelManager
struct LevelManager_t3598086311;
// UnityEngine.GameObject
struct GameObject_t1756533147;
// System.String
struct String_t;

#include "codegen/il2cpp-codegen.h"
#include "UnityEngine_UnityEngine_GameObject1756533147.h"
#include "mscorlib_System_String2029220233.h"

// System.Void nsLevelManager.LevelManager::.ctor()
extern "C"  void LevelManager__ctor_m2204638816 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::Start()
extern "C"  void LevelManager_Start_m3851340720 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::UpdatePosition()
extern "C"  void LevelManager_UpdatePosition_m4138772836 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::CheckforImpact()
extern "C"  void LevelManager_CheckforImpact_m1891061771 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::UpdateScore()
extern "C"  void LevelManager_UpdateScore_m3897202069 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::UpdatePositionCalc()
extern "C"  void LevelManager_UpdatePositionCalc_m1603579497 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::UpdateRingPositionCalc()
extern "C"  void LevelManager_UpdateRingPositionCalc_m3840579739 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::UpdateFramePositionCalc()
extern "C"  void LevelManager_UpdateFramePositionCalc_m1359887444 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::GenerateCourseObjects()
extern "C"  void LevelManager_GenerateCourseObjects_m1377174166 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::MixMaterial(UnityEngine.GameObject,System.String,System.Single)
extern "C"  void LevelManager_MixMaterial_m3891273646 (LevelManager_t3598086311 * __this, GameObject_t1756533147 * ___g_obj0, String_t* ___str_dest_material1, float ___avg2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::ChangeAlpha(UnityEngine.GameObject,System.Single,System.Boolean)
extern "C"  void LevelManager_ChangeAlpha_m1891255292 (LevelManager_t3598086311 * __this, GameObject_t1756533147 * ___g_obj0, float ___alpha1, bool ___by_delta2, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::ChangeAlpha(UnityEngine.GameObject,System.Single)
extern "C"  void LevelManager_ChangeAlpha_m2206909911 (LevelManager_t3598086311 * __this, GameObject_t1756533147 * ___g_obj0, float ___alpha1, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::AdvanceLevel()
extern "C"  void LevelManager_AdvanceLevel_m4184892014 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::PickLevel(System.Int32)
extern "C"  void LevelManager_PickLevel_m2848591844 (LevelManager_t3598086311 * __this, int32_t ___level0, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::ClearLevel()
extern "C"  void LevelManager_ClearLevel_m3166062283 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
// System.Void nsLevelManager.LevelManager::ResetLevel()
extern "C"  void LevelManager_ResetLevel_m372349339 (LevelManager_t3598086311 * __this, const MethodInfo* method) IL2CPP_METHOD_ATTR;
