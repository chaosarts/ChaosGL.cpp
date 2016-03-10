#version 150

const int nLights = 2;

// die Texturen
uniform sampler2D   tDiffuse;
uniform sampler2D   tBumpmap;

uniform vec3 vCameraPosition;
uniform vec3 lightPositionWS[ nLights ];
uniform vec4 lightColor     [ nLights ];

in vec3 vNormal;
in vec3 vWorldPosition;
in vec2 vTexCoord[7];

// zum Vergleich: Beleuchtung pro Vertex
in vec4 cPerVertexLighting;

// Gamma-Wert
uniform float gamma;

// -1  -- per Vertex Beleuchtung
//  0  -- per Pixel Beleuchtung
//  1  -- diffuse Beleuchtung, ohne Bumpmaps
//  2  -- diffuse Beleuchtung, einfaches Texturemapping
//  3  -- Ambient Occlusion only
//  4  -- diffuse Beleuchtung, mit Bumpmaps
//  5  -- diffuse Beleuchtung, mit Bumpmaps und Texturen
//  6  -- diffuse Beleuchtung, mit Bumpmaps, Texturen und Ambient Occlusion
//  7  -- diffuse & spekulare Beleuchtung, mit Bumpmaps, Texturen und Ambient Occlusion
//  8  -- diffuse & spekulare Beleuchtung, mit Bumpmaps, Texturen und Ambient Occlusion, und Glossmaps
//  9  -- diffuse & spekulare Beleuchtung, mit Bumpmaps und Ambient Occlusion, und Glossmaps aber OHNE Texturen
uniform int renderMode;


out vec4 glFragColor;


void computeLighting(in vec3 lightPositionWS, in mat3 matTangentSpace,
					 in vec3 normalTS, out float diffuse, out float specular)
{
	//
	// Aufgabe 2
	//
	// Beleuchtungsberechnung mit
	// lightPositionWS, vCameraPosition, vWorldPosition und vNormal
	//vec3 lightWS   = ...;
	//vec3 viewWS    = ...;
	//...
	//diffuse = ...;
	//specular = ...;
	
	diffuse  = 0.0;
	specular = 0.0;
	
	//
	// Aufgabe 3
	//
	
	if (renderMode >= 4 && renderMode <= 9)
	{
		// Normal mapping
		//vec3 lightTS = ...;
		//vec3 viewTS = ...;
		//...
		//diffuse = ...;
		//specular = ...;
	}
}

// Diese Funktion erzeugt EINEN Tangent-Frame für eine gegebene Normale.
void computeTangentSpace(in vec3 N, out mat3 TS)
{
	vec3 NeverCoLinear = vec3( N.y, N.z, -N.x );
	vec3 T = normalize( cross( NeverCoLinear, N ) );
	vec3 B = cross( N, T );
	TS = mat3( T, B, N );
}


void main()
{
	// Die Oberflächenfarbe ist in der Textur in Rot/Grün/Blau Kanälen gespeichert,
	// der Alpha Kanal wird für den Ambient Occlusion Wert verwendet
	vec4	texColor   = texture(tDiffuse, vTexCoord[0]);
	
	//
	// Aufgabe 4
	//
	// Gamma-Korrektur
	//texColor.rgb = ...;
	
	// Die Tangent-Space-Normale ist farbkodiert in einer 8 Bit Textur gespeichert.
	// Da 8 Bit Texturen den Wertebereich von [0; 1] haben (wenn wir den Wert im Shader auslesen,
	// im Speicher natürlich [0; 255]), müssen wir ihn auf das Intervall [-1; 1] abbilden => "* 2 - 1"
	vec4	normalTS   = texture( tBumpmap, vTexCoord[ 0 ] ) * 2.0 - vec4( 1.0 );
	
	// Die "glossiness" kann in Texturen vorgegeben sein, oder wie hier, aus der Farbtextur
	// bestimmt werden. Wir berechnen der Wert so, dass helle Oberflächen glänzen, dunkle nicht.
	float	glossValue = max( 0.0, ( length( texColor.xyz ) - 0.5 ) / 0.5 );
	
	// Alle "in" Variablen werden komponentenweise linear für das Dreieck interpoliert.
	// Das bedeutet, dass die Länge eines Normalenvektors i.A. ungleich 1 ist => normalisieren
	vec3 N = normalize( vNormal );
	
	// Einen Tangentspace berechnen
	mat3 matTangentSpace;
	computeTangentSpace( N, matTangentSpace );
	
	glFragColor = vec4( 0.0 );
	
	for ( int i = 0; i < nLights; i++ )
	{
		vec4	lightContribution = vec4( 0.0 );
		
		float	diffuse, specular;
		
		if ( renderMode == 1 ) {
			normalTS = vec4( 0, 0, 1, 0 );
		}
		
		computeLighting( lightPositionWS[ i ], matTangentSpace, normalTS.xyz, diffuse, specular );
		
		// pro-Vertex Beleuchtung
		if( renderMode == -1 )
		{
			glFragColor = cPerVertexLighting;
		}
		else
		{
			if ( renderMode == 0 )
			{
				lightContribution  = vec4( diffuse  ) * 0.5;
				lightContribution += vec4( specular ) * 0.5;
			}
			
			// diffuse Beleuchtung, ohne Bumpmaps
			if( renderMode == 1 )
			{
				vec3 toLight = normalize( lightPositionWS[ i ] - vWorldPosition );
				lightContribution = vec4( clamp( dot( toLight, N ), 0.0, 1.0 ) * 0.5 );
			}
			
			// diffuse Beleuchtung, einfaches Texturemapping
			if( renderMode == 2 )
			{
				vec3 toLight = normalize( lightPositionWS[ i ] - vWorldPosition );
				lightContribution = clamp( dot( toLight, N ), 0.0, 1.0 ) * texColor;
			}
			
			// Ambient Occlusion only
			if( renderMode == 3 )
			{
				lightContribution = vec4( texColor.w ) * 0.5;
			}
			
			// diffuse Beleuchtung, mit Bumpmaps
			if( renderMode == 4 )
			{
				lightContribution = vec4( diffuse ) * 0.5;
			}
			
			// diffuse Beleuchtung, mit Bumpmaps und Texturen
			if( renderMode == 5 )
			{
				lightContribution = vec4( diffuse ) * texColor;
			}
			
			// diffuse Beleuchtung, mit Bumpmaps, Texturen und Ambient Occlusion
			if( renderMode == 6 )
			{
				lightContribution = vec4( diffuse ) * texColor * texColor.w * 1.5;
			}
			
			// diffuse & spekulare Beleuchtung, mit Bumpmaps, Texturen und Ambient Occlusion
			if( renderMode == 7 )
			{
				lightContribution  = vec4( diffuse  ) * texColor * texColor.w;
				lightContribution += vec4( specular );
			}
			
			// diffuse & spekulare Beleuchtung, mit Bumpmaps, Texturen und Ambient Occlusion, und Glossmaps
			if( renderMode == 8 )
			{
				lightContribution  = vec4( diffuse  ) * texColor * texColor.w;
				lightContribution += vec4( specular ) * glossValue;
			}
			
			// diffuse & spekulare Beleuchtung, mit Bumpmaps und Ambient Occlusion, und Glossmaps aber OHNE Texturen
			if( renderMode == 9 )
			{
				lightContribution  = vec4( diffuse  ) * texColor.w;
				lightContribution += vec4( specular ) * glossValue;
			}
			
			glFragColor += lightContribution * lightColor[ i ];
		}
	}
}
