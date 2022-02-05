
#include"Time.h"
#include"Voxel.h"
#include"Chunk.h"

#include"ChunkManager.h"
#include"TextureArray.h"
#include<string>
#include<thread>
const unsigned int width = 800;
const unsigned int height = 800;
const float aspect = float(width) / height;
GLFWwindow* window;


int init() {

	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);
	
	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);

	
	// Initialize ImGUI
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");



	std::string newTitle = "OpenGL";
	glfwSetWindowTitle(window, newTitle.c_str());
}

int main()
{
	#pragma region Initialization
		init();

		// Generates Shader object using shaders default.vert and default.frag
		Shader shaderProgram = Shader("default.vert", "default.frag");

		// Take care of all the light related things
		glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		glm::vec3 lightPos = glm::vec3(0.5f, 1.0f, 0.5f);
		glm::mat4 lightModel = glm::mat4(1.0f);


		lightModel = glm::translate(lightModel, lightPos);

		shaderProgram.Activate();
		glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
		glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);



		// Enables the Depth Buffer
		glEnable(GL_DEPTH_TEST);
		// Enables Cull Facing
		glEnable(GL_CULL_FACE);
		// Keeps front faces
		glCullFace(GL_FRONT);
		// Uses counter clock-wise standard
		glFrontFace(GL_CCW);

		// Creates camera object
		Camera camera(width, height, glm::vec3(0.0f, 0.0f, 0.0f));
		camera.setup(window);


		// Variables to create periodic event for FPS displaying
		float prevTime = 0.0f;
		float crntTime = 0.0f;
		float timeDiff = 0.0f;
	#pragma endregion

	Time time = Time();

	bool draw = true;

	Texture textures[] = {
			Texture("planks.png","diffuse", 0)
	};

	ChunkManager chunkManager = ChunkManager();
	//chunkManager.Generate();

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Updates counter and times
		crntTime = time.GetElapsedTime();

		// Creates new title
		std::string ms = std::to_string((timeDiff));
		std::string fps = std::to_string((1/timeDiff));

		// Resets times and counter
		prevTime = crntTime;
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Tell OpenGL a new frame is about to begin
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();

		// Handles camera inputs (delete this if you have disabled VSync)
		camera.Inputs(window, timeDiff);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(90.0f, 0.1f, 1000.0f);



		chunkManager.Update(timeDiff, camera.Position, shaderProgram, camera);
		

		//GUI Labels
		#pragma region ImGUI
		// ImGUI window creation
		ImGui::Begin("My name is window, ImGUI window");
			ImGui::Checkbox("Draw", &draw);
			// Text that appears in the window
			ImGui::Text("Hello there adventurer!");

			




			if (chunkManager.chunkRenderList.size() > 0) {

				std::string numverts = "Number of verts: " + std::to_string(chunkManager.chunkRenderList.size() * chunkManager.chunkRenderList.at(0)->mesh.vertices.size());
				ImGui::Text(numverts.c_str());

				float memoryOfVerts = chunkManager.chunkRenderList.size() * chunkManager.chunkRenderList.at(0)->mesh.vertices.size() * sizeof(Vertex);
				std::string memverts = "Memory of verts: " + std::to_string(memoryOfVerts) + " bytes" + " (" + std::to_string(memoryOfVerts / 1000000) + " MB)";
				ImGui::Text(memverts.c_str());
			};

			


			std::string frameTime = "Current Time between Frames: " + ms + "ms";
			ImGui::Text(frameTime.c_str());

			std::string fpsTime = "FPS: " + fps + "";
			ImGui::Text(fpsTime.c_str());

			std::string currentPosition = "Current Position" + std::to_string(camera.Position.x) + "\n" + std::to_string(camera.Position.y) + "\n" + std::to_string(camera.Position.z);
			ImGui::Text(currentPosition.c_str());

			static float f0 = 0.0f;
			static float f1 = 0.0f;
			static float f2 = 0.0f;

			if (ImGui::InputFloat("X", &f0, 1.0f, 1.0f, "%1f")) {
				camera.Orientation = glm::vec3(0.0f, 0.0f, 1.0f);
				camera.Position.x = f0;
			}

			if (ImGui::InputFloat("Y", &f1, 1.0f, 1.0f, "%1f")) {
				camera.Orientation = glm::vec3(0.0f, 0.0f, 1.0f);
				camera.Position.y = f1;
			}

			if (ImGui::InputFloat("Z", &f2, 1.0f, 1.0f, "%1f")) {
				camera.Orientation = glm::vec3(0.0f, 0.0f, 1.0f);
				camera.Position.z = f2;
			}


			std::string blockPosition = "Current Position" + std::to_string(camera.Position.x) + "\n" + std::to_string(camera.Position.y) + "\n" + std::to_string(camera.Position.z);
			ImGui::Text(blockPosition.c_str());







		// Ends the window
		ImGui::End();
#pragma endregion



		// Renders the ImGUI elements
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		timeDiff = time.GetElapsedTime() - crntTime;
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects we've created
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}