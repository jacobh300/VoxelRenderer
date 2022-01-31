#include"ChunkManager.h"



ChunkManager::ChunkManager() {
	ChunkManager::initializeChunks(); 
}


void ChunkManager::chunkGenTask(Chunk &chunk) {
	std::cout << "new thread created";
	chunk.Generate();
}
 



void ChunkManager::initializeChunks() {
	for (int x = 0; x < 25; x++) {
		for (int z = 0; z < 25; z++) {

			Chunk chunk = Chunk(glm::vec3(x, 0, z), &unwrapTexture);



			//std::thread threadObj( &ChunkManager::chunkGenTask, this, std::ref(chunk) );
			//generationThreadList.push_back( std::move(threadObj) );


			//generationThreadList.emplace_back(threadObj);
			//generationThreadList.push_back(move(threadObj));
			//threadObj.join();
			
			chunkLoadList.insert(chunkLoadList.begin(), chunk);
		}
	}

	for (std::thread& thread : generationThreadList) {
		//thread.join();
	}


}





void ChunkManager::GenerateAvailableChunk() {

	if (!chunkLoadList.empty()) {

		//std::thread thread(&ChunkManager::chunkGenTask, this, chunkLoadList.at(0));
		//generationThreadList.emplace_back(&ChunkManager::chunkGenTask, this, &chunkLoadList.at(0));
	}

}



//Called every frame
void ChunkManager::Update(float deltaTime, Shader& shader, Camera& camera) {
	int size = 25;


	GenerateAvailableChunk();

	if (!chunkLoadList.empty()) {
		chunkLoadList.at(0).Generate();


		//generationThreadList.emplace_back(&ChunkManager::chunkGenTask, this, &chunkLoadList.at(0));


		chunkLoadList.at(0).GenerateMesh();
		chunkList.push_back(chunkLoadList.at(0));
		chunkLoadList.erase(chunkLoadList.begin());

	}

	if(!generationThreadList.empty()){
		for (int i = 0; i < generationThreadList.size(); i++) {
			generationThreadList.at(i).join();
			generationThreadList.erase( generationThreadList.begin() + i);
		}
	}


	for (int i = 0; i < chunkList.size(); i++) {
		if (!chunkList.empty()) {
			chunkList.at(i).mesh.Draw(shader, camera, glm::mat4(1.0f), chunkList.at(i).offsetTranslation);
		}
	}
	
}


void ChunkManager::Generate() {
	printf(std::to_string( GL_TIME_ELAPSED).c_str());

	for (int x = 0; x < 26; x++) {
		for (int z = 0; z < 26; z++) {
			
		}
	}
	printf(std::to_string(GL_TIME_ELAPSED).c_str());

}


void ChunkManager::DrawChunks() {
	for (int i = 0; i < chunkList.size(); i++) {

	}
}