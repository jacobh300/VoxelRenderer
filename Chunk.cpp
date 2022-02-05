#include "Chunk.h"
#include<set>





Chunk::Chunk(glm::vec3 offset, Texture *tex) {
	offsetTranslation = glm::vec3(offset.x * chunkSize, offset.y * chunkHeight, offset.z * chunkSize);
	textures.push_back(*tex);
}

Chunk::Chunk() {

}

Chunk::~Chunk() {
	mesh.~Mesh();
}



//Generates Mesh of the chunk based on blocks that are set to active.
void Chunk::Load() {

	vertices.clear();
	ind.clear();
	//textures.clear();

	float cubeSize = 0.5f;
	int numOfVertices = 0;
	for (int x = 0; x < chunkSize; x++) {
		for (int y = 0; y < chunkHeight; y++) {
			for (int z = 0; z < chunkSize; z++) {

				if (Chunk::block[x][y][z].IsActive()) {

					std::vector<Vertex> frontVerts = {
						//front bottom left
						Vertex{ glm::vec3(x - cubeSize, y - cubeSize,  z + cubeSize),  glm::vec2(1.0f, 0.0f) },
						//front top left							   
						Vertex { glm::vec3(x - cubeSize, y + cubeSize, z + cubeSize),  glm::vec2(0.0f, 0.0f) },
						//front bottom right						   
						Vertex { glm::vec3(x + cubeSize, y - cubeSize, z + cubeSize),  glm::vec2(1.0f, 1.0f) },
						//front top right							   
						Vertex { glm::vec3(x + cubeSize, y + cubeSize, z + cubeSize),  glm::vec2(0.0f, 1.0f) }

					};
					std::vector<Vertex> backVerts = {
						//back bottom left							   
						Vertex { glm::vec3(x + cubeSize, y - cubeSize, z - cubeSize),  glm::vec2(1.0f, 0.0f) },
						//back top left								   
						Vertex { glm::vec3(x + cubeSize, y + cubeSize, z - cubeSize),  glm::vec2(0.0f, 0.0f) },
						//back bottom right							   
						Vertex { glm::vec3(x - cubeSize, y - cubeSize, z - cubeSize),  glm::vec2(1.0f, 1.0f) },
						//back top right							   
						Vertex { glm::vec3(x - cubeSize, y + cubeSize, z - cubeSize),  glm::vec2(0.0f, 1.0f) }

					};
					std::vector<Vertex> rightVerts = {
						//right bottom left							   
						Vertex { glm::vec3(x + cubeSize, y - cubeSize, z + cubeSize),  glm::vec2(1.0f, 0.0f) },
						//right top left							   
						Vertex { glm::vec3(x + cubeSize, y + cubeSize, z + cubeSize),  glm::vec2(0.0f, 0.0f) },
						//right bottom right						   
						Vertex { glm::vec3(x + cubeSize, y - cubeSize, z - cubeSize),  glm::vec2(1.0f, 1.0f) },
						//right top right							   
						Vertex { glm::vec3(x + cubeSize, y + cubeSize, z - cubeSize),  glm::vec2(0.0f, 1.0f) }

					};
					std::vector<Vertex> leftVerts = {
						//left bottom left							   
						Vertex { glm::vec3(x - cubeSize, y - cubeSize, z - cubeSize),  glm::vec2(1.0f, 0.0f) },
						//left top left								   
						Vertex { glm::vec3(x - cubeSize, y + cubeSize, z - cubeSize),  glm::vec2(0.0f, 0.0f) },
						//left bottom right							   
						Vertex { glm::vec3(x - cubeSize, y - cubeSize, z + cubeSize),  glm::vec2(1.0f, 1.0f) },
						//left top right							   
						Vertex { glm::vec3(x - cubeSize, y + cubeSize, z + cubeSize),  glm::vec2(0.0f, 1.0f) }

					};
					std::vector<Vertex> topVerts = {
						//top bottom left							   
						Vertex { glm::vec3(x - cubeSize, y + cubeSize, z + cubeSize),  glm::vec2(1.0f, 0.0f) },
						//top top left								   
						Vertex { glm::vec3(x - cubeSize, y + cubeSize, z - cubeSize),  glm::vec2(0.0f, 0.0f) },
						//top bottom right							   
						Vertex { glm::vec3(x + cubeSize, y + cubeSize, z + cubeSize),  glm::vec2(1.0f, 1.0f) },
						//top top right							   
						Vertex { glm::vec3(x + cubeSize, y + cubeSize, z - cubeSize),  glm::vec2(0.0f, 1.0f) }

					};
					std::vector<Vertex> bottomVerts = {
						//bottom bottom left							   
						Vertex { glm::vec3(x - cubeSize, y - cubeSize, z - cubeSize),  glm::vec2(1.0f, 0.0f) },
						//bottom top left								   
						Vertex { glm::vec3(x - cubeSize, y - cubeSize, z + cubeSize),  glm::vec2(0.0f, 0.0f) },
						//bottom bottom right							   
						Vertex { glm::vec3(x + cubeSize, y - cubeSize, z - cubeSize),  glm::vec2(1.0f, 1.0f) },
						//bottom top right							   
						Vertex { glm::vec3(x + cubeSize, y - cubeSize, z + cubeSize),  glm::vec2(0.0f, 1.0f) }

					};
			
					
					//Front Indicies
					if (z + 1 >= chunkSize || !Chunk::block[x][y][z + 1].IsActive()) {
						vertices.insert(vertices.end(), frontVerts.begin(), frontVerts.end());
						if (!(x == 0 && y == 0 && z == 0)) numOfVertices += 4;

						GLuint frontInd[] = {
							//front face
							(0 + (ind.size()/6)*4) ,  (1 + (ind.size()/6)*4) ,  (2 + (ind.size()/6)*4) ,
							(2 + (ind.size()/6)*4) , (1 + (ind.size()/6)*4) ,  (3 + (ind.size()/6)*4) 
						};
						std::vector<GLuint> tempFrontInd(frontInd, frontInd + sizeof(frontInd) / sizeof(GLuint));


						ind.insert(ind.end(), tempFrontInd.begin(), tempFrontInd.end());
						
					}
					//Back Indicices
					if (z == 0 || !Chunk::block[x][y][z - 1].IsActive()) {
						vertices.insert(vertices.end(), backVerts.begin(), backVerts.end());
						if (!(x == 0 && y == 0 && z == 0)) numOfVertices += 4;
						GLuint backInd[] = {
							//back face
							(0 + (ind.size()/6)*4) ,  (1 + (ind.size()/6)*4) ,  (2 + (ind.size()/6)*4) ,
							(2 + (ind.size()/6)*4) ,  (1 + (ind.size()/6)*4) ,  (3 + (ind.size()/6)*4) 
						};
						std::vector<GLuint> tempBackInd(backInd, backInd + sizeof(backInd) / sizeof(GLuint));
						ind.insert(ind.end(), tempBackInd.begin(), tempBackInd.end());
					}
					//Right Indicies
					if (x + 1 >= chunkSize || !Chunk::block[x + 1][y][z].IsActive()) {
						vertices.insert(vertices.end(), rightVerts.begin(), rightVerts.end());
						if (!(x == 0 && y == 0 && z == 0)) numOfVertices += 4;
						GLuint rightInd[] = {
							//right face
							(0 + (ind.size()/6)*4) ,  (1 + (ind.size()/6)*4) , (2 + (ind.size()/6)*4) ,
							(2 + (ind.size()/6)*4) ,  (1 + (ind.size()/6)*4) , (3 + (ind.size()/6)*4) ,
						};

						std::vector<GLuint> tempRightInd(rightInd, rightInd + sizeof(rightInd) / sizeof(GLuint));
						ind.insert(ind.end(), tempRightInd.begin(), tempRightInd.end());
						
					}
					//Left Indicies
					if (x == 0 || !Chunk::block[x - 1][y][z].IsActive()) {
						vertices.insert(vertices.end(), leftVerts.begin(), leftVerts.end());
						if (!(x == 0 && y == 0 && z == 0)) numOfVertices += 4;
						GLuint leftInd[] = {
							//left face
							(0 + (ind.size()/6)*4) , (1 + (ind.size()/6)*4) , (2 + (ind.size()/6)*4) ,
							(2 + (ind.size()/6)*4) , (1 + (ind.size()/6)*4) , (3 + (ind.size()/6)*4) ,
						};

						std::vector<GLuint> tempLeftInd(leftInd, leftInd + sizeof(leftInd) / sizeof(GLuint));
						ind.insert(ind.end(), tempLeftInd.begin(), tempLeftInd.end());
					}
					//Top Indicies
					if (y + 1 >= chunkHeight || !Chunk::block[x][y + 1][z].IsActive()) {
						vertices.insert(vertices.end(), topVerts.begin(), topVerts.end());
						if (!(x == 0 && y == 0 && z == 0)) numOfVertices += 4;
						GLuint topInd[] = {
							//top face
							(0 + (ind.size()/6)*4) , (1 + (ind.size()/6)*4) ,  (2 + (ind.size()/6)*4) ,
							(2 + (ind.size()/6)*4) ,  (1 + (ind.size()/6)*4) , (3 + (ind.size()/6)*4) ,
						};
						std::vector<GLuint> tempTopInd(topInd, topInd + sizeof(topInd) / sizeof(GLuint));
						ind.insert(ind.end(), tempTopInd.begin(), tempTopInd.end());
						
					}
					//Bottom Indicies
					if (y == 0 || !Chunk::block[x][y - 1][z].IsActive()) {
						vertices.insert(vertices.end(), bottomVerts.begin(), bottomVerts.end());
						if (!(x == 0 && y == 0 && z == 0)) numOfVertices += 4;
						GLuint bottomInd[] = {
							//bottom face
							(0 + (ind.size()/6)*4) ,  (1 + (ind.size()/6)*4) ,  (2 + (ind.size()/6)*4) ,
							(2 + (ind.size()/6)*4) ,  (1 + (ind.size()/6)*4) ,  (3 + (ind.size()/6)*4) 
						};
						std::vector<GLuint> tempBottomInd(bottomInd, bottomInd + sizeof(bottomInd) / sizeof(GLuint));
						ind.insert(ind.end(), tempBottomInd.begin(), tempBottomInd.end());
					}
				}
			}
		}
	}

	GenerateMesh();

	loaded = true;

};

void Chunk::Setup() {

	for (int x = 0; x < chunkSize; x++) {
		for (int y = 0; y < chunkHeight; y++) {
			for (int z = 0; z < chunkSize; z++) {
				//if ((std::rand() % 100) < 25)
				Chunk::block[x][y][z].SetActive(true);
			}
		}
	}

	isSetup = true;


}


//Generates the mesh of the chunk.
void Chunk::GenerateMesh() {
	Chunk::mesh = Mesh(vertices, ind, textures);
}


void Chunk::DrawChunk(Shader& shader, Camera& camera) {
	mesh.Draw(shader, camera, glm::mat4(1.0f), offsetTranslation );
}
