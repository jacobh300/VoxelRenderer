#ifndef VOXEL_CLASS_H
#define VOXEL_CLASS_H

#include<string>
#include"VAO.h"

#include"Camera.h"
#include"Texture.h"


class Voxel {

	public:
		VAO VAO;

		std::vector <Vertex> vertices; 
		std::vector <GLuint> indices; 
		std::vector <Texture> textures;


		Voxel(std::vector <Vertex>& vertices, std::vector <GLuint>& indices, std::vector<Texture>& textures);

		void Draw(
			Shader& shader,
			Camera& camera,
			glm::mat4 matrix = glm::mat4(1.0f),
			glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f),
			glm::quat rotation = glm::quat(0.0f, 0.0f, 0.0f, 0.0f),
			glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)
		);


	private:






};




#endif