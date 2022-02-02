#ifndef MESH_CLASS_H
#define MESH_CLASS_H

#include<string>
#include"VAO.h"

#include"Camera.h"
#include"Texture.h"



class Mesh {


public:
	
	//Using vectors since we don't know how big the data will be.
	std::vector <Vertex> vertices; 
	std::vector <GLuint> indices; 
	std::vector <Texture> textures;  


	VAO VAO;
	~Mesh();
	Mesh();
	Mesh(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector<Texture>& textures); 

	void Draw(
		Shader& shader,
		Camera& camera,
		glm::mat4 matrix = glm::mat4(1.0f),
		glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f),
		glm::vec3 scale = glm::vec3(1.0f,1.0f,1.0f)
	);

};
#endif