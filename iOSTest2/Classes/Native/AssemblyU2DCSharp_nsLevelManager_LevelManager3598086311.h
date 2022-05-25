#pragma once

#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <stdint.h>

// System.Int32[0...,0...][]
struct Int32U5BU2CU5DU5BU5D_t4237006271;
// System.Collections.Generic.List`1<UnityEngine.GameObject>[]
struct List_1U5BU5D_t3122329854;
// UnityEngine.GameObject
struct GameObject_t1756533147;
// Ship1
struct Ship1_t1303907657;
// Ship2
struct Ship2_t1303907656;

#include "UnityEngine_UnityEngine_MonoBehaviour1158329972.h"

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif

// nsLevelManager.LevelManager
struct  LevelManager_t3598086311  : public MonoBehaviour_t1158329972
{
public:
	// System.Single nsLevelManager.LevelManager::radius_shift
	float ___radius_shift_2;
	// System.Single nsLevelManager.LevelManager::radius_signature
	float ___radius_signature_3;
	// System.Single nsLevelManager.LevelManager::level1_start_position
	float ___level1_start_position_4;
	// System.Single nsLevelManager.LevelManager::level2_start_position
	float ___level2_start_position_5;
	// System.Single nsLevelManager.LevelManager::level3_start_position
	float ___level3_start_position_6;
	// System.Single nsLevelManager.LevelManager::level1_tickrate
	float ___level1_tickrate_7;
	// System.Single nsLevelManager.LevelManager::level2_tickrate
	float ___level2_tickrate_8;
	// System.Single nsLevelManager.LevelManager::level3_tickrate
	float ___level3_tickrate_9;
	// System.Int32 nsLevelManager.LevelManager::position
	int32_t ___position_10;
	// System.Boolean nsLevelManager.LevelManager::ring_position_updated
	bool ___ring_position_updated_11;
	// System.Int32 nsLevelManager.LevelManager::score
	int32_t ___score_12;
	// System.Single nsLevelManager.LevelManager::depth_separation_mod
	float ___depth_separation_mod_13;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::current_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___current_course_data_14;
	// System.Single nsLevelManager.LevelManager::current_position
	float ___current_position_15;
	// System.Int32 nsLevelManager.LevelManager::current_length
	int32_t ___current_length_16;
	// System.Single nsLevelManager.LevelManager::current_tickrate
	float ___current_tickrate_17;
	// System.Int32 nsLevelManager.LevelManager::current_level
	int32_t ___current_level_18;
	// System.Collections.Generic.List`1<UnityEngine.GameObject>[] nsLevelManager.LevelManager::course_obj_list
	List_1U5BU5D_t3122329854* ___course_obj_list_19;
	// UnityEngine.GameObject nsLevelManager.LevelManager::shp1
	GameObject_t1756533147 * ___shp1_20;
	// UnityEngine.GameObject nsLevelManager.LevelManager::shp2
	GameObject_t1756533147 * ___shp2_21;
	// Ship1 nsLevelManager.LevelManager::shp1_scr
	Ship1_t1303907657 * ___shp1_scr_22;
	// Ship2 nsLevelManager.LevelManager::shp2_scr
	Ship2_t1303907656 * ___shp2_scr_23;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level3_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level3_course_data_24;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level2_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level2_course_data_25;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level1_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level1_course_data_26;

public:
	inline static int32_t get_offset_of_radius_shift_2() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___radius_shift_2)); }
	inline float get_radius_shift_2() const { return ___radius_shift_2; }
	inline float* get_address_of_radius_shift_2() { return &___radius_shift_2; }
	inline void set_radius_shift_2(float value)
	{
		___radius_shift_2 = value;
	}

	inline static int32_t get_offset_of_radius_signature_3() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___radius_signature_3)); }
	inline float get_radius_signature_3() const { return ___radius_signature_3; }
	inline float* get_address_of_radius_signature_3() { return &___radius_signature_3; }
	inline void set_radius_signature_3(float value)
	{
		___radius_signature_3 = value;
	}

	inline static int32_t get_offset_of_level1_start_position_4() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level1_start_position_4)); }
	inline float get_level1_start_position_4() const { return ___level1_start_position_4; }
	inline float* get_address_of_level1_start_position_4() { return &___level1_start_position_4; }
	inline void set_level1_start_position_4(float value)
	{
		___level1_start_position_4 = value;
	}

	inline static int32_t get_offset_of_level2_start_position_5() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level2_start_position_5)); }
	inline float get_level2_start_position_5() const { return ___level2_start_position_5; }
	inline float* get_address_of_level2_start_position_5() { return &___level2_start_position_5; }
	inline void set_level2_start_position_5(float value)
	{
		___level2_start_position_5 = value;
	}

	inline static int32_t get_offset_of_level3_start_position_6() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level3_start_position_6)); }
	inline float get_level3_start_position_6() const { return ___level3_start_position_6; }
	inline float* get_address_of_level3_start_position_6() { return &___level3_start_position_6; }
	inline void set_level3_start_position_6(float value)
	{
		___level3_start_position_6 = value;
	}

	inline static int32_t get_offset_of_level1_tickrate_7() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level1_tickrate_7)); }
	inline float get_level1_tickrate_7() const { return ___level1_tickrate_7; }
	inline float* get_address_of_level1_tickrate_7() { return &___level1_tickrate_7; }
	inline void set_level1_tickrate_7(float value)
	{
		___level1_tickrate_7 = value;
	}

	inline static int32_t get_offset_of_level2_tickrate_8() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level2_tickrate_8)); }
	inline float get_level2_tickrate_8() const { return ___level2_tickrate_8; }
	inline float* get_address_of_level2_tickrate_8() { return &___level2_tickrate_8; }
	inline void set_level2_tickrate_8(float value)
	{
		___level2_tickrate_8 = value;
	}

	inline static int32_t get_offset_of_level3_tickrate_9() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level3_tickrate_9)); }
	inline float get_level3_tickrate_9() const { return ___level3_tickrate_9; }
	inline float* get_address_of_level3_tickrate_9() { return &___level3_tickrate_9; }
	inline void set_level3_tickrate_9(float value)
	{
		___level3_tickrate_9 = value;
	}

	inline static int32_t get_offset_of_position_10() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___position_10)); }
	inline int32_t get_position_10() const { return ___position_10; }
	inline int32_t* get_address_of_position_10() { return &___position_10; }
	inline void set_position_10(int32_t value)
	{
		___position_10 = value;
	}

	inline static int32_t get_offset_of_ring_position_updated_11() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___ring_position_updated_11)); }
	inline bool get_ring_position_updated_11() const { return ___ring_position_updated_11; }
	inline bool* get_address_of_ring_position_updated_11() { return &___ring_position_updated_11; }
	inline void set_ring_position_updated_11(bool value)
	{
		___ring_position_updated_11 = value;
	}

	inline static int32_t get_offset_of_score_12() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___score_12)); }
	inline int32_t get_score_12() const { return ___score_12; }
	inline int32_t* get_address_of_score_12() { return &___score_12; }
	inline void set_score_12(int32_t value)
	{
		___score_12 = value;
	}

	inline static int32_t get_offset_of_depth_separation_mod_13() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___depth_separation_mod_13)); }
	inline float get_depth_separation_mod_13() const { return ___depth_separation_mod_13; }
	inline float* get_address_of_depth_separation_mod_13() { return &___depth_separation_mod_13; }
	inline void set_depth_separation_mod_13(float value)
	{
		___depth_separation_mod_13 = value;
	}

	inline static int32_t get_offset_of_current_course_data_14() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_course_data_14)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_current_course_data_14() const { return ___current_course_data_14; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_current_course_data_14() { return &___current_course_data_14; }
	inline void set_current_course_data_14(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___current_course_data_14 = value;
		Il2CppCodeGenWriteBarrier(&___current_course_data_14, value);
	}

	inline static int32_t get_offset_of_current_position_15() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_position_15)); }
	inline float get_current_position_15() const { return ___current_position_15; }
	inline float* get_address_of_current_position_15() { return &___current_position_15; }
	inline void set_current_position_15(float value)
	{
		___current_position_15 = value;
	}

	inline static int32_t get_offset_of_current_length_16() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_length_16)); }
	inline int32_t get_current_length_16() const { return ___current_length_16; }
	inline int32_t* get_address_of_current_length_16() { return &___current_length_16; }
	inline void set_current_length_16(int32_t value)
	{
		___current_length_16 = value;
	}

	inline static int32_t get_offset_of_current_tickrate_17() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_tickrate_17)); }
	inline float get_current_tickrate_17() const { return ___current_tickrate_17; }
	inline float* get_address_of_current_tickrate_17() { return &___current_tickrate_17; }
	inline void set_current_tickrate_17(float value)
	{
		___current_tickrate_17 = value;
	}

	inline static int32_t get_offset_of_current_level_18() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_level_18)); }
	inline int32_t get_current_level_18() const { return ___current_level_18; }
	inline int32_t* get_address_of_current_level_18() { return &___current_level_18; }
	inline void set_current_level_18(int32_t value)
	{
		___current_level_18 = value;
	}

	inline static int32_t get_offset_of_course_obj_list_19() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___course_obj_list_19)); }
	inline List_1U5BU5D_t3122329854* get_course_obj_list_19() const { return ___course_obj_list_19; }
	inline List_1U5BU5D_t3122329854** get_address_of_course_obj_list_19() { return &___course_obj_list_19; }
	inline void set_course_obj_list_19(List_1U5BU5D_t3122329854* value)
	{
		___course_obj_list_19 = value;
		Il2CppCodeGenWriteBarrier(&___course_obj_list_19, value);
	}

	inline static int32_t get_offset_of_shp1_20() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp1_20)); }
	inline GameObject_t1756533147 * get_shp1_20() const { return ___shp1_20; }
	inline GameObject_t1756533147 ** get_address_of_shp1_20() { return &___shp1_20; }
	inline void set_shp1_20(GameObject_t1756533147 * value)
	{
		___shp1_20 = value;
		Il2CppCodeGenWriteBarrier(&___shp1_20, value);
	}

	inline static int32_t get_offset_of_shp2_21() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp2_21)); }
	inline GameObject_t1756533147 * get_shp2_21() const { return ___shp2_21; }
	inline GameObject_t1756533147 ** get_address_of_shp2_21() { return &___shp2_21; }
	inline void set_shp2_21(GameObject_t1756533147 * value)
	{
		___shp2_21 = value;
		Il2CppCodeGenWriteBarrier(&___shp2_21, value);
	}

	inline static int32_t get_offset_of_shp1_scr_22() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp1_scr_22)); }
	inline Ship1_t1303907657 * get_shp1_scr_22() const { return ___shp1_scr_22; }
	inline Ship1_t1303907657 ** get_address_of_shp1_scr_22() { return &___shp1_scr_22; }
	inline void set_shp1_scr_22(Ship1_t1303907657 * value)
	{
		___shp1_scr_22 = value;
		Il2CppCodeGenWriteBarrier(&___shp1_scr_22, value);
	}

	inline static int32_t get_offset_of_shp2_scr_23() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp2_scr_23)); }
	inline Ship2_t1303907656 * get_shp2_scr_23() const { return ___shp2_scr_23; }
	inline Ship2_t1303907656 ** get_address_of_shp2_scr_23() { return &___shp2_scr_23; }
	inline void set_shp2_scr_23(Ship2_t1303907656 * value)
	{
		___shp2_scr_23 = value;
		Il2CppCodeGenWriteBarrier(&___shp2_scr_23, value);
	}

	inline static int32_t get_offset_of_level3_course_data_24() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level3_course_data_24)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level3_course_data_24() const { return ___level3_course_data_24; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level3_course_data_24() { return &___level3_course_data_24; }
	inline void set_level3_course_data_24(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level3_course_data_24 = value;
		Il2CppCodeGenWriteBarrier(&___level3_course_data_24, value);
	}

	inline static int32_t get_offset_of_level2_course_data_25() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level2_course_data_25)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level2_course_data_25() const { return ___level2_course_data_25; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level2_course_data_25() { return &___level2_course_data_25; }
	inline void set_level2_course_data_25(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level2_course_data_25 = value;
		Il2CppCodeGenWriteBarrier(&___level2_course_data_25, value);
	}

	inline static int32_t get_offset_of_level1_course_data_26() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level1_course_data_26)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level1_course_data_26() const { return ___level1_course_data_26; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level1_course_data_26() { return &___level1_course_data_26; }
	inline void set_level1_course_data_26(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level1_course_data_26 = value;
		Il2CppCodeGenWriteBarrier(&___level1_course_data_26, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
