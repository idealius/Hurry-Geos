using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Ship2 : MonoBehaviour {

	public bool impact = false;
	public string bogey;
	// Use this for initialization
	public GameObject g_obj_bogey;

	public int collide_side;

	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
	}

	void OnTriggerEnter(Collider other)
	{

		impact = true;
			
		bogey = other.name;

		g_obj_bogey = other.gameObject;

		Vector3 direction = other.transform.position - transform.position;

		if (Vector3.Dot (transform.forward, direction) > 0) {
			collide_side = 1;
		} 
		if (Vector3.Dot (transform.forward, direction) <= 0) {
	
			collide_side = 0;
		} 
		
	}
}
