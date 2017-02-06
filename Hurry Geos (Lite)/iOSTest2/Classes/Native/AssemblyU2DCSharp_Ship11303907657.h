#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.String
struct String_t;
// UnityEngine.GameObject
struct GameObject_t1756533147;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// Ship1
struct  Ship1_t1303907657  : public MonoBehaviour_t1158329972
{
public:
	// System.Boolean Ship1::impact
	bool ___impact_2;
	// System.String Ship1::bogey
	String_t* ___bogey_3;
	// UnityEngine.GameObject Ship1::g_obj_bogey
	GameObject_t1756533147 * ___g_obj_bogey_4;

public:
	inline static int32_t get_offset_of_impact_2() { return static_cast<int32_t>(offsetof(Ship1_t1303907657, ___impact_2)); }
	inline bool get_impact_2() const { return ___impact_2; }
	inline bool* get_address_of_impact_2() { return &___impact_2; }
	inline void set_impact_2(bool value)
	{
		___impact_2 = value;
	}

	inline static int32_t get_offset_of_bogey_3() { return static_cast<int32_t>(offsetof(Ship1_t1303907657, ___bogey_3)); }
	inline String_t* get_bogey_3() const { return ___bogey_3; }
	inline String_t** get_address_of_bogey_3() { return &___bogey_3; }
	inline void set_bogey_3(String_t* value)
	{
		___bogey_3 = value;
		Il2CppCodeGenWriteBarrier(&___bogey_3, value);
	}

	inline static int32_t get_offset_of_g_obj_bogey_4() { return static_cast<int32_t>(offsetof(Ship1_t1303907657, ___g_obj_bogey_4)); }
	inline GameObject_t1756533147 * get_g_obj_bogey_4() const { return ___g_obj_bogey_4; }
	inline GameObject_t1756533147 ** get_address_of_g_obj_bogey_4() { return &___g_obj_bogey_4; }
	inline void set_g_obj_bogey_4(GameObject_t1756533147 * value)
	{
		___g_obj_bogey_4 = value;
		Il2CppCodeGenWriteBarrier(&___g_obj_bogey_4, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
