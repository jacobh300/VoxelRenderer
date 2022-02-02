#ifndef CHUNKMANAGER_CLASS_H
#define CHUNKMANAGER_CLASS_H

#include<vector>
#include"Chunk.h"



class ChunkManager {
public:


	ChunkManager();
	ChunkManager(const ChunkManager& obj); 
	Texture unwrapTexture = Texture("unwrap_helper.jpg", "diffuse", 0);

	std::vector<Chunk> chunkList;

	std::vector<Chunk> chunkLoadList;
	std::vector<Chunk> chunkUnloadList;

	std::vector<Chunk> meshLoadList;

	bool chunkAtPos = false;

	void Update(float deltaTime, glm::vec3 playerPosition, Shader& shader, Camera& camera);

	void initializeChunks();
	void chunkGenTask(Chunk &chunk);

};




#endif