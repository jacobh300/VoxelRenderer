#include"ChunkManager.h"



ChunkManager::ChunkManager() {

	//ChunkManager::initializeChunks(); 
}


ChunkManager::ChunkManager(const ChunkManager& obj) {
	std::cout << "Copy constructor allocating pointer." << std::endl;
	
}



void ChunkManager::UpdateChunkList(glm::vec3 playerPosition) {

	int radius = 8;

	for (int x = - radius/2; x < radius/2; x++) {
		for (int z = -radius / 2; z < radius / 2; z++) {

			if(totalChunksLoaded < 30){

				glm::vec3 pos = glm::round(playerPosition / 16.0f);
				pos.x += 1 * x;
				pos.y = 0;
				pos.z += 1 * z;

					Chunk* chunk = new Chunk(pos, &unwrapTexture);
			
					
					
					if (chunkList.empty()) {
						
				
							chunkList.push_back(chunk); 
							std::cout << chunk->offsetTranslation.x << ", " << chunk->offsetTranslation.y << ", " << chunk->offsetTranslation.z << std::endl;
						
					
					
					}
					else{

						std::vector<Chunk*>::iterator iter;

						bool match = false;
						for (int i = 0; i < chunkList.size(); i++) {

							if (!chunkList.at(i)->isSetup) {
								chunkSetupList.push_back(chunkList.at(i));
							}

							if (!chunkList.at(i)->loaded && chunkList.at(i)->isSetup) {
								chunkLoadList.push_back(chunkList.at(i));
							}

							if (chunkList.at(i)->offsetTranslation == chunk->offsetTranslation) {
								match = true;
								delete chunk;
							}
						}

						if (!match) { 
							chunkList.push_back(chunk); 
							std::cout << chunk->offsetTranslation.x << ", " << chunk->offsetTranslation.y << ", " << chunk->offsetTranslation.z << std::endl;
						}
	

					}
					
			
				
					
			


					//chunkSetupList.push_back(chunk);
					


					//totalChunksLoaded++;
				
			}

		}
	}



}




void ChunkManager::UpdateLoadList() {
	std::vector<Chunk*>::iterator iter;

	for (iter = chunkLoadList.begin(); iter != chunkLoadList.end(); iter++) {
		Chunk* chunk = (*iter);

		if (!chunk->loaded && chunk->isSetup == true && numOfChunksLoaded != chunksLoadedPerFrame) {
			chunk->Load();
			numOfChunksLoaded++;
			std::cout << "loading" << std::endl;
		}
	
	}



	chunkLoadList.clear();
}

void ChunkManager::UpdateSetupList() {
	std::vector<Chunk*>::iterator iter;

	for (iter = chunkSetupList.begin(); iter != chunkSetupList.end(); iter++) {
		Chunk* chunk = (*iter);

		if(!chunk->isSetup && !chunk->loaded){
			chunk->Setup();
			std::cout << "setup" << std::endl;
		}
	
	}

	chunkSetupList.clear();
}


//Called every frame
void ChunkManager::Update(float deltaTime, glm::vec3 playerPosition, Shader& shader, Camera& camera) {
	int radius = 10;

	UpdateChunkList(playerPosition);
	
	UpdateLoadList();
	UpdateSetupList();

	for (Chunk* chunk : chunkList) {
		chunk->DrawChunk(shader, camera);
	}

	numOfChunksLoaded = 0;
	
}
