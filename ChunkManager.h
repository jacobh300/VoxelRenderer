#ifndef CHUNKMANAGER_CLASS_H
#define CHUNKMANAGER_CLASS_H

#include<vector>
#include"Chunk.h"
#include <thread>
#include<mutex>
#include<future>


class ChunkManager {
public:


	ChunkManager();
	Texture unwrapTexture = Texture("unwrap_helper.jpg", "diffuse", 0);
	
	//std::mutex mutex;
	std::vector<Chunk> chunkList;
	std::vector<Chunk> chunkLoadList;
	std::vector<Chunk> meshLoadList;

	std::vector<std::thread> generationThreadList;


	int xIndex = 0;
	int zIndex = 0;

	void Update(float deltaTime, Shader& shader, Camera& camera);
	void Generate();
	void DrawChunks();
	void initializeChunks();
	void chunkGenTask(Chunk &chunk);
	void GenerateAvailableChunk();
};




#endif