using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ship1 : MonoBehaviour {


	public bool impact = false;
	public string bogey;

	public GameObject g_obj_bogey;
	

	// Use this for initialization
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
	
		
	}
	
}
