#ifndef BLOCK_CLASS_HEADER
#define BLOCK_CLASS_HEADER

#include "Mesh.h"



enum BlockType {
	BlockType_Default = 0,
	BlockType_Grass,
	BlockType_Stone
};



class Block {
	public:
		Block();
		~Block();
		BlockType blockType;
		bool IsActive();
		void SetActive(bool active);

	private:
		bool active;
};




#endif