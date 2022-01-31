#include "Cube.h"
#include<glm/glm.hpp>


Vertex _verts[] =
{
	//        COORDS                              NORMAL                      COLOR                         UV
	//Bottom Vertices
	Vertex{ glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f,  1.0f), glm::vec3(-1.0f, -1.0f,  1.0f),  glm::vec2(1.0f, 1.0f)  },
	Vertex{ glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f,  1.0f), glm::vec3(-1.0f, -1.0f, -1.0f),  glm::vec2(1.0f, 1.0f)  },
	
	Vertex{ glm::vec3(0.5f, -0.5f, -0.5f), glm::vec3(1.0f, 1.0f,  1.0f),  glm::vec3(1.0f, -1.0f, -1.0f),   glm::vec2(1.0f, 1.0f)  },
	Vertex{ glm::vec3(0.5f, -0.5f,  0.5f), glm::vec3(1.0f, 1.0f,  1.0f),  glm::vec3(1.0f, -1.0f,  1.0f),   glm::vec2(1.0f, 1.0f)  },

	//Top Vertices
	Vertex{ glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f,  1.0f), glm::vec3(-1.0f,  1.0f,  1.0f),  glm::vec2(1.0f, 1.0f) },
	Vertex{ glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f,  1.0f), glm::vec3(-1.0f,  1.0f, -1.0f),  glm::vec2(1.0f, 1.0f) },
	
	Vertex{ glm::vec3(0.5f,  0.5f, -0.5f), glm::vec3(1.0f, 1.0f,  1.0f),  glm::vec3(1.0f,  1.0f, -1.0f),   glm::vec2(1.0f, 1.0f) },
	Vertex{ glm::vec3(0.5f,  0.5f,  0.5f), glm::vec3(1.0f, 1.0f,  1.0f),  glm::vec3(1.0f,  1.0f,  1.0f),   glm::vec2(1.0f, 1.0f) },

};

GLuint _indices[] = {
	0,4,3,
	3,4,7,

	2,3,7,
	2,7,6,

	1,2,6,
	6,5,1,

	5,6,7,
	4,5,7,

	4,1,5,
	1,4,0,

	2,1,0,
	0,3,2
};


Mesh Cube::genMesh() {

	Texture textures[]{
		Texture("planks.png", "diffuse", 0)
	};

	std::vector<Vertex> vertices(_verts, _verts + sizeof(_verts) / sizeof(Vertex));
	std::vector<GLuint> ind(_indices, _indices + sizeof(_indices) / sizeof(GLuint));
	std::vector<Texture> tex(textures, textures + sizeof(textures) / sizeof(Texture));

	return Mesh(vertices, ind, tex);

};

glm::mat4 matrix = glm::mat4(1.0f);
glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f);
glm::quat rotation = glm::quat(0.0f, 0.0f, 0.0f, 0.0f);
glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);
glm::mat4 matNode = glm::mat4(1.0f);

Cube::Cube() {


};




void Cube::Render(Mesh mesh,Shader shaderProgram, Camera camera) {
	mesh.Draw(shaderProgram, camera, matrix, translation, rotation, scale);
};