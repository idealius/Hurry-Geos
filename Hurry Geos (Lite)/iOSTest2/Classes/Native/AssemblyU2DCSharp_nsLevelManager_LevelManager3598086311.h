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
// Ship
struct Ship_t1116303770;

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
	// System.Int32 nsLevelManager.LevelManager::radius_shift
	int32_t ___radius_shift_2;
	// System.Int32 nsLevelManager.LevelManager::x_rot_axis
	int32_t ___x_rot_axis_3;
	// level nsLevelManager.LevelManager::lvl1
	level_t866812534  ___lvl1_4;
	// level nsLevelManager.LevelManager::lvl2
	level_t866812534  ___lvl2_5;
	// level nsLevelManager.LevelManager::lvl3
	level_t866812534  ___lvl3_6;
	// level nsLevelManager.LevelManager::current
	level_t866812534  ___current_7;
	// System.Int32 nsLevelManager.LevelManager::position
	int32_t ___position_8;
	// System.Boolean nsLevelManager.LevelManager::ring_position_updated
	bool ___ring_position_updated_9;
	// System.Int32 nsLevelManager.LevelManager::score
	int32_t ___score_10;
	// System.Single nsLevelManager.LevelManager::depth_separation_mod
	float ___depth_separation_mod_11;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::current_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___current_course_data_12;
	// System.Single nsLevelManager.LevelManager::current_position
	float ___current_position_13;
	// System.Int32 nsLevelManager.LevelManager::current_length
	int32_t ___current_length_14;
	// System.Int32 nsLevelManager.LevelManager::current_level
	int32_t ___current_level_15;
	// System.Collections.Generic.List`1<UnityEngine.GameObject>[] nsLevelManager.LevelManager::course_obj_list
	List_1U5BU5D_t3122329854* ___course_obj_list_16;
	// UnityEngine.GameObject nsLevelManager.LevelManager::shp1
	GameObject_t1756533147 * ___shp1_17;
	// UnityEngine.GameObject nsLevelManager.LevelManager::shp2
	GameObject_t1756533147 * ___shp2_18;
	// Ship nsLevelManager.LevelManager::shp1_scr
	Ship_t1116303770 * ___shp1_scr_19;
	// Ship nsLevelManager.LevelManager::shp2_scr
	Ship_t1116303770 * ___shp2_scr_20;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level3_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level3_course_data_21;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level2_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level2_course_data_22;
	// System.Int32[0...,0...][] nsLevelManager.LevelManager::level1_course_data
	Int32U5BU2CU5DU5BU5D_t4237006271* ___level1_course_data_23;

public:
	inline static int32_t get_offset_of_radius_shift_2() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___radius_shift_2)); }
	inline int32_t get_radius_shift_2() const { return ___radius_shift_2; }
	inline int32_t* get_address_of_radius_shift_2() { return &___radius_shift_2; }
	inline void set_radius_shift_2(int32_t value)
	{
		___radius_shift_2 = value;
	}

	inline static int32_t get_offset_of_x_rot_axis_3() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___x_rot_axis_3)); }
	inline int32_t get_x_rot_axis_3() const { return ___x_rot_axis_3; }
	inline int32_t* get_address_of_x_rot_axis_3() { return &___x_rot_axis_3; }
	inline void set_x_rot_axis_3(int32_t value)
	{
		___x_rot_axis_3 = value;
	}

	inline static int32_t get_offset_of_lvl1_4() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___lvl1_4)); }
	inline level_t866812534  get_lvl1_4() const { return ___lvl1_4; }
	inline level_t866812534 * get_address_of_lvl1_4() { return &___lvl1_4; }
	inline void set_lvl1_4(level_t866812534  value)
	{
		___lvl1_4 = value;
	}

	inline static int32_t get_offset_of_lvl2_5() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___lvl2_5)); }
	inline level_t866812534  get_lvl2_5() const { return ___lvl2_5; }
	inline level_t866812534 * get_address_of_lvl2_5() { return &___lvl2_5; }
	inline void set_lvl2_5(level_t866812534  value)
	{
		___lvl2_5 = value;
	}

	inline static int32_t get_offset_of_lvl3_6() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___lvl3_6)); }
	inline level_t866812534  get_lvl3_6() const { return ___lvl3_6; }
	inline level_t866812534 * get_address_of_lvl3_6() { return &___lvl3_6; }
	inline void set_lvl3_6(level_t866812534  value)
	{
		___lvl3_6 = value;
	}

	inline static int32_t get_offset_of_current_7() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_7)); }
	inline level_t866812534  get_current_7() const { return ___current_7; }
	inline level_t866812534 * get_address_of_current_7() { return &___current_7; }
	inline void set_current_7(level_t866812534  value)
	{
		___current_7 = value;
	}

	inline static int32_t get_offset_of_position_8() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___position_8)); }
	inline int32_t get_position_8() const { return ___position_8; }
	inline int32_t* get_address_of_position_8() { return &___position_8; }
	inline void set_position_8(int32_t value)
	{
		___position_8 = value;
	}

	inline static int32_t get_offset_of_ring_position_updated_9() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___ring_position_updated_9)); }
	inline bool get_ring_position_updated_9() const { return ___ring_position_updated_9; }
	inline bool* get_address_of_ring_position_updated_9() { return &___ring_position_updated_9; }
	inline void set_ring_position_updated_9(bool value)
	{
		___ring_position_updated_9 = value;
	}

	inline static int32_t get_offset_of_score_10() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___score_10)); }
	inline int32_t get_score_10() const { return ___score_10; }
	inline int32_t* get_address_of_score_10() { return &___score_10; }
	inline void set_score_10(int32_t value)
	{
		___score_10 = value;
	}

	inline static int32_t get_offset_of_depth_separation_mod_11() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___depth_separation_mod_11)); }
	inline float get_depth_separation_mod_11() const { return ___depth_separation_mod_11; }
	inline float* get_address_of_depth_separation_mod_11() { return &___depth_separation_mod_11; }
	inline void set_depth_separation_mod_11(float value)
	{
		___depth_separation_mod_11 = value;
	}

	inline static int32_t get_offset_of_current_course_data_12() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_course_data_12)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_current_course_data_12() const { return ___current_course_data_12; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_current_course_data_12() { return &___current_course_data_12; }
	inline void set_current_course_data_12(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___current_course_data_12 = value;
		Il2CppCodeGenWriteBarrier(&___current_course_data_12, value);
	}

	inline static int32_t get_offset_of_current_position_13() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_position_13)); }
	inline float get_current_position_13() const { return ___current_position_13; }
	inline float* get_address_of_current_position_13() { return &___current_position_13; }
	inline void set_current_position_13(float value)
	{
		___current_position_13 = value;
	}

	inline static int32_t get_offset_of_current_length_14() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_length_14)); }
	inline int32_t get_current_length_14() const { return ___current_length_14; }
	inline int32_t* get_address_of_current_length_14() { return &___current_length_14; }
	inline void set_current_length_14(int32_t value)
	{
		___current_length_14 = value;
	}

	inline static int32_t get_offset_of_current_level_15() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___current_level_15)); }
	inline int32_t get_current_level_15() const { return ___current_level_15; }
	inline int32_t* get_address_of_current_level_15() { return &___current_level_15; }
	inline void set_current_level_15(int32_t value)
	{
		___current_level_15 = value;
	}

	inline static int32_t get_offset_of_course_obj_list_16() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___course_obj_list_16)); }
	inline List_1U5BU5D_t3122329854* get_course_obj_list_16() const { return ___course_obj_list_16; }
	inline List_1U5BU5D_t3122329854** get_address_of_course_obj_list_16() { return &___course_obj_list_16; }
	inline void set_course_obj_list_16(List_1U5BU5D_t3122329854* value)
	{
		___course_obj_list_16 = value;
		Il2CppCodeGenWriteBarrier(&___course_obj_list_16, value);
	}

	inline static int32_t get_offset_of_shp1_17() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp1_17)); }
	inline GameObject_t1756533147 * get_shp1_17() const { return ___shp1_17; }
	inline GameObject_t1756533147 ** get_address_of_shp1_17() { return &___shp1_17; }
	inline void set_shp1_17(GameObject_t1756533147 * value)
	{
		___shp1_17 = value;
		Il2CppCodeGenWriteBarrier(&___shp1_17, value);
	}

	inline static int32_t get_offset_of_shp2_18() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp2_18)); }
	inline GameObject_t1756533147 * get_shp2_18() const { return ___shp2_18; }
	inline GameObject_t1756533147 ** get_address_of_shp2_18() { return &___shp2_18; }
	inline void set_shp2_18(GameObject_t1756533147 * value)
	{
		___shp2_18 = value;
		Il2CppCodeGenWriteBarrier(&___shp2_18, value);
	}

	inline static int32_t get_offset_of_shp1_scr_19() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp1_scr_19)); }
	inline Ship_t1116303770 * get_shp1_scr_19() const { return ___shp1_scr_19; }
	inline Ship_t1116303770 ** get_address_of_shp1_scr_19() { return &___shp1_scr_19; }
	inline void set_shp1_scr_19(Ship_t1116303770 * value)
	{
		___shp1_scr_19 = value;
		Il2CppCodeGenWriteBarrier(&___shp1_scr_19, value);
	}

	inline static int32_t get_offset_of_shp2_scr_20() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___shp2_scr_20)); }
	inline Ship_t1116303770 * get_shp2_scr_20() const { return ___shp2_scr_20; }
	inline Ship_t1116303770 ** get_address_of_shp2_scr_20() { return &___shp2_scr_20; }
	inline void set_shp2_scr_20(Ship_t1116303770 * value)
	{
		___shp2_scr_20 = value;
		Il2CppCodeGenWriteBarrier(&___shp2_scr_20, value);
	}

	inline static int32_t get_offset_of_level3_course_data_21() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level3_course_data_21)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level3_course_data_21() const { return ___level3_course_data_21; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level3_course_data_21() { return &___level3_course_data_21; }
	inline void set_level3_course_data_21(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level3_course_data_21 = value;
		Il2CppCodeGenWriteBarrier(&___level3_course_data_21, value);
	}

	inline static int32_t get_offset_of_level2_course_data_22() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level2_course_data_22)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level2_course_data_22() const { return ___level2_course_data_22; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level2_course_data_22() { return &___level2_course_data_22; }
	inline void set_level2_course_data_22(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level2_course_data_22 = value;
		Il2CppCodeGenWriteBarrier(&___level2_course_data_22, value);
	}

	inline static int32_t get_offset_of_level1_course_data_23() { return static_cast<int32_t>(offsetof(LevelManager_t3598086311, ___level1_course_data_23)); }
	inline Int32U5BU2CU5DU5BU5D_t4237006271* get_level1_course_data_23() const { return ___level1_course_data_23; }
	inline Int32U5BU2CU5DU5BU5D_t4237006271** get_address_of_level1_course_data_23() { return &___level1_course_data_23; }
	inline void set_level1_course_data_23(Int32U5BU2CU5DU5BU5D_t4237006271* value)
	{
		___level1_course_data_23 = value;
		Il2CppCodeGenWriteBarrier(&___level1_course_data_23, value);
	}
};

#ifdef __clang__
#pragma clang diagnostic pop
#endif
