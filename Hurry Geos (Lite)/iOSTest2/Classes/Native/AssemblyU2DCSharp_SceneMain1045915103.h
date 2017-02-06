#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// nsLevelManager.LevelManager
struct LevelManager_t3598086311;
// UnityEngine.GameObject
struct GameObject_t1756533147;
// CameraTracker
struct CameraTracker_t2463508323;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// SceneMain
struct  SceneMain_t1045915103  : public MonoBehaviour_t1158329972
{
public:
	// nsLevelManager.LevelManager SceneMain::g
	LevelManager_t3598086311 * ___g_2;
	// UnityEngine.GameObject SceneMain::g_obj1
	GameObject_t1756533147 * ___g_obj1_3;
	// UnityEngine.GameObject SceneMain::g_obj2
	GameObject_t1756533147 * ___g_obj2_4;
	// UnityEngine.GameObject SceneMain::c_obj
	GameObject_t1756533147 * ___c_obj_5;
	// CameraTracker SceneMain::c_obj_script
	CameraTracker_t2463508323 * ___c_obj_script_6;

public:
	inline static int32_t get_offset_of_g_2() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___g_2)); }
	inline LevelManager_t3598086311 * get_g_2() const { return ___g_2; }
	inline LevelManager_t3598086311 ** get_address_of_g_2() { return &___g_2; }
	inline void set_g_2(LevelManager_t3598086311 * value)
	{
		___g_2 = value;
		Il2CppCodeGenWriteBarrier(&___g_2, value);
	}

	inline static int32_t get_offset_of_g_obj1_3() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___g_obj1_3)); }
	inline GameObject_t1756533147 * get_g_obj1_3() const { return ___g_obj1_3; }
	inline GameObject_t1756533147 ** get_address_of_g_obj1_3() { return &___g_obj1_3; }
	inline void set_g_obj1_3(GameObject_t1756533147 * value)
	{
		___g_obj1_3 = value;
		Il2CppCodeGenWriteBarrier(&___g_obj1_3, value);
	}

	inline static int32_t get_offset_of_g_obj2_4() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___g_obj2_4)); }
	inline GameObject_t1756533147 * get_g_obj2_4() const { return ___g_obj2_4; }
	inline GameObject_t1756533147 ** get_address_of_g_obj2_4() { return &___g_obj2_4; }
	inline void set_g_obj2_4(GameObject_t1756533147 * value)
	{
		___g_obj2_4 = value;
		Il2CppCodeGenWriteBarrier(&___g_obj2_4, value);
	}

	inline static int32_t get_offset_of_c_obj_5() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___c_obj_5)); }
	inline GameObject_t1756533147 * get_c_obj_5() const { return ___c_obj_5; }
	inline GameObject_t1756533147 ** get_address_of_c_obj_5() { return &___c_obj_5; }
	inline void set_c_obj_5(GameObject_t1756533147 * value)
	{
		___c_obj_5 = value;
		Il2CppCodeGenWriteBarrier(&___c_obj_5, value);
	}

	inline static int32_t get_offset_of_c_obj_script_6() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___c_obj_script_6)); }
	inline CameraTracker_t2463508323 * get_c_obj_script_6() const { return ___c_obj_script_6; }
	inline CameraTracker_t2463508323 ** get_address_of_c_obj_script_6() { return &___c_obj_script_6; }
	inline void set_c_obj_script_6(CameraTracker_t2463508323 * value)
	{
		___c_obj_script_6 = value;
		Il2CppCodeGenWriteBarrier(&___c_obj_script_6, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
