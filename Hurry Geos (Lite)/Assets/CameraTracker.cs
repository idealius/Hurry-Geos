using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraTracker : MonoBehaviour {
    public GameObject player;       //Public variable to store a reference to the player game object


    public float r0_player_offset_z = -5;
    public float r0_player_offset_y = 1;
    public float r0_player_offset_x = 0;


    public float r1_player_offset_z = -11.5f;    
    public float r1_player_offset_x = 0;    
    public float r1_player_offset_y = 0;    
    

    public float current_player_offset_z = 0;    
    public float current_player_offset_x = 0;    
    public float current_player_offset_y = 0;    



    
	// Use this for initialization
    void Start () {
		   
           player = GameObject.Find("Ship1");
           Initialize();
	}

    public void  Initialize()
    {
            current_player_offset_z = r1_player_offset_z;
           transform.position = new Vector3(r1_player_offset_x, r1_player_offset_y, r1_player_offset_z);
        
    }
	
	// Update is called once per frame
   void LateUpdate () 
    {
        
       // Vector3 cam_follower = new Vector3(transform.position.x + current_player_offset_x, transform.position.y + current_player_offset_y, player.transform.position.z + current_player_offset_z);
	//	transform.position = cam_follower;
    }
}
