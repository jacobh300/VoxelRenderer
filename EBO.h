#ifndef EBO_CLASS_H
#define EBO_CLASS_H


#include <glad/glad.h>
#include<vector>


class EBO {


public:

	//Reference ID
	GLuint ID;
	//Constructor that generates Element Buffer object and links it to indicies.
	EBO(std::vector<GLuint>& indices);
	//Binds EBO
	void Bind();
	//Unbinds the EBO
	void Unbind();
	//Deletes the EBO
	void Delete();


};


#endif