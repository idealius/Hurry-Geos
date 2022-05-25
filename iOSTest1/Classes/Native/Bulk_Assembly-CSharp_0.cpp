#include "il2cpp-config.h"

#ifndef _MSC_VER
# include <alloca.h>
#else
# include <malloc.h>
#endif

#include <cstring>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <limits>
#include <assert.h>

// SceneMain
struct SceneMain_t1045915103;
// UnityEngine.GameObject
struct GameObject_t1756533147;
// System.Object
struct Il2CppObject;
// UnityEngine.Rigidbody
struct Rigidbody_t4233889191;

#include "class-internals.h"
#include "codegen/il2cpp-codegen.h"
#include "mscorlib_System_Array3829468939.h"
#include "AssemblyU2DCSharp_U3CModuleU3E3783534214.h"
#include "AssemblyU2DCSharp_U3CModuleU3E3783534214MethodDeclarations.h"
#include "AssemblyU2DCSharp_SceneMain1045915103.h"
#include "AssemblyU2DCSharp_SceneMain1045915103MethodDeclarations.h"
#include "mscorlib_System_Void1841601450.h"
#include "mscorlib_System_Collections_Generic_List_1_gen1125654279MethodDeclarations.h"
#include "UnityEngine_UnityEngine_MonoBehaviour1158329972MethodDeclarations.h"
#include "mscorlib_System_Collections_Generic_List_1_gen1125654279.h"
#include "UnityEngine_UnityEngine_Random1170710517MethodDeclarations.h"
#include "UnityEngine_UnityEngine_Quaternion4030073918MethodDeclarations.h"
#include "UnityEngine_UnityEngine_Object1021602117MethodDeclarations.h"
#include "UnityEngine_UnityEngine_GameObject1756533147MethodDeclarations.h"
#include "UnityEngine_UnityEngine_Vector32243707580MethodDeclarations.h"
#include "UnityEngine_UnityEngine_Transform3275118058MethodDeclarations.h"
#include "mscorlib_System_Int322071877448.h"
#include "UnityEngine_UnityEngine_Vector32243707580.h"
#include "UnityEngine_UnityEngine_Quaternion4030073918.h"
#include "mscorlib_System_Single2076509932.h"
#include "UnityEngine_UnityEngine_GameObject1756533147.h"
#include "UnityEngine_UnityEngine_Object1021602117.h"
#include "UnityEngine_UnityEngine_Transform3275118058.h"
#include "UnityEngine_UnityEngine_Input1785128008MethodDeclarations.h"
#include "UnityEngine_UnityEngine_Rigidbody4233889191MethodDeclarations.h"
#include "UnityEngine_UnityEngine_Rigidbody4233889191.h"
#include "mscorlib_System_Collections_Generic_List_1_Enumerat660383953.h"
#include "mscorlib_System_String2029220233.h"
#include "mscorlib_System_Collections_Generic_List_1_Enumerat660383953MethodDeclarations.h"
#include "mscorlib_System_Boolean3825574718.h"

// !!0 UnityEngine.Object::Instantiate<System.Object>(!!0,UnityEngine.Vector3,UnityEngine.Quaternion)
extern "C"  Il2CppObject * Object_Instantiate_TisIl2CppObject_m3829784634_gshared (Il2CppObject * __this /* static, unused */, Il2CppObject * p0, Vector3_t2243707580  p1, Quaternion_t4030073918  p2, const MethodInfo* method);
#define Object_Instantiate_TisIl2CppObject_m3829784634(__this /* static, unused */, p0, p1, p2, method) ((  Il2CppObject * (*) (Il2CppObject * /* static, unused */, Il2CppObject *, Vector3_t2243707580 , Quaternion_t4030073918 , const MethodInfo*))Object_Instantiate_TisIl2CppObject_m3829784634_gshared)(__this /* static, unused */, p0, p1, p2, method)
// !!0 UnityEngine.Object::Instantiate<UnityEngine.GameObject>(!!0,UnityEngine.Vector3,UnityEngine.Quaternion)
#define Object_Instantiate_TisGameObject_t1756533147_m3064851704(__this /* static, unused */, p0, p1, p2, method) ((  GameObject_t1756533147 * (*) (Il2CppObject * /* static, unused */, GameObject_t1756533147 *, Vector3_t2243707580 , Quaternion_t4030073918 , const MethodInfo*))Object_Instantiate_TisIl2CppObject_m3829784634_gshared)(__this /* static, unused */, p0, p1, p2, method)
// !!0 UnityEngine.GameObject::GetComponent<System.Object>()
extern "C"  Il2CppObject * GameObject_GetComponent_TisIl2CppObject_m3347661153_gshared (GameObject_t1756533147 * __this, const MethodInfo* method);
#define GameObject_GetComponent_TisIl2CppObject_m3347661153(__this, method) ((  Il2CppObject * (*) (GameObject_t1756533147 *, const MethodInfo*))GameObject_GetComponent_TisIl2CppObject_m3347661153_gshared)(__this, method)
// !!0 UnityEngine.GameObject::GetComponent<UnityEngine.Rigidbody>()
#define GameObject_GetComponent_TisRigidbody_t4233889191_m1060888193(__this, method) ((  Rigidbody_t4233889191 * (*) (GameObject_t1756533147 *, const MethodInfo*))GameObject_GetComponent_TisIl2CppObject_m3347661153_gshared)(__this, method)
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// System.Void SceneMain::.ctor()
extern Il2CppClass* List_1_t1125654279_il2cpp_TypeInfo_var;
extern const MethodInfo* List_1__ctor_m3094264809_MethodInfo_var;
extern const uint32_t SceneMain__ctor_m3928308984_MetadataUsageId;
extern "C"  void SceneMain__ctor_m3928308984 (SceneMain_t1045915103 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (SceneMain__ctor_m3928308984_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	{
		List_1_t1125654279 * L_0 = (List_1_t1125654279 *)il2cpp_codegen_object_new(List_1_t1125654279_il2cpp_TypeInfo_var);
		List_1__ctor_m3094264809(L_0, /*hidden argument*/List_1__ctor_m3094264809_MethodInfo_var);
		__this->set_asteroid_list_7(L_0);
		MonoBehaviour__ctor_m2464341955(__this, /*hidden argument*/NULL);
		return;
	}
}
// System.Void SceneMain::Start()
extern Il2CppClass* Object_t1021602117_il2cpp_TypeInfo_var;
extern const MethodInfo* Object_Instantiate_TisGameObject_t1756533147_m3064851704_MethodInfo_var;
extern const MethodInfo* List_1_Add_m3815825701_MethodInfo_var;
extern const uint32_t SceneMain_Start_m821503012_MetadataUsageId;
extern "C"  void SceneMain_Start_m821503012 (SceneMain_t1045915103 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (SceneMain_Start_m821503012_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	int32_t V_0 = 0;
	Vector3_t2243707580  V_1;
	memset(&V_1, 0, sizeof(V_1));
	Quaternion_t4030073918  V_2;
	memset(&V_2, 0, sizeof(V_2));
	Vector3_t2243707580  V_3;
	memset(&V_3, 0, sizeof(V_3));
	{
		V_0 = 0;
		goto IL_00dc;
	}

IL_0008:
	{
		float L_0 = __this->get_Spread_5();
		float L_1 = __this->get_Spread_5();
		float L_2 = Random_Range_m2884721203(NULL /*static, unused*/, ((-L_0)), L_1, /*hidden argument*/NULL);
		float L_3 = __this->get_Spread_5();
		float L_4 = __this->get_Spread_5();
		float L_5 = Random_Range_m2884721203(NULL /*static, unused*/, ((-L_3)), L_4, /*hidden argument*/NULL);
		Vector3__ctor_m2638739322((&V_1), L_2, L_5, (0.0f), /*hidden argument*/NULL);
		int32_t L_6 = Random_Range_m694320887(NULL /*static, unused*/, 0, ((int32_t)360), /*hidden argument*/NULL);
		int32_t L_7 = Random_Range_m694320887(NULL /*static, unused*/, 0, ((int32_t)360), /*hidden argument*/NULL);
		int32_t L_8 = Random_Range_m694320887(NULL /*static, unused*/, 0, ((int32_t)360), /*hidden argument*/NULL);
		Quaternion_t4030073918  L_9 = Quaternion_Euler_m2887458175(NULL /*static, unused*/, (((float)((float)L_6))), (((float)((float)L_7))), (((float)((float)L_8))), /*hidden argument*/NULL);
		V_2 = L_9;
		GameObject_t1756533147 * L_10 = __this->get_pAsteroid_4();
		Vector3_t2243707580  L_11 = V_1;
		Quaternion_t4030073918  L_12 = V_2;
		IL2CPP_RUNTIME_CLASS_INIT(Object_t1021602117_il2cpp_TypeInfo_var);
		GameObject_t1756533147 * L_13 = Object_Instantiate_TisGameObject_t1756533147_m3064851704(NULL /*static, unused*/, L_10, L_11, L_12, /*hidden argument*/Object_Instantiate_TisGameObject_t1756533147_m3064851704_MethodInfo_var);
		__this->set_prefabAsteroid_6(L_13);
		List_1_t1125654279 * L_14 = __this->get_asteroid_list_7();
		GameObject_t1756533147 * L_15 = __this->get_prefabAsteroid_6();
		NullCheck(L_14);
		List_1_Add_m3815825701(L_14, L_15, /*hidden argument*/List_1_Add_m3815825701_MethodInfo_var);
		GameObject_t1756533147 * L_16 = __this->get_prefabAsteroid_6();
		NullCheck(L_16);
		Transform_t3275118058 * L_17 = GameObject_get_transform_m909382139(L_16, /*hidden argument*/NULL);
		Vector3_t2243707580  L_18 = Vector3_get_zero_m1527993324(NULL /*static, unused*/, /*hidden argument*/NULL);
		Vector3_t2243707580  L_19 = Vector3_get_up_m2725403797(NULL /*static, unused*/, /*hidden argument*/NULL);
		NullCheck(L_17);
		Transform_RotateAround_m3410686872(L_17, L_18, L_19, (-45.0f), /*hidden argument*/NULL);
		Vector3__ctor_m2638739322((&V_3), (1.0f), (1.0f), (0.0f), /*hidden argument*/NULL);
		GameObject_t1756533147 * L_20 = __this->get_prefabAsteroid_6();
		NullCheck(L_20);
		Transform_t3275118058 * L_21 = GameObject_get_transform_m909382139(L_20, /*hidden argument*/NULL);
		Vector3_t2243707580  L_22 = Vector3_get_zero_m1527993324(NULL /*static, unused*/, /*hidden argument*/NULL);
		Vector3_t2243707580  L_23 = V_3;
		NullCheck(L_21);
		Transform_RotateAround_m3410686872(L_21, L_22, L_23, (-45.0f), /*hidden argument*/NULL);
		int32_t L_24 = V_0;
		V_0 = ((int32_t)((int32_t)L_24+(int32_t)1));
	}

IL_00dc:
	{
		int32_t L_25 = V_0;
		int32_t L_26 = __this->get_AsteroidAmount_2();
		if ((((int32_t)L_25) < ((int32_t)L_26)))
		{
			goto IL_0008;
		}
	}
	{
		return;
	}
}
// System.Void SceneMain::FixedUpdate()
extern Il2CppClass* Input_t1785128008_il2cpp_TypeInfo_var;
extern const MethodInfo* List_1_GetEnumerator_m970439620_MethodInfo_var;
extern const MethodInfo* Enumerator_get_Current_m2389888842_MethodInfo_var;
extern const MethodInfo* GameObject_GetComponent_TisRigidbody_t4233889191_m1060888193_MethodInfo_var;
extern const MethodInfo* Enumerator_MoveNext_m3635305532_MethodInfo_var;
extern const MethodInfo* Enumerator_Dispose_m1242097970_MethodInfo_var;
extern Il2CppCodeGenString* _stringLiteral855845486;
extern Il2CppCodeGenString* _stringLiteral1635882288;
extern const uint32_t SceneMain_FixedUpdate_m839638201_MetadataUsageId;
extern "C"  void SceneMain_FixedUpdate_m839638201 (SceneMain_t1045915103 * __this, const MethodInfo* method)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_method (SceneMain_FixedUpdate_m839638201_MetadataUsageId);
		s_Il2CppMethodInitialized = true;
	}
	Rigidbody_t4233889191 * V_0 = NULL;
	float V_1 = 0.0f;
	float V_2 = 0.0f;
	Vector3_t2243707580  V_3;
	memset(&V_3, 0, sizeof(V_3));
	GameObject_t1756533147 * V_4 = NULL;
	Enumerator_t660383953  V_5;
	memset(&V_5, 0, sizeof(V_5));
	Exception_t1927440687 * __last_unhandled_exception = 0;
	NO_UNUSED_WARNING (__last_unhandled_exception);
	Exception_t1927440687 * __exception_local = 0;
	NO_UNUSED_WARNING (__exception_local);
	int32_t __leave_target = 0;
	NO_UNUSED_WARNING (__leave_target);
	{
		IL2CPP_RUNTIME_CLASS_INIT(Input_t1785128008_il2cpp_TypeInfo_var);
		float L_0 = Input_GetAxis_m2098048324(NULL /*static, unused*/, _stringLiteral855845486, /*hidden argument*/NULL);
		V_1 = L_0;
		float L_1 = Input_GetAxis_m2098048324(NULL /*static, unused*/, _stringLiteral1635882288, /*hidden argument*/NULL);
		V_2 = L_1;
		float L_2 = V_1;
		float L_3 = V_2;
		Vector3__ctor_m2638739322((&V_3), ((-L_2)), (0.0f), ((-L_3)), /*hidden argument*/NULL);
		List_1_t1125654279 * L_4 = __this->get_asteroid_list_7();
		NullCheck(L_4);
		Enumerator_t660383953  L_5 = List_1_GetEnumerator_m970439620(L_4, /*hidden argument*/List_1_GetEnumerator_m970439620_MethodInfo_var);
		V_5 = L_5;
	}

IL_0035:
	try
	{ // begin try (depth: 1)
		{
			goto IL_0060;
		}

IL_003a:
		{
			GameObject_t1756533147 * L_6 = Enumerator_get_Current_m2389888842((&V_5), /*hidden argument*/Enumerator_get_Current_m2389888842_MethodInfo_var);
			V_4 = L_6;
			GameObject_t1756533147 * L_7 = V_4;
			NullCheck(L_7);
			Rigidbody_t4233889191 * L_8 = GameObject_GetComponent_TisRigidbody_t4233889191_m1060888193(L_7, /*hidden argument*/GameObject_GetComponent_TisRigidbody_t4233889191_m1060888193_MethodInfo_var);
			V_0 = L_8;
			Rigidbody_t4233889191 * L_9 = V_0;
			Vector3_t2243707580  L_10 = V_3;
			int32_t L_11 = __this->get_Thrust_3();
			Vector3_t2243707580  L_12 = Vector3_op_Multiply_m1351554733(NULL /*static, unused*/, L_10, (((float)((float)L_11))), /*hidden argument*/NULL);
			NullCheck(L_9);
			Rigidbody_AddForce_m2836187433(L_9, L_12, /*hidden argument*/NULL);
		}

IL_0060:
		{
			bool L_13 = Enumerator_MoveNext_m3635305532((&V_5), /*hidden argument*/Enumerator_MoveNext_m3635305532_MethodInfo_var);
			if (L_13)
			{
				goto IL_003a;
			}
		}

IL_006c:
		{
			IL2CPP_LEAVE(0x7F, FINALLY_0071);
		}
	} // end try (depth: 1)
	catch(Il2CppExceptionWrapper& e)
	{
		__last_unhandled_exception = (Exception_t1927440687 *)e.ex;
		goto FINALLY_0071;
	}

FINALLY_0071:
	{ // begin finally (depth: 1)
		Enumerator_Dispose_m1242097970((&V_5), /*hidden argument*/Enumerator_Dispose_m1242097970_MethodInfo_var);
		IL2CPP_END_FINALLY(113)
	} // end finally (depth: 1)
	IL2CPP_CLEANUP(113)
	{
		IL2CPP_JUMP_TBL(0x7F, IL_007f)
		IL2CPP_RETHROW_IF_UNHANDLED(Exception_t1927440687 *)
	}

IL_007f:
	{
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
