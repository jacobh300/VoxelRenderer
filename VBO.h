#ifndef VBO_CLASS_H
#define VBO_CLASS_H


#include<glm/glm.hpp>
#include <glad/glad.h>
#include<vector>


struct Vertex {
	glm::vec3 position;
	glm::vec2 texUV;
};


class VBO {


public:
	//Reference ID
	GLuint ID;

	//Constructor that generates the Vertex Buffer Object and links to vertices.
	VBO(std::vector<Vertex>& vertices);

	//Binds the VBO
	void Bind();

	//Unbinds the VBO
	void Unbind();

	//Deletes the VBO
	void Delete();


};


#endif