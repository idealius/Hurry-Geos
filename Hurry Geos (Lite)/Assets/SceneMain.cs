using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using nsLevelManager;

public class SceneMain : MonoBehaviour {

	public LevelManager g;
	GameObject shp1;
	GameObject shp2;
	GameObject c_obj;
	CameraTracker c_obj_script;

	void Start ()
	{

		shp1 = GameObject.Find("Ship1");
		shp2 = GameObject.Find("Ship2");
		c_obj = GameObject.Find("Camera");
		c_obj_script = c_obj.GetComponent<CameraTracker>();


		g = gameObject.AddComponent<LevelManager>();
		//Screen.SetResolution (750, 1334, false);
	
		g.PickLevel(1);

	}
	
	void FixedUpdate ()
	{
		GameInput();
		g.current_position += g.current.tickrate;
		g.UpdatePosition();
		
	}

	// public float distance_normalized(Vector3 vec1, Vector3 vec2, float threshold)
	// {
		
	// }

	void GameInput ()
	{
		
		float deltax = 0;
		Vector3 orbit1;
		Vector3 orbit2;
		Vector3 gas;
		float multiplier = 2.2f;
		
		if (shp1 == null || shp2 == null) return;

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
				g.current.tickrate = .2f;
				g.ChangeAlpha(shp1, .3f, false);
				g.ChangeAlpha(shp2, .3f, false);
				shp1.GetComponent<TrailRenderer>().enabled = false;
				shp1.transform.Find("GhostTrail").GetComponent<TrailRenderer>().enabled = true;
				shp2.GetComponent<TrailRenderer>().enabled = false;
				shp2.transform.Find("GhostTrail").GetComponent<TrailRenderer>().enabled = true;

			}
			else
			{
				multiplier = 2.2f;
				g.current.tickrate = .15f;
				g.ChangeAlpha(shp1, 1, false);
				g.ChangeAlpha(shp2, 1, false);
				shp1.GetComponent<TrailRenderer>().enabled = true;
				shp1.transform.Find("GhostTrail").GetComponent<TrailRenderer>().enabled = false;
				shp2.GetComponent<TrailRenderer>().enabled = true;
				shp2.transform.Find("GhostTrail").GetComponent<TrailRenderer>().enabled = false;

				
			}

		gas = new Vector3(0, 0, g.current.tickrate);

		orbit1 = new Vector3(0, 0, shp1.transform.position.z);
		orbit2 = new Vector3(0, 0, shp2.transform.position.z);

		shp1.transform.RotateAround(orbit1,  Vector3.forward, deltax * multiplier);
		shp1.transform.Translate(gas);
			
		shp2.transform.RotateAround(orbit2,  Vector3.forward, deltax * multiplier);
		shp2.transform.Translate(gas);

		
		Vector3 r0_c_dest = new Vector3(c_obj_script.r0_player_offset_x, c_obj_script.r0_player_offset_y, shp1.transform.position.z + c_obj_script.r0_player_offset_z);
		Vector3 r1_c_dest = new Vector3(c_obj_script.r1_player_offset_x, c_obj_script.r1_player_offset_y, shp1.transform.position.z + c_obj_script.r1_player_offset_z);


	
		
		if (g.radius_shift == 0)
		{
			// Move Ships towards center
			if (Vector3.Distance(shp1.transform.position, orbit1) > .7f)
			{
				shp1.transform.position = Vector3.MoveTowards(shp1.transform.position, orbit1, g.current.tickrate / 1.8f);
				shp2.transform.position = Vector3.MoveTowards(shp2.transform.position, orbit2, g.current.tickrate / 1.8f);
			}
			else
			{
				Vector3.ClampMagnitude(shp1.transform.position, .7f);
				Vector3.ClampMagnitude(shp2.transform.position, .7f);
				
			}
			// Move Camera
			if (Vector3.Distance(c_obj.transform.position, r0_c_dest) > 0)
			{
				 c_obj.transform.position = Vector3.MoveTowards(c_obj.transform.position, r0_c_dest, g.current.tickrate * 2);
				// c_obj_script.current_player_offset_z = Mathf.Lerp(c_obj_script.current_player_offset_z, c_obj_script.r0_player_offset_z, g.current_tickrate / 10);
					// print ("down");
			}
			
			 
		}
		else
		{
			// Move Ships away from center
			if (Vector3.Distance(shp1.transform.position, orbit1) < 2.5f)
			{
				Vector3 vec1 = new Vector3(shp1.transform.position.x * 1.08f, shp1.transform.position.y * 1.08f, shp1.transform.position.z);
				Vector3 vec2 = new Vector3(shp2.transform.position.x * 1.08f, shp2.transform.position.y * 1.08f, shp1.transform.position.z);
				shp1.transform.position = vec1;
				shp2.transform.position = vec2; 
			}
			else
			{
				Vector3.ClampMagnitude(shp1.transform.position, 2.5f);
				Vector3.ClampMagnitude(shp2.transform.position, 2.5f);
			}
			// Move Camera
			if (Vector3.Distance(c_obj.transform.position, r1_c_dest) > 0)
			{
				 c_obj.transform.position = Vector3.MoveTowards(c_obj.transform.position, r1_c_dest, g.current.tickrate);
				 	// print ("up");
				// c_obj_script.current_player_offset_z = Mathf.Lerp(c_obj_script.current_player_offset_z, c_obj_script.r1_player_offset_z, g.current_tickrate / 10);
			} 
				
		}


	}
}
