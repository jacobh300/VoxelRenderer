#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include"imgui.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_opengl3.h"


#include"EBO.h"
#include<GLFW/glfw3.h>




#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaderClass.h"

class Camera {
	public:

		//Main vectors of the camera
		glm::vec3 Position;
		glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
		glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

		glm::mat4 cameraMatrix = glm::mat4(1.0f);



		// Prevents camera from jumping around when first rotating
		bool firstClick = true;




		int width;
		int height;
		float speed = 10000.0f;
		float sensitivity = 100.0f;

		Camera(int width, int height, glm::vec3 position);

		void setWidth(int width);
		void setHeight(int height);

		void updateMatrix(float FOVdeg, float nearPlane, float farPlane);

		void Matrix(Shader& shader, const char* uniform);

		void Inputs(GLFWwindow* window, float deltaTime);
		void setup(GLFWwindow* window);

};
#endif