#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// UnityEngine.GameObject
struct GameObject_t1756533147;
// System.Collections.Generic.List`1<UnityEngine.GameObject>
struct List_1_t1125654279;

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
	// System.Int32 SceneMain::AsteroidAmount
	int32_t ___AsteroidAmount_2;
	// System.Int32 SceneMain::Thrust
	int32_t ___Thrust_3;
	// UnityEngine.GameObject SceneMain::pAsteroid
	GameObject_t1756533147 * ___pAsteroid_4;
	// System.Single SceneMain::Spread
	float ___Spread_5;
	// UnityEngine.GameObject SceneMain::prefabAsteroid
	GameObject_t1756533147 * ___prefabAsteroid_6;
	// System.Collections.Generic.List`1<UnityEngine.GameObject> SceneMain::asteroid_list
	List_1_t1125654279 * ___asteroid_list_7;

public:
	inline static int32_t get_offset_of_AsteroidAmount_2() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___AsteroidAmount_2)); }
	inline int32_t get_AsteroidAmount_2() const { return ___AsteroidAmount_2; }
	inline int32_t* get_address_of_AsteroidAmount_2() { return &___AsteroidAmount_2; }
	inline void set_AsteroidAmount_2(int32_t value)
	{
		___AsteroidAmount_2 = value;
	}

	inline static int32_t get_offset_of_Thrust_3() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___Thrust_3)); }
	inline int32_t get_Thrust_3() const { return ___Thrust_3; }
	inline int32_t* get_address_of_Thrust_3() { return &___Thrust_3; }
	inline void set_Thrust_3(int32_t value)
	{
		___Thrust_3 = value;
	}

	inline static int32_t get_offset_of_pAsteroid_4() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___pAsteroid_4)); }
	inline GameObject_t1756533147 * get_pAsteroid_4() const { return ___pAsteroid_4; }
	inline GameObject_t1756533147 ** get_address_of_pAsteroid_4() { return &___pAsteroid_4; }
	inline void set_pAsteroid_4(GameObject_t1756533147 * value)
	{
		___pAsteroid_4 = value;
		Il2CppCodeGenWriteBarrier(&___pAsteroid_4, value);
	}

	inline static int32_t get_offset_of_Spread_5() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___Spread_5)); }
	inline float get_Spread_5() const { return ___Spread_5; }
	inline float* get_address_of_Spread_5() { return &___Spread_5; }
	inline void set_Spread_5(float value)
	{
		___Spread_5 = value;
	}

	inline static int32_t get_offset_of_prefabAsteroid_6() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___prefabAsteroid_6)); }
	inline GameObject_t1756533147 * get_prefabAsteroid_6() const { return ___prefabAsteroid_6; }
	inline GameObject_t1756533147 ** get_address_of_prefabAsteroid_6() { return &___prefabAsteroid_6; }
	inline void set_prefabAsteroid_6(GameObject_t1756533147 * value)
	{
		___prefabAsteroid_6 = value;
		Il2CppCodeGenWriteBarrier(&___prefabAsteroid_6, value);
	}

	inline static int32_t get_offset_of_asteroid_list_7() { return static_cast<int32_t>(offsetof(SceneMain_t1045915103, ___asteroid_list_7)); }
	inline List_1_t1125654279 * get_asteroid_list_7() const { return ___asteroid_list_7; }
	inline List_1_t1125654279 ** get_address_of_asteroid_list_7() { return &___asteroid_list_7; }
	inline void set_asteroid_list_7(List_1_t1125654279 * value)
	{
		___asteroid_list_7 = value;
		Il2CppCodeGenWriteBarrier(&___asteroid_list_7, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
