#ifndef TEXTUREARRAY_CLASS_H
#define TEXTUREARRAY_CLASS_H

#include<stb/stb_image.h>
#include"shaderClass.h"


class TextureArray {
	public:
		GLuint ID;
		const char* type;
		GLuint unit;


		TextureArray(const char* image, const char* texType, GLuint slot);
		void texUnit(Shader& shader, const char* uniform, GLuint unit);
		void Bind();
		void Unbind();
		void Delete();

};
#endif