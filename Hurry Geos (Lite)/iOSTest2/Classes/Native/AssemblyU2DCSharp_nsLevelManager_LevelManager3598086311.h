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
#include "AssemblyU2DCSharp_level866812534.h"

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
	// level nsLevelManager.LevelManager::lvl1
	level_t866812534  ___lvl1_3;
	// level nsLevelManager.LevelManager::lvl2
	level_t866812534  ___lvl2_4;
	// level nsLevelManager.LevelManager::lvl3
	level_t866812534  ___lvl3_5;
	// level nsLevelManager.LevelManager::current
	level_t866812534  ___current_6;
	// System.Int32 nsLevelManager.LevelManager::position
	int32_t ___position_7;
	// System.Boolean nsLevelManager.LevelManager::ring_position_updated
	bool ___ring_position_updated_8;
	// System.Int32 nsLevelManager.LevelManager::score
	int32_t ___score_9;
	// System.Single nsLevelManager.LevelManager::depth_separation_mod
	float ___depth_separation_mod_10;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::current_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___current_course_data_11;
	// System.Single nsLevelManager.LevelManager::current_position
	float ___current_position_12;
	// System.Int32 nsLevelManager.LevelManager::current_length
	int32_t ___current_length_13;
	// System.Int32 nsLevelManager.LevelManager::current_level
	int32_t ___current_level_14;
	// System.Collections.Generic.List`1<UnityEngine.GameObject>[] nsLevelManager.LevelManager::course_obj_list
	List_1U5BU5D_t3122329854* ___course_obj_list_15;
	// UnityEngine.GameObject nsLevelManager.LevelManager::shp1
	GameObject_t1756533147 * ___shp1_16;
	// UnityEngine.GameObject nsLevelManager.LevelManager::shp2
	GameObject_t1756533147 * ___shp2_17;
	// Ship1 nsLevelManager.LevelManager::shp1_scr
	Ship1_t1303907657 * ___shp1_scr_18;
	// Ship2 nsLevelManager.LevelManager::shp2_scr
	Ship2_t1303907656 * ___shp2_scr_19;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level3_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level3_course_data_20;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level2_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level2_course_data_21;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level1_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level1_course_data_22;

public:
	inline static int32_t get_offset_of_radius_shift_2() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___radius_shift_2)); }
	inline float get_radius_shift_2() const { return ___radius_shift_2; }
	inline float* get_address_of_radius_shift_2() { return &___radius_shift_2; }
	inline void set_radius_shift_2(float value)
	{
		___radius_shift_2 = value;
	}

	inline static int32_t get_offset_of_lvl1_3() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___lvl1_3)); }
	inline level_t866812534  get_lvl1_3() const { return ___lvl1_3; }
	inline level_t866812534 * get_address_of_lvl1_3() { return &___lvl1_3; }
	inline void set_lvl1_3(level_t866812534  value)
	{
		___lvl1_3 = value;
	}

	inline static int32_t get_offset_of_lvl2_4() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___lvl2_4)); }
	inline level_t866812534  get_lvl2_4() const { return ___lvl2_4; }
	inline level_t866812534 * get_address_of_lvl2_4() { return &___lvl2_4; }
	inline void set_lvl2_4(level_t866812534  value)
	{
		___lvl2_4 = value;
	}

	inline static int32_t get_offset_of_lvl3_5() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___lvl3_5)); }
	inline level_t866812534  get_lvl3_5() const { return ___lvl3_5; }
	inline level_t866812534 * get_address_of_lvl3_5() { return &___lvl3_5; }
	inline void set_lvl3_5(level_t866812534  value)
	{
		___lvl3_5 = value;
	}

	inline static int32_t get_offset_of_current_6() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_6)); }
	inline level_t866812534  get_current_6() const { return ___current_6; }
	inline level_t866812534 * get_address_of_current_6() { return &___current_6; }
	inline void set_current_6(level_t866812534  value)
	{
		___current_6 = value;
	}

	inline static int32_t get_offset_of_position_7() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___position_7)); }
	inline int32_t get_position_7() const { return ___position_7; }
	inline int32_t* get_address_of_position_7() { return &___position_7; }
	inline void set_position_7(int32_t value)
	{
		___position_7 = value;
	}

	inline static int32_t get_offset_of_ring_position_updated_8() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___ring_position_updated_8)); }
	inline bool get_ring_position_updated_8() const { return ___ring_position_updated_8; }
	inline bool* get_address_of_ring_position_updated_8() { return &___ring_position_updated_8; }
	inline void set_ring_position_updated_8(bool value)
	{
		___ring_position_updated_8 = value;
	}

	inline static int32_t get_offset_of_score_9() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___score_9)); }
	inline int32_t get_score_9() const { return ___score_9; }
	inline int32_t* get_address_of_score_9() { return &___score_9; }
	inline void set_score_9(int32_t value)
	{
		___score_9 = value;
	}

	inline static int32_t get_offset_of_depth_separation_mod_10() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___depth_separation_mod_10)); }
	inline float get_depth_separation_mod_10() const { return ___depth_separation_mod_10; }
	inline float* get_address_of_depth_separation_mod_10() { return &___depth_separation_mod_10; }
	inline void set_depth_separation_mod_10(float value)
	{
		___depth_separation_mod_10 = value;
	}

	inline static int32_t get_offset_of_current_course_data_11() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_course_data_11)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_current_course_data_11() const { return ___current_course_data_11; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_current_course_data_11() { return &___current_course_data_11; }
	inline void set_current_course_data_11(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___current_course_data_11 = value;
		Il2CppCodeGenWriteBarrier(&___current_course_data_11, value);
	}

	inline static int32_t get_offset_of_current_position_12() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_position_12)); }
	inline float get_current_position_12() const { return ___current_position_12; }
	inline float* get_address_of_current_position_12() { return &___current_position_12; }
	inline void set_current_position_12(float value)
	{
		___current_position_12 = value;
	}

	inline static int32_t get_offset_of_current_length_13() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_length_13)); }
	inline int32_t get_current_length_13() const { return ___current_length_13; }
	inline int32_t* get_address_of_current_length_13() { return &___current_length_13; }
	inline void set_current_length_13(int32_t value)
	{
		___current_length_13 = value;
	}

	inline static int32_t get_offset_of_current_level_14() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_level_14)); }
	inline int32_t get_current_level_14() const { return ___current_level_14; }
	inline int32_t* get_address_of_current_level_14() { return &___current_level_14; }
	inline void set_current_level_14(int32_t value)
	{
		___current_level_14 = value;
	}

	inline static int32_t get_offset_of_course_obj_list_15() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___course_obj_list_15)); }
	inline List_1U5BU5D_t3122329854* get_course_obj_list_15() const { return ___course_obj_list_15; }
	inline List_1U5BU5D_t3122329854** get_address_of_course_obj_list_15() { return &___course_obj_list_15; }
	inline void set_course_obj_list_15(List_1U5BU5D_t3122329854* value)
	{
		___course_obj_list_15 = value;
		Il2CppCodeGenWriteBarrier(&___course_obj_list_15, value);
	}

	inline static int32_t get_offset_of_shp1_16() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp1_16)); }
	inline GameObject_t1756533147 * get_shp1_16() const { return ___shp1_16; }
	inline GameObject_t1756533147 ** get_address_of_shp1_16() { return &___shp1_16; }
	inline void set_shp1_16(GameObject_t1756533147 * value)
	{
		___shp1_16 = value;
		Il2CppCodeGenWriteBarrier(&___shp1_16, value);
	}

	inline static int32_t get_offset_of_shp2_17() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp2_17)); }
	inline GameObject_t1756533147 * get_shp2_17() const { return ___shp2_17; }
	inline GameObject_t1756533147 ** get_address_of_shp2_17() { return &___shp2_17; }
	inline void set_shp2_17(GameObject_t1756533147 * value)
	{
		___shp2_17 = value;
		Il2CppCodeGenWriteBarrier(&___shp2_17, value);
	}

	inline static int32_t get_offset_of_shp1_scr_18() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp1_scr_18)); }
	inline Ship1_t1303907657 * get_shp1_scr_18() const { return ___shp1_scr_18; }
	inline Ship1_t1303907657 ** get_address_of_shp1_scr_18() { return &___shp1_scr_18; }
	inline void set_shp1_scr_18(Ship1_t1303907657 * value)
	{
		___shp1_scr_18 = value;
		Il2CppCodeGenWriteBarrier(&___shp1_scr_18, value);
	}

	inline static int32_t get_offset_of_shp2_scr_19() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp2_scr_19)); }
	inline Ship2_t1303907656 * get_shp2_scr_19() const { return ___shp2_scr_19; }
	inline Ship2_t1303907656 ** get_address_of_shp2_scr_19() { return &___shp2_scr_19; }
	inline void set_shp2_scr_19(Ship2_t1303907656 * value)
	{
		___shp2_scr_19 = value;
		Il2CppCodeGenWriteBarrier(&___shp2_scr_19, value);
	}

	inline static int32_t get_offset_of_level3_course_data_20() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level3_course_data_20)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level3_course_data_20() const { return ___level3_course_data_20; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level3_course_data_20() { return &___level3_course_data_20; }
	inline void set_level3_course_data_20(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level3_course_data_20 = value;
		Il2CppCodeGenWriteBarrier(&___level3_course_data_20, value);
	}

	inline static int32_t get_offset_of_level2_course_data_21() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level2_course_data_21)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level2_course_data_21() const { return ___level2_course_data_21; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level2_course_data_21() { return &___level2_course_data_21; }
	inline void set_level2_course_data_21(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level2_course_data_21 = value;
		Il2CppCodeGenWriteBarrier(&___level2_course_data_21, value);
	}

	inline static int32_t get_offset_of_level1_course_data_22() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level1_course_data_22)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level1_course_data_22() const { return ___level1_course_data_22; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level1_course_data_22() { return &___level1_course_data_22; }
	inline void set_level1_course_data_22(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level1_course_data_22 = value;
		Il2CppCodeGenWriteBarrier(&___level1_course_data_22, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
