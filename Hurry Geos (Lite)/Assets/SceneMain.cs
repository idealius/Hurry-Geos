using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using nsLevelManager;

public class SceneMain : MonoBehaviour {


	public LevelManager g;
	GameObject g_obj1;
	GameObject g_obj2;
	GameObject c_obj;
	CameraTracker c_obj_script;

	void Start ()
	{

		g_obj1 = GameObject.Find("Ship1");
		g_obj2 = GameObject.Find("Ship2");
		c_obj = GameObject.Find("Camera");
		c_obj_script = c_obj.GetComponent<CameraTracker>();


		g = gameObject.AddComponent<LevelManager>();
		//Screen.SetResolution (750, 1334, false);
	
		g.PickLevel(1);

	}
	
	void FixedUpdate ()
	{
		GameInput();
		g.current_position += g.current_tickrate;
		g.UpdatePosition();
		
	}

	void GameInput ()
	{

		float deltax = 0;
		Vector3 orbit1;
		Vector3 orbit2;
		Vector3 gas = new Vector3(0, 0, g.current_tickrate);
		float multiplier = 2.2f;
		//Vector3 shp1_radius_shrink = new Vector3(g_obj1.transform.position.x, g_obj1.transform.position.y
		
		#if UNITY_EDITOR || UNITY_STANDALONE
      		float a = -Input.GetAxis("Horizontal");
			  if (a > 0) deltax = a + .5f;
			  else if (a < 0) deltax = a - .5f;
    	#endif

		#if UNITY_IOS || UNITY_ANDROID
		 if (Input.touchCount > 0)
		 	{
				 if (Input.touches[0].position.x > Screen.width / 2)
					deltax = -1.5f;
				 else
					deltax = 1.5f;
			 }
		#endif

		if (g.radius_shift == 0)
			{
				multiplier = 3.2f;
				g.current_tickrate = .2f;
			}
			else
			{
				multiplier = 2.2f;
				g.current_tickrate = .15f;
			}

		orbit1 = new Vector3(0, 0, g_obj1.transform.position.z);
		orbit2 = new Vector3(0, 0, g_obj2.transform.position.z);

		g_obj1.transform.RotateAround(orbit1,  Vector3.forward, deltax * multiplier);
		g_obj1.transform.Translate(gas);
			
		g_obj2.transform.RotateAround(orbit2,  Vector3.forward, deltax * multiplier);
		g_obj2.transform.Translate(gas);

		
		Vector3 r0_c_dest = new Vector3(c_obj_script.r0_player_offset_x, c_obj_script.r0_player_offset_y, g_obj1.transform.position.z + c_obj_script.r0_player_offset_z);
		Vector3 r1_c_dest = new Vector3(c_obj_script.r1_player_offset_x, c_obj_script.r1_player_offset_y, g_obj1.transform.position.z + c_obj_script.r1_player_offset_z);

	
		
		if (g.radius_shift == 0)
		{
			// Move Ships towards center
			if (Vector3.Distance(g_obj1.transform.position, orbit1) > .7f)
			{
				g_obj1.transform.position = Vector3.MoveTowards(g_obj1.transform.position, orbit1, g.current_tickrate / 1.8f);
				g_obj2.transform.position = Vector3.MoveTowards(g_obj2.transform.position, orbit2, g.current_tickrate / 1.8f);
			}
			// Move Camera
			if (Vector3.Distance(c_obj.transform.position, r0_c_dest) > 0)
			{
				 c_obj.transform.position = Vector3.MoveTowards(c_obj.transform.position, r0_c_dest, g.current_tickrate * 2);
				// c_obj_script.current_player_offset_z = Mathf.Lerp(c_obj_script.current_player_offset_z, c_obj_script.r0_player_offset_z, g.current_tickrate / 10);
					// print ("down");
			}
			
			 
		}
		else
		{
			// Move Ships away from center
			if (Vector3.Distance(g_obj1.transform.position, orbit1) < 2.5f)
			{
				Vector3 vec1 = new Vector3(g_obj1.transform.position.x * 1.08f, g_obj1.transform.position.y * 1.08f, g_obj1.transform.position.z);
				Vector3 vec2 = new Vector3(g_obj2.transform.position.x * 1.08f, g_obj2.transform.position.y * 1.08f, g_obj1.transform.position.z);
				g_obj1.transform.position = vec1;
				g_obj2.transform.position = vec2;
			}
			// Move Camera
			if (Vector3.Distance(c_obj.transform.position, r1_c_dest) > 0)
			{
				 c_obj.transform.position = Vector3.MoveTowards(c_obj.transform.position, r1_c_dest, g.current_tickrate);
				 	// print ("up");
				// c_obj_script.current_player_offset_z = Mathf.Lerp(c_obj_script.current_player_offset_z, c_obj_script.r1_player_offset_z, g.current_tickrate / 10);
			} 
				
		}


	}
}
