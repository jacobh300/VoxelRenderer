#include"EBO.h"

//Constructor that generates Element Buffer object and links it to indicies.
EBO::EBO(std::vector<GLuint>& indices){

	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);

}

//Binds EBO
void EBO::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}
//Unbinds the EBO
void EBO::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//Deletes the EBO
void EBO::Delete() {
	glDeleteBuffers(1, &ID);
}