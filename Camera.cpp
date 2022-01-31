#include"Camera.h"


Camera::Camera(int width, int height, glm::vec3 position) {
	Camera::width = width;
	Camera::height = height;

	Position = position;



}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane) {

	//Create matrices for view and projection, need to create mat4(1.0f) otherwise they will be null matrices.
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	//makes famera look in the correct direction from the correct position.
	view = glm::lookAt(Position, Position + Orientation, Up);
	//Perspective to the projection matrix
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / (float)height, nearPlane, farPlane);


	cameraMatrix = projection * view;

}
void Camera::setHeight(int height) {
	Camera::height = height;
}

void Camera::setWidth(int width) {
	Camera::width = width;
}

void Camera::setup(GLFWwindow *window) {

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height)
		{

			glViewport(0, 0, width, height);
			
			//Do Something
		});
}

void Camera::Matrix(Shader& shader, const char* uniform) {

	// Exports the camera matrix to the vertex shader.
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));

}




void Camera::Inputs(GLFWwindow* window, float deltaTime) {



	//Key Inputs.
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS ) {
		Position += speed * (deltaTime * 1000) * Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		Position += speed * (deltaTime * 1000) * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		Position += speed * (deltaTime * 1000) * -Orientation;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		Position += speed * (deltaTime * 1000) * glm::normalize(glm::cross(Orientation, Up));
	}


	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
		Position += speed * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		Position += speed * -Up;
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		speed = 0.4f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
		speed = 0.1f;
	}

	if (ImGui::GetIO().WantCaptureMouse) return;

	//Mouse inputs
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {

		//Hides mouse cursor
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		// Centers the mouse in the middle of the screen when clicking.
		if (firstClick) {
			glfwSetCursorPos(window, (width / 2), (height / 2));
			firstClick = false;
		}

		//Stores coordinates of mouse
		double mouseX;
		double mouseY;
		//Sends coordinates of mouse to variables.
		glfwGetCursorPos(window, &mouseX, &mouseY);

		//Normalize and shifts the coordinates of the cursor such that they begin in the middle of the screen
		//and then "transforms them into degrees.
		float rotX = sensitivity * (float)(mouseY - (height / 2)) / height;
		float rotY = sensitivity * (float)(mouseX - (width / 2)) / width;

		//Calculate the vertical change in orientation
		//Uses cross product to find the Z axis to rotate the camera Up/Down.
		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotX), glm::normalize(glm::cross(Orientation, Up))); 

		//Deciedes whether or not the next vertical orientation is over maximum/under minimum. (To prevent player from rotating full 360.)
		if (!(glm::angle(newOrientation, Up) <= glm::radians(5.0f) or (glm::angle(newOrientation, -Up) <= glm::radians(5.0f)))) {
			Orientation = newOrientation;
		}

		//Roates the camera left and right. 
		Orientation = glm::rotate(Orientation, glm::radians(-rotY), Up);

		//Resets cursor to the middle of the screen.
		glfwSetCursorPos(window, (width / 2), (height / 2));

	}
	//Release mouse click condition
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_RELEASE) {
		//Unhides cursor
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		//Makes sure the next time the camera looks around it doesn't jump
		firstClick = true;
	}



}