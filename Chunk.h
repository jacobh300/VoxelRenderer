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



	std::vector<Vertex> vertices;
	std::vector<GLuint> ind;
	std::vector<Texture> textures;

	glm::vec3 offsetTranslation;

	Mesh mesh;
	Block block[chunkSize][chunkHeight][chunkSize];

	void Generate();
	void GenerateMesh();
	void DrawChunk();
};







#endif