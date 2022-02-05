#ifndef CHUNK_CLASS_H
#define CHUNK_CLASS_H
#include "Mesh.h"
#include "Block.h"

class Chunk {


private:


public:

	static const unsigned long chunkSize = 16;
	static const unsigned long chunkHeight = 16;

	Chunk();
	Chunk(glm::vec3 offset, Texture *tex);

	~Chunk();

	bool loaded = false;
	bool isSetup = false;

	std::vector<Vertex> vertices;
	std::vector<GLuint> ind;
	std::vector<Texture> textures;


	//May reduce values by 8(?)
	glm::vec3 offsetTranslation;

	Mesh mesh;
	Block block[chunkSize][chunkHeight][chunkSize];


	//Sets active blocks.
	void Setup();
	void Load();


	void GenerateMesh();
	void DrawChunk(Shader& shader, Camera& camera);
};







#endif