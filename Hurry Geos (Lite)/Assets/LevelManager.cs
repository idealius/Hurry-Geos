
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine;

namespace nsLevelManager {
	 public class LevelManager : MonoBehaviour{
	
		//Tracks player ships distance between each other
		public float radius_shift = 1;
		private float radius_signature;

		public float level1_start_position = 0;

		public float level2_start_position = 0;

		public float level3_start_position = 0;

		//public const float level_default_tickrate = .15F;
		public float level1_tickrate = .15f;
		public float level2_tickrate = .15f;
		public float level3_tickrate = .15f;

		
	
		//Ticker position throughout the level, bit by bit not by ring
		public int position; 
		public bool ring_position_updated;

		public int score;

		//Depth separation modifier, z axis separation between stroyds
		private float depth_separation_mod = 4;
	
		private int[][,] current_course_data;
		public float current_position;
		public int current_length;
		public float current_tickrate;

		public int current_level = 1;


		private List<GameObject>[] course_obj_list;


		private GameObject shp1;
		private GameObject shp2;

		private Ship1 shp1_scr;
		private Ship2 shp2_scr;

		void Start()
		{
				shp1 = GameObject.Find("Ship1");
				shp2 = GameObject.Find("Ship2");

				shp1_scr = shp1.GetComponent<Ship1>();
				shp2_scr = shp2.GetComponent<Ship2>();

		}
		
		public void UpdatePosition()
		{
			CheckforImpact();
			UpdatePositionCalc();
			if (ring_position_updated) UpdateRingPositionCalc();
			UpdateFramePositionCalc();
			
		}
		public void CheckforImpact()
		{
			
			if (shp1_scr == null || shp2_scr == null) return;
		
			if (shp1_scr.impact || shp2_scr.impact)
			{
				
				if (shp1_scr.bogey.Contains("amper") || shp2_scr.bogey.Contains("amper"))
				{
					
					// if (radius_signature != position)
					// {
					// 	radius_signature = position;
						if (radius_shift == 1) radius_shift = 0; else radius_shift = 1;
					// }
					if (shp1_scr.g_obj_bogey != null)
					{
					
						for (int i = course_obj_list[position].Count - 1; i > -1; i--)
						{
					
							if (course_obj_list[position][i].name.Contains("amper"))
							{
								DestroyImmediate(course_obj_list[position][i]);
								
								//course_obj_list[position][i] = null;
								course_obj_list[position].RemoveAt(i);
							}
						}
					}
					else if (shp2_scr.g_obj_bogey != null)
					{
						for (int i = course_obj_list[position].Count - 1; i > -1; i--)
						{
							if (course_obj_list[position][i].name.Contains("amper"))
							{
								DestroyImmediate(course_obj_list[position][i]);
								
								//course_obj_list[position][i] = null;
								course_obj_list[position].RemoveAt(i);
							}
						}
					}
				}
				else 
				{

					//AdvanceLevel level if at the end
					if (position+1 == current_length)
					{
						AdvanceLevel();
						
					}
					else
					{
						// print(position);
						// print(current_length);
						ResetLevel();
					}

				}
				//Since were checking for collision here instead of ship scripts we need to track and reset variables for the next
				//collision.
				shp1_scr.impact = false;
				shp2_scr.impact = false;
				shp1_scr.bogey = "";
				shp2_scr.bogey = "";

				
			}
	
		}

		public void UpdateScore()
		{
			Text t_score;
			t_score = GameObject.Find("Score").GetComponent<Text>();
			t_score.text = "Score: " + score;		
		}

		public void UpdatePositionCalc()
		{
			int prior_position = position;
			
			position = Mathf.CeilToInt(current_position / depth_separation_mod);

			if (prior_position != position) ring_position_updated = true;
			else ring_position_updated = false;
		}

		public void UpdateRingPositionCalc()
		{
			int limit_pos = position;

			if (position > current_length) limit_pos = current_length;
			if (position < 0) limit_pos = 0;	

			//Update Score
			if (limit_pos > 0)
			{
				if (course_obj_list[limit_pos-1].Count > 0)
				{
					score ++;
					UpdateScore(); 
				}

			}


			if (limit_pos > 1)
			{
			
				//Destroy course_objs past explode point (-2)
				foreach(GameObject course_obj in course_obj_list[limit_pos-2])
				{			
					Destroy(course_obj);
				}

				//AdvanceLevel level if at the end (more of a safeguard)
				if (position - 2 == current_length)
				{
					AdvanceLevel();
					return;
				}
			}

			//Add collider for each closely upcoming course_obj
			int limit_pos2 = limit_pos+1;
			if (limit_pos2 >= current_length) limit_pos2 = current_length-1;
			foreach(GameObject course_obj in course_obj_list[limit_pos2])
			{
				
				course_obj.AddComponent<SphereCollider>();
				course_obj.GetComponent<SphereCollider>().radius = .5f;// * course_obj.transform.localScale.x;
			}

		}

		public void UpdateFramePositionCalc()
		{
			position = Mathf.CeilToInt(current_position / depth_separation_mod);
		
			float camera_pos_z = -11.5f;
			int max = position + 6; //6 is based on camera view distance (aligned with Z axis)
			int limit_pos = position;

			if (shp1 != null) camera_pos_z =  shp1.transform.position.z - 11.5f;

			if (position > current_length) limit_pos = current_length;
			if (position < 0) limit_pos = 0;	
			if (max > current_length) max = current_length;
		
			//Color them to provide more contrast around the collision timing and fade in
			for (int i = limit_pos; i < max; i++)
			{
				foreach(GameObject course_obj in course_obj_list[i])
				{
					ChangeAlpha(course_obj, "highlight_particle", 1 - (course_obj.transform.position.z - camera_pos_z) / 25);
					MixMaterial(course_obj, "highlight_particle", "collide", 1 - (course_obj.transform.position.z - camera_pos_z) / 15);
				
				}

			}
						
			//Time.timeScale = .5f;
			
			//After passing a ring explode outward to make it more satisfying and fade a little as well
			if (limit_pos > 0)
			{
				foreach(GameObject course_obj in course_obj_list[limit_pos-1])
				{
			
					Vector3 new_delta;
					float deltax;
					float deltay;

					deltax = course_obj.transform.position.x / 30;
					deltay = course_obj.transform.position.y / 30;
					new_delta = new Vector3(deltax , deltay, 0);

					course_obj.transform.Translate(new_delta, Space.World);
					
					ChangeAlpha(course_obj, "highlight_particle", -.01f, true);

				}
			}

		}


		public void GenerateCourseObjects()
		{
			//Whether we create a new object in Unity editor and set scale to 0 and create instances off of that or go
			//straight to resource.load (which will create said object anyway) we need to hide it somehow
			
			GameObject inst_course_obj;
			
			//prefab_course_obj = (GameObject) Instantiate(Resources.Load("stroyd_1"));
			//prefab_course_obj.transform.localScale = new Vector3(0,0,0);
			

			
			//Main course_obj generating loop
			for (int z = 0; z < current_length; z++)
			{
				int w = (int)Mathf.Sqrt(current_course_data[z].Length);
				int h = w;
				for (int y = 0; y < h; y++)
				{	
					for (int x = 0; x < w; x++)
					{
						int a = current_course_data[z][y, x];
						if (a != 0)
						{
							Quaternion r_orientation;
							float x_offset;
							float y_offset;
							float fit_x;
							float fit_y;

							//Center
							x_offset = w / 2f - .5f;
							y_offset = h / 2f - .5f;

							
							//Scale the source field to the equivalent of 6 units
							fit_x = (x - x_offset) / (w / 6f);
							fit_y = -(y - y_offset) / (h / 6f);
							

							Vector3 r_position = new Vector3(fit_x, fit_y, z * depth_separation_mod);

							
							switch (a)
							{
							case 1:
						
								r_orientation = Quaternion.Euler( Random.Range(0, 360) , Random.Range(0, 360) , Random.Range(0, 360));
								
								inst_course_obj = (GameObject) Instantiate(GameObject.Find("stroyd_1"), r_position, r_orientation);
								inst_course_obj.transform.localScale = Vector3.one;
								break;

							case 6:

								r_orientation = Quaternion.identity;

								inst_course_obj = (GameObject) Instantiate(GameObject.Find("amper"), r_position, r_orientation);
								inst_course_obj.transform.localScale = Vector3.one;
								break;
							default:
								inst_course_obj = null;
								break;
							}

							if (inst_course_obj != null) course_obj_list[z].Add (inst_course_obj);

							//Scale the unit size so it can fit each into a 6x6 field
							float f_sc = 1f-(1f/(w/6f)); 
							Vector3 scale = new Vector3(f_sc, f_sc, f_sc);
						
							inst_course_obj.transform.localScale -= scale;
							ChangeAlpha(inst_course_obj, "highlight_particle", 0f);
						}
	      		  }
				}
			}
		}

	void MixMaterial(GameObject g_obj, string str_mesh, string str_dest_material, float avg)
		{
		
			Color orig_col;
			Material partner_mat;
			Color partner_col;
			Color output_col;
			foreach (Transform child in g_obj.transform) 
			{
				
				//orig_col = g_obj.transform.Find(str_mesh).GetComponent<Renderer>().material.color;
				orig_col = child.GetComponent<Renderer>().material.color;
				
				partner_mat = (Material) Resources.Load(str_dest_material, typeof(Material));
				partner_col = partner_mat.color;

				output_col.r = Mathf.Lerp(orig_col.r, partner_col.r, avg);
				output_col.g = Mathf.Lerp(orig_col.g, partner_col.g, avg);
				output_col.b = Mathf.Lerp(orig_col.b, partner_col.b, avg);
				output_col.a = orig_col.a;

				child.transform.GetComponent<Renderer>().material.color = output_col;
				
			}
			//g_obj.transform.Find(str_model).GetComponent<Renderer>().material = (Material) Resources.Load(str_dest_material, typeof(Material));
		}

		void ChangeAlpha (GameObject g_obj, string mesh, float alpha, bool by_delta)
		{
			Color orig_col;
			Color new_col;
			foreach (Transform child in g_obj.transform)
			{
				orig_col = child.transform.GetComponent<Renderer>().material.color;

				new_col.r = orig_col.r;
				new_col.g = orig_col.g;
				new_col.b = orig_col.b;
				if (by_delta) new_col.a = orig_col.a + alpha; else new_col.a = alpha;

				child.transform.GetComponent<Renderer>().material.color = new_col;
			}
		}
		void ChangeAlpha(GameObject g_obj, string mesh, float alpha)
		{
			ChangeAlpha(g_obj, mesh, alpha, false);
	
		}
		

		public void AdvanceLevel()
		{
		 switch(current_level)
		 {
			 case 1:
		
				 ClearLevel();
				 PickLevel(2);
				 current_level = 2;
				 break;
			 case 2:
			 	ClearLevel();
				 PickLevel(3);
			 	current_level = 3;
				 break;

			case 3:
			 	ClearLevel();
				 PickLevel(1);
			 	current_level = 1;
				 break;
			 default:
			 break;
		 }	
		 
		}

        public void PickLevel(int level)
		{


			current_level = level;

			switch (level)
			{
				case 1:
		
					current_length = level1_course_data.Length;
					//print("This:" + current_length);
					current_course_data = level1_course_data;
					current_position = level1_start_position;
					current_tickrate = level1_tickrate;
					
					break;

				case 2:

					current_length = level2_course_data.Length;
					//print("This:" + current_length);
					current_course_data = level2_course_data;
					current_position = level2_start_position;
					current_tickrate = level2_tickrate;
			

					break;

				case 3:

					current_length = level3_course_data.Length;
					//print("This:" + current_length);
					current_course_data = level3_course_data;
					current_position = level3_start_position;
					current_tickrate = level3_tickrate;
			

					break;



				default:
					break;
			}

					course_obj_list = new List<GameObject>[current_length];
								
					//Arrange course_objs by z sections
					for (int i = 0; i < current_length; i++)
				 		course_obj_list[i] = new List<GameObject>();

					GenerateCourseObjects();
		}

		public void ClearLevel()
		{
			GameObject c_obj;
			Vector3 obj1_start = new Vector3(-2.5f, 0, 0); 
			Vector3 obj2_start = new Vector3(2.5f, 0, 0); 
			
			//Make sure all course_objs are destroyed
			for (int i = 0; i<current_length; i++)
			{
				foreach(GameObject course_obj in course_obj_list[i])
				{
					DestroyImmediate(course_obj);
					
				}
				course_obj_list[i].Clear();
				
			}
			course_obj_list = null;

			score = 0;
			UpdateScore();


			radius_shift = 1;
			radius_signature = -1;

			c_obj = GameObject.Find("Camera");
			c_obj.GetComponent<CameraTracker>().Initialize();

			shp1.transform.position = obj1_start;
			shp2.transform.position = obj2_start;
			shp1.transform.rotation = Quaternion.Euler(0, 0, 0);
			shp2.transform.rotation = Quaternion.Euler(0, 0, 0);


		}

		public void ResetLevel()
		{
			ClearLevel();
			PickLevel(current_level);
		}

private int[][,] level3_course_data = new int[][,]
	{
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 6, 6, 0, 6, 6, 0 },
														{ 0, 6, 0, 0, 0, 6, 0 },
														{ 0, 6, 6, 0, 6, 6, 0 }, 
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },


										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 6, 6, 6, 0, 0 },
														{ 0, 0, 6, 6, 6, 0, 0 },
														{ 0, 0, 6, 6, 6, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 6, 6, 0, 6, 6, 0 },
														{ 0, 6, 0, 0, 0, 6, 0 },
														{ 0, 6, 6, 0, 6, 6, 0 }, 
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 6, 6, 6, 0, 0 },
														{ 0, 0, 6, 6, 6, 0, 0 },
														{ 0, 0, 6, 6, 6, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 6, 6, 1, 6, 6, 0 },
														{ 0, 6, 6, 6, 6, 6, 0 }, 
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 1, 1, 1, 1, 1, 0 },
														{ 0, 1, 6, 6, 6, 1, 0 },
														{ 0, 1, 6, 6, 6, 1, 0 },
														{ 0, 1, 6, 6, 6, 1, 0 }, 
														{ 0, 1, 1, 1, 1, 1, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 6, 6, 1, 6, 6, 0 },
														{ 0, 6, 6, 6, 6, 6, 0 }, 
														{ 0, 6, 6, 6, 6, 6, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },


										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 1, 1, 1, 1, 1, 0 },
														{ 0, 1, 6, 6, 6, 1, 0 },
														{ 0, 1, 6, 6, 6, 1, 0 },
														{ 0, 1, 6, 6, 6, 1, 0 }, 
														{ 0, 1, 1, 1, 1, 1, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },


											new int[,] { { 1 } }

			};
											
			
		
						

private int[][,] level2_course_data = new int[][,]
	{
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
						
										   new int[,] { { 0, 0, 1, 1, 0, 0 },
														{ 0, 6, 0, 0, 1, 0 },
														{ 1, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 1 },
														{ 0, 1, 0, 0, 6, 0 }, 
														{ 0, 0, 1, 1, 0, 0 } },

										   new int[,] { { 1, 1, 1, 1, 1, 1, 1 },
														{ 1, 1, 1, 1, 1, 1, 1 },
														{ 1, 1, 0, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 0, 1, 1 }, 
														{ 1, 1, 1, 1, 1, 1, 1 },
														{ 1, 1, 1, 1, 1, 1, 1 } },

									new int[,] { { 0 } },
									new int[,] { { 0 } },
									new int[,] { { 0 } },
									new int[,] { { 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 1, 1, 1, 1, 1, 0 },
														{ 0, 1, 0, 0, 0, 1, 0 },
														{ 0, 1, 0, 0, 0, 1, 0 },
														{ 0, 1, 0, 0, 0, 1, 0 }, 
														{ 0, 1, 1, 1, 1, 1, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 1, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 1, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 0, 0, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },

										   new int[,] { { 0, 1, 0, 0, 1, 0 },
														{ 0, 1, 0, 0, 1, 0 },
														{ 0, 1, 0, 0, 1, 0 },
														{ 0, 1, 0, 0, 1, 0 },
														{ 0, 1, 0, 0, 1, 0 }, 
														{ 0, 1, 0, 0, 1, 0 } },

											new int[,] { { 0 } },

										   new int[,] { { 1, 1, 1, 1, 1, 1 },
														{ 1, 1, 1, 1, 1, 1 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 1, 1, 1, 1, 1, 1 }, 
														{ 1, 1, 1, 1, 1, 1 } },


											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },

											

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 1, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 1, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 0, 0, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 1, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 1, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 0, 0, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },
																								   
										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 1, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },

										   new int[,] { { 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 6, 0, 1, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 0, 6, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0 } },


											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
										    new int[,] { { 0 } },

											
											new int[,] { { 0, 0, 1, 1, 0, 0 },
														{ 0, 1, 0, 0, 6, 0 },
														{ 1, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 1 },
														{ 0, 6, 0, 0, 1, 0 }, 
														{ 0, 0, 1, 1, 0, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },
											

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 6, 6, 0, 1 },
														{ 1, 0, 6, 6, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

											
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
	 										new int[,] { { 0 } },
	 										
											 		
											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },
											

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },
											 
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
	 										new int[,] { { 0 } },

											 new int[,] { { 1 } }};
															


	


		private int[][,] level1_course_data = new int[][,]
													{
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },
						
										   new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 }, 
														{ 0, 0, 0, 0, 0, 0 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },
										
											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 1, 1, 1, 1, 1, 1 },
														{ 1, 1, 1, 1, 1, 1 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 1, 1, 1, 1, 1, 1 }, 
														{ 1, 1, 1, 1, 1, 1 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 }, 
														{ 1, 1, 0, 0, 1, 1 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 0 } },
											
											new int[,] { { 0 } },

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },
											

											new int[,] { { 0, 1, 1, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 0, 0, 0, 0, 1, 1 }, 
														{ 0, 0, 0, 1, 1, 0 } },
											
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },
											
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
															

											new int[,] { { 1, 1, 1, 1, 1, 1 },
														{ 1, 1, 1, 1, 1, 1 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 1, 1, 1, 1, 1, 1 }, 
														{ 1, 1, 1, 1, 1, 1 } },

											new int[,] { { 0 } },

											new int[,] { { 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 }, 
														{ 1, 1, 0, 0, 1, 1 } },

											new int[,] { { 0 } },

											new int[,] { { 1, 1, 1, 1, 1, 1 },
														{ 1, 1, 1, 1, 1, 1 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 1, 1, 1, 1, 1, 1 }, 
														{ 1, 1, 1, 1, 1, 1 } },

											new int[,] { { 0 } },

											new int[,] { { 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 },
														{ 1, 1, 0, 0, 1, 1 }, 
														{ 1, 1, 0, 0, 1, 1 } },

											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },

											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

										   new int[,] { { 1, 1, 1, 0, 0, 0 },
														{ 1, 1, 1, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 1, 1, 1 }, 
														{ 0, 0, 1, 1, 1, 1 } },

	
											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

										   new int[,] { { 1, 1, 1, 0, 0, 0 },
														{ 1, 1, 1, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 1, 1, 1 }, 
														{ 0, 0, 1, 1, 1, 1 } },

											new int[,] { { 0, 0, 0, 1, 1, 0 },
														{ 0, 0, 0, 0, 1, 1 },
														{ 0, 0, 0, 0, 0, 1 },
														{ 1, 0, 0, 0, 0, 0 },
														{ 1, 1, 0, 0, 0, 0 }, 
														{ 0, 1, 1, 0, 0, 0 } },

										   new int[,] { { 1, 1, 1, 0, 0, 0 },
														{ 1, 1, 1, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 1, 1, 1 }, 
														{ 0, 0, 1, 1, 1, 1 } },

														
										

											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
								     	   new int[,] { { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0 },
														{ 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
														{ 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0 },
														{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1 },
														{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
														{ 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
														{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 } },

											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },
											new int[,] { { 0 } },



											new int[,] { { 1 } }

			};
											
			}
		}
// private int[][,] level1_course_data = new int[][,]
// 											  {
// 									 new int[,] { { 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 0 }, 
// 												  { 0, 0, 0, 0, 0, 0 } },
												
// 									 new int[,] { { 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 0 }, 
// 												  { 0, 0, 0, 0, 0, 0 } },

// 									new int[,] { { 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 0 }, 
// 												  { 0, 0, 0, 0, 0, 0 } },

// 									 new int[,] { { 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 0 }, 
// 												  { 0, 0, 0, 0, 0, 0 } },
	
// 									 new int[,] { { 0, 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 0, 0 },
// 												  { 1, 0, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 0, 0, 0 }, 
// 												  { 0, 1, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0, 0 } },


// 									 new int[,] { { 0, 0, 0, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 0, 0, 0 } },

// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 0, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 0, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 			 						 new int[,] { { 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 },
// 											      { 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0 },
// 											      { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
// 												  { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
// 												  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
// 												  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
// 												  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
// 												  { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
// 												  { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
// 												  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
// 												  { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
// 												  { 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
// 												  { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 },
// 												  { 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0 },
// 									  			  { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0 } },

// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },

// 									 new int[,] { { 0, 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 0, 0 },
// 												  { 1, 0, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 0, 0, 0 }, 
// 												  { 0, 1, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0, 0 } },
	
// 									 new int[,] { { 0, 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 0, 0 },
// 												  { 1, 0, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 0, 0, 0 }, 
// 												  { 0, 1, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0, 0 } },

// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0 } }, 

// 									 new int[,] { { 0, 0, 0, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 0, 0, 0 } },
												
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 0, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 0, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },

// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0 } }, 

// 									 new int[,] { { 0, 0, 0, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 0, 0, 0 } },
												
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 0, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 0, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },

// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0 } }, 

// 									 new int[,] { { 0, 0, 0, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 0, 0, 0 } },
												
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 0, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 0, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },

// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0 } }, 

// 									 new int[,] { { 0, 0, 0, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 0, 0, 0 } },
												
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 0, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 0, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },

// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0 } }, 

// 									 new int[,] { { 0, 0, 0, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 0, 0, 0 } },
												
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 0, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 0, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 0, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 0 },
// 												  { 0, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },

// 									 new int[,] { { 0, 0, 1, 1, 0, 0 },
// 											      { 0, 1, 0, 0, 0, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 0, 0, 0, 1, 0 }, 
// 												  { 0, 0, 1, 1, 0, 0 } },
		
// 									 new int[,] { { 0, 0, 1, 0, 0, 0 },
// 											      { 0, 1, 0, 0, 1, 0 },
// 											      { 1, 0, 0, 0, 0, 1 },
// 												  { 1, 0, 0, 0, 0, 1 },
// 												  { 0, 1, 0, 0, 1, 0 }, 
// 												  { 0, 0, 0, 1, 0, 0 } } };

	
	
// 	} 
