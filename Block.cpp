#include "Block.h"
float cubeSize = 1.0f;

std::vector<Vertex> frontVerts = {
	//front bottom left
	Vertex{ glm::vec3(0 - cubeSize, 0 - cubeSize,  0 + cubeSize),  glm::vec2(1.0f, 0.0f) },
	//front top left							   
	Vertex { glm::vec3(0 - cubeSize, 0 + cubeSize, 0 + cubeSize),  glm::vec2(0.0f, 0.0f) },
	//front bottom right						   
	Vertex { glm::vec3(0 + cubeSize, 0 - cubeSize, 0 + cubeSize),  glm::vec2(1.0f, 1.0f) },
	//front top right							   
	Vertex { glm::vec3(0 + cubeSize, 0 + cubeSize, 0 + cubeSize),  glm::vec2(0.0f, 1.0f) }

};
std::vector<Vertex> backVerts = {
	//back bottom left							   
	Vertex { glm::vec3(0 + cubeSize, 0 - cubeSize, 0 - cubeSize),  glm::vec2(1.0f, 0.0f) },
	//back top left								   
	Vertex { glm::vec3(0 + cubeSize, 0 + cubeSize, 0 - cubeSize),  glm::vec2(0.0f, 0.0f) },
	//back bottom right							   
	Vertex { glm::vec3(0 - cubeSize, 0 - cubeSize, 0 - cubeSize),  glm::vec2(1.0f, 1.0f) },
	//back top right							   
	Vertex { glm::vec3(0 - cubeSize, 0 + cubeSize, 0 - cubeSize),  glm::vec2(0.0f, 1.0f) }

};
std::vector<Vertex> rightVerts = {
	//right bottom left							   
	Vertex { glm::vec3(0 + cubeSize, 0 - cubeSize, 0 + cubeSize),  glm::vec2(1.0f, 0.0f) },
	//right top left							   
	Vertex { glm::vec3(0 + cubeSize, 0 + cubeSize, 0 + cubeSize),  glm::vec2(0.0f, 0.0f) },
	//right bottom right						   
	Vertex { glm::vec3(0 + cubeSize, 0 - cubeSize, 0 - cubeSize),  glm::vec2(1.0f, 1.0f) },
	//right top right							   
	Vertex { glm::vec3(0 + cubeSize, 0 + cubeSize, 0 - cubeSize),  glm::vec2(0.0f, 1.0f) }

};
std::vector<Vertex> leftVerts = {
	//left bottom left							   
	Vertex { glm::vec3(0 - cubeSize, 0 - cubeSize, 0 - cubeSize),  glm::vec2(1.0f, 0.0f) },
	//left top left								   
	Vertex { glm::vec3(0 - cubeSize, 0 + cubeSize, 0 - cubeSize),  glm::vec2(0.0f, 0.0f) },
	//left bottom right							   
	Vertex { glm::vec3(0 - cubeSize, 0 - cubeSize, 0 + cubeSize),  glm::vec2(1.0f, 1.0f) },
	//left top right							   
	Vertex { glm::vec3(0 - cubeSize, 0 + cubeSize, 0 + cubeSize),  glm::vec2(0.0f, 1.0f) }

};
std::vector<Vertex> topVerts = {
	//top bottom left							   
	Vertex { glm::vec3(0 - cubeSize, 0 + cubeSize, 0 + cubeSize),  glm::vec2(1.0f, 0.0f) },
	//top top left								   
	Vertex { glm::vec3(0 - cubeSize, 0 + cubeSize, 0 - cubeSize),  glm::vec2(0.0f, 0.0f) },
	//top bottom right							   
	Vertex { glm::vec3(0 + cubeSize, 0 + cubeSize, 0 + cubeSize),  glm::vec2(1.0f, 1.0f) },
	//top top right							   
	Vertex { glm::vec3(0 + cubeSize, 0 + cubeSize, 0 - cubeSize),  glm::vec2(0.0f, 1.0f) }

};
std::vector<Vertex> bottomVerts = {
	//bottom bottom left							   
	Vertex { glm::vec3(0 - cubeSize, 0 - cubeSize, 0 - cubeSize),  glm::vec2(1.0f, 0.0f) },
	//bottom top left								   
	Vertex { glm::vec3(0 - cubeSize, 0 - cubeSize, 0 + cubeSize),  glm::vec2(0.0f, 0.0f) },
	//bottom bottom right							   
	Vertex { glm::vec3(0 + cubeSize, 0 - cubeSize, 0 - cubeSize),  glm::vec2(1.0f, 1.0f) },
	//bottom top right							   
	Vertex { glm::vec3(0 + cubeSize, 0 - cubeSize, 0 + cubeSize),  glm::vec2(0.0f, 1.0f) }

};


GLuint frontInd[] = {
	//front face
	0 ,  1 ,  2 ,
	2 ,  1 ,  3 
};

GLuint backInd[] = {
	//back face
	0 + (4 * 1) ,  1 + (4 * 1) ,  2 + (4 * 1) ,
	2 + (4 * 1) ,  1 + (4 * 1) ,  3 + (4 * 1) 
};

GLuint rightInd[] = {
	//right face
	0 + (4 * 2) ,  1 + (4 * 2) ,  2 + (4 * 2) ,
	2 + (4 * 2) ,  1 + (4 * 2) ,  3 + (4 * 2) ,
};

GLuint leftInd[] = {
	//left face
	0 + (4 * 3) ,  1 + (4 * 3) ,  2 + (4 * 3) ,
	2 + (4 * 3) ,  1 + (4 * 3) ,  3 + (4 * 3) ,
};

GLuint topInd[] = {
	//top face
	0 + (4 * 4) ,  1 + (4 * 4) ,  2 + (4 * 4) ,
	2 + (4 * 4) ,  1 + (4 * 4) ,  3 + (4 * 4) ,
};

GLuint bottomInd[] = {
	//bottom face
	0 + (4 * 5) ,  1 + (4 * 5) ,  2 + (4 * 5) ,
	2 + (4 * 5) ,  1 + (4 * 5) ,  3 + (4 * 5) 
};

Block::Block() {

}

Block::~Block() {


}

bool Block::IsActive() {
	return Block::active;
}

void Block::SetActive(bool active) {
	Block::active = active;
}