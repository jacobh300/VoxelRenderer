#include"VAO.h"

//Generates the Vertex Array Object.
VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

//Links a VBO attribute to the VAO using a certain layout
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {

	VBO.Bind();

	//Configure the Vertex Attribute so that openGL knows how to read the VBO
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	// Enable the vertex Attribute so that OpenGL knows to use it
	glEnableVertexAttribArray(layout);

	VBO.Unbind();
}


//Binds the VAO to the reference ID
void VAO::Bind() {
	glBindVertexArray(ID);
}

//Unbinds the VAO
void VAO::Unbind() {
	glBindVertexArray(0);

}

//Deletes the VAO
void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}