Shader "Transparent/Specular VertexLit with Z" {
	Properties {
	    _Color ("Main Color", Color) = (1,1,1,1)
	    _SpecColor ("Specular Color", Color) = (0.5, 0.5, 0.5, 1)
	     _Shininess ("Shininess", Range (0.01, 1)) = 0.078125
	    _MainTex ("Base (RGB) Trans (A)", 2D) = "white" {}
	}
 
	SubShader {
	    Tags {"RenderType"="Transparent" "Queue"="Transparent"}
	    // Render into depth buffer only
	    Pass {
	        ColorMask 0
	    }
	    // Render normally
	    Pass {
	        ZWrite Off
	        Blend SrcAlpha OneMinusSrcAlpha
	        ColorMask RGB
	        Material {
	            Diffuse [_Color]
	            Ambient [_Color]
            	Shininess [_Shininess]
	            Specular [_SpecColor]
	        }
	        Lighting On
			SeparateSpecular On
	        SetTexture [_MainTex] {
	            Combine texture * primary DOUBLE, texture * primary
	        } 
	    }
	}
}