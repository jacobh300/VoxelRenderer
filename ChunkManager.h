#ifndef CHUNKMANAGER_CLASS_H
#define CHUNKMANAGER_CLASS_H

#include<vector>
#include"Chunk.h"



class ChunkManager {
public:


	ChunkManager();
	ChunkManager(const ChunkManager& obj); 
	Texture unwrapTexture = Texture("unwrap_helper.jpg", "diffuse", 0);



	std::vector<Chunk *> chunkList; 





	std::vector<Chunk *> chunkLoadList;
	std::vector<Chunk *> chunkSetupList;
	std::vector<Chunk *> chunkUnloadList; 
	std::vector<Chunk *> chunkRenderList;

	bool chunkAtPos = false;

	int chunksLoadedPerFrame = 1;
	int numOfChunksLoaded = 0;
	int totalChunksLoaded = 0;

	void Update(float deltaTime, glm::vec3 playerPosition, Shader& shader, Camera& camera);


	

	void UpdateChunkList(glm::vec3 playerPosition);

	//Check if any chunks need to be loaded.
	void UpdateLoadList();

	//Check if any chunks have been laoded but need to be setup.
	void UpdateSetupList();


	void UpdateRebuildList();
	void UpdateUnloadList();


	void UpdateVisibilityList();

	void UpdateRenderList();


};




#endif