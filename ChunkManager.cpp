#include"ChunkManager.h"



ChunkManager::ChunkManager() {

	ChunkManager::initializeChunks(); 
}


ChunkManager::ChunkManager(const ChunkManager& obj) {
	std::cout << "Copy constructor allocating pointer." << std::endl;
	
}



void ChunkManager::chunkGenTask(Chunk &chunk) {
	chunk.Generate();
}
 



void ChunkManager::initializeChunks() {

	for (int x = 0; x < 25; x++) {
		for (int z = 0; z < 25; z++) {
			Chunk chunk = Chunk(glm::vec3(x, 0, z), &unwrapTexture);
			chunkLoadList.insert(chunkLoadList.begin(), chunk);
		}
	}
}


//Called every frame
void ChunkManager::Update(float deltaTime, glm::vec3 playerPosition, Shader& shader, Camera& camera) {
	int radius = 10;

	for (Chunk chunk : chunkLoadList) {

		if (chunk.offsetTranslation == glm::vec3(std::round(playerPosition.x/16), 0, std::round(playerPosition.z/16))) {
			//std::cout << "chunk loading at location" << std::endl;
			break;
		}

	}

	for (Chunk chunk : chunkList) {
		if (chunk.offsetTranslation == glm::vec3((std::round(playerPosition.x / 16) * 16 ) , 0, (std::round(playerPosition.z / 16) * 16))) {

			//chunkAtPos == true;
			//std::cout << "chunk at location" << std::endl;
			break;
		}

		//chunkAtPos == false;


	}



	if (!chunkLoadList.empty()) {
		chunkLoadList.at(0).Generate();
		chunkLoadList.at(0).GenerateMesh();
		chunkList.push_back(std::move( chunkLoadList.at(0)));
		chunkLoadList.erase(chunkLoadList.begin());
	}

	if (!chunkUnloadList.empty()) {
			chunkUnloadList.at(0).~Chunk();
			chunkUnloadList.erase(chunkUnloadList.begin());
		
	}






	for (int i = 0; i < chunkList.size(); i++) {

		if (!chunkList.empty()) {

			if (glm::distance(chunkList.at(i).offsetTranslation, playerPosition) > 1000) {
				chunkUnloadList.push_back(std::move(chunkList.at(i)));
				chunkList.erase(chunkList.begin() + i);
			}
			else {
				glm::vec3 modTrans = chunkList.at(i).offsetTranslation;
				modTrans.x -= 8;
				modTrans.z -= 8;
				chunkList.at(i).mesh.Draw(shader, camera, glm::mat4(1.0f), modTrans);
			}
		}
	}
	
}
