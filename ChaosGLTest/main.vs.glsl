#version 150

const int nLights = 2;
uniform vec3 lightPositionWS[ nLights ];
uniform vec4 lightColor[ nLights ];
uniform vec3 vCameraPosition;
uniform mat4 matObjectToWorld, matObjectToWorldNormals;
uniform mat4 uModelViewProjectionMatrix;

in vec4 aNormal;
in vec4 aVertex;
in vec2 aMultiTexCoord0;

out vec2 vTexCoord[7];
out vec4 cPerVertexLighting;
out vec3 vNormal;
out vec3 vWorldPosition;

void computeLighting(in vec3 lightPositionWS, in vec3 normalWS,
	in vec3 worldPosition, out float diffuse, out float specular)
{
	//
	// Aufgabe 1
	//
	// Wir berechnen alles im World Space, verwenden also die
	// Licht- & Blickrichtung und berechnen dann die Reflexionsrichtung
	/*	vec3 lightWS   = ...;
	 vec3 viewWS    = ...;
	 vec3 halfwayWS = ...;
	 */
	diffuse  = 0.0;
	specular = 0.0;
}

void main()
{
	// Wir geben die Textur-Koordinate unverändert weiter
	vTexCoord[ 0 ] = aMultiTexCoord0;
	
	// Annahme: World Space = Object Space
	vNormal        =  ( matObjectToWorldNormals * vec4( aNormal.xyz, 0.0 ) ).xyz;
	vWorldPosition =  ( matObjectToWorld * aVertex ).xyz;
	
	// akkumulieren der Beiträge von Lichtquellen
	cPerVertexLighting = vec4( 0.0 );
	for ( int i = 0; i < nLights; i++ )
	{
		vec4	lightContribution = vec4( 0.0 );
		
		float	diffuse, specular;
		
		// Beleuchtung durch die i-te Lichtquelle
		computeLighting( lightPositionWS[ i ], vNormal.xyz, vWorldPosition.xyz, diffuse, specular );
		
		lightContribution  = vec4( diffuse ) * 0.5;
		lightContribution += vec4( specular )* 0.5;
		
		// und aufsummieren
		cPerVertexLighting += lightContribution * lightColor[ i ];
	}
	
	// Transformieren der Vertices
	gl_Position = uModelViewProjectionMatrix * matObjectToWorld * aVertex;
}