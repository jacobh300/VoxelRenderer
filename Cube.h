#ifndef CUBE_CLASS_H
#define CUBE_CLASS_H

#include"Mesh.h"
#include"Camera.h"




class Cube {



	public:
		VAO VAO;
		Cube();
		Mesh genMesh();
		void Render(Mesh mesh, Shader shaderProgram, Camera camera);
		

	private:
		int x, y, z;

};


#endif