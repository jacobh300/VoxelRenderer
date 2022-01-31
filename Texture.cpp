#include"Texture.h"

Texture::Texture() {

}



Texture::Texture(const char* image, const char* texType, GLuint slot) {

	//Assings the type of texture of the texture object.
	type = texType;

	int widthImg, heightImg, numColCh;

	//Flips the texture on load.
	stbi_set_flip_vertically_on_load(true);
	//Reads the image from a file and stores it in bytes.
	unsigned char* bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

	//Generates an OpenGL texture Object
	glGenTextures(1, &ID);

	//Assigns the texture to a texture Unit
	glActiveTexture(GL_TEXTURE0 + slot);
	unit = slot;
	glBindTexture(GL_TEXTURE_2D, ID);

	//Configures the type of algorithm to enlarge/decrease size of texture.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	//Configure how the texture repeats.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	if (numColCh == 4)
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			widthImg,
			heightImg,
			0,
			GL_RGBA,
			GL_UNSIGNED_BYTE,
			bytes
		);
	else if (numColCh == 3)
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			widthImg,
			heightImg,
			0,
			GL_RGB,
			GL_UNSIGNED_BYTE,
			bytes
		);
	else if (numColCh == 1)
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RGBA,
			widthImg,
			heightImg,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			bytes
		);
	else
		throw std::invalid_argument("Automatic Texture type recognition failed");

	//Generate MipMaps
	glGenerateMipmap(GL_TEXTURE_2D);

	// Deletes the image data as it is already in the openGL texture
	stbi_image_free(bytes);

	//Unbinds the openGL texture object so it doesn't change
	glBindTexture(GL_TEXTURE_2D, 0);


}


void Texture::texUnit(Shader& shader, const char* uniform, GLuint unit) {

	//Gets the location of the uniform
	GLuint texUni = glGetUniformLocation(shader.ID, uniform);

	//Shader needs to be activated before changing the value of a uniform
	shader.Activate();

	//Sets the value of the uniform
	glUniform1i(texUni, unit);

}


void Texture::Bind() {
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind() {
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::Delete() {
	glDeleteTextures(1, &ID);
}