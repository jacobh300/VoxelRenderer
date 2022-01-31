#version 330 core


// Positions/Coordinates
layout (location = 0) in vec3 aPos;
// Texture Coordinates
layout (location = 1) in vec2 aTex;


out vec3 Normal;
out vec3 color;
out vec2 texCoord;

//Imports the camera matrix from the main function
uniform mat4 camMatrix;

//Imports the transformation matrices
uniform mat4 model;
uniform mat4 translation;
uniform mat4 rotation;
uniform mat4 scale;

void main()
{

	gl_Position = camMatrix * model * translation * rotation * scale * vec4(aPos , 1.0f);
	Normal = vec3(1.0f,1.0f,1.0f);
	color = vec3(1.0f, 1.0f, 0.0f);
	

	texCoord =  mat2(0.0, -1.0, 1.0, 0.0) * aTex;

}