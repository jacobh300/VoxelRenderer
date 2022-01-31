#version 330 core

//Outputs colors in RGBA
out vec4 FragColor;

//Imports the current position from the vertex shader
in vec3 crntPos;

//Imports the normal from the vertex shader
in vec3 Normal;

//Inputs the color from the vertex shader
in vec3 color;

// Inputs the texture coordinates from the vertex shader
in vec2 texCoord;


// Gets the texture Unit from the main function
uniform sampler2D diffuse0;
uniform sampler2D specular0;

//Get the color of the light from the main function
uniform vec4 lightColor;

//Get the position of the light from the main function
uniform vec3 lightPos;

//Get the position of the camera from the main function
uniform vec3 camPos;





//Directional Light (Enviormental Light)
vec4 direcLight(){

	//Ambient Lighting
	float ambient = 0.20f;

	//Diffuse Lighting
	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize (vec3(1.0f, 0.0f, 0.0f));
	float diffuse = max(dot(normal, lightDirection) , 0.0f);


	//Specular Lighting
	float specularLight = 0.50;
	vec3 viewDirection = normalize(camPos - crntPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
	float specular = specAmount * specularLight;

	//Outputs the final color
	return (texture(diffuse0 , texCoord) * (diffuse  + ambient ) + texture(specular0, texCoord).r * specular ) * lightColor;
	

}




float near = 0.1f;
float far = 100.0f;



float linearizeDepth(float depth){

	return (2.0 * near * far) / (far + near - (depth * 2.0 - 1.0) * (far - near));

}

float logisiticDepth(float depth, float steepness = 0.1f, float offset = 70.0f){

	float zVal = linearizeDepth(depth);
	return (1/ (1+ exp(-steepness * (zVal - offset))));
	
}




void main()
{
	//Outputs the final color
	FragColor = direcLight();

	//float depth = logisiticDepth(gl_FragCoord.z);
	//First part allows the object to grow brighter the closer you get to a object, the second part shades the objects the color of the background.
	//This gives the illusion of the object fading away the farther away you go
	//FragColor = (direcLight() * (1.0f - depth) ) + vec4(depth * vec3(0.85f, 0.85f, 0.90f), 1.0f);
}