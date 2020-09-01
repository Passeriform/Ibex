#include <iostream>

#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader.h>
#include <world/camera.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void error_callback(int error, const char* description);
void mouse_callback(GLFWwindow* window, int button, int action, int mods);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);

const int gridSize = 32;
const unsigned int SCR_WIDTH = 32 * gridSize;
const unsigned int SCR_HEIGHT = 32 * gridSize;

float vertices[] = {
		-0.5f, -0.5f, -0.5f,		0.0f,  0.0f,  0.5f,
		 0.5f, -0.5f, -0.5f,		0.2f,  0.3f,  1.0f,
		 0.5f,  0.5f, -0.5f,		0.3f,  0.6f,  0.5f,
		 0.5f,  0.5f, -0.5f,		0.4f,  1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,		0.6f,  0.0f,  0.5f,
		-0.5f, -0.5f, -0.5f,		0.7f,  0.3f,  1.0f,
};

glm::vec3 cubePos[] = {
	glm::vec3(0.0f,  0.0f,  0.0f)
};

unsigned int VBO, VAO;

Shader worldShader;

bool lmb_down = false;
bool rmb_down = false;
bool mmb_down = false;

double dragInitX, dragInitY;

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;

float deltaTime = 0.1f;
float lastFrame = 0.0f;

int main(void)
{
	if (!glfwInit()) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Ibex Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Error:: Ibex failed to load up GLFW (Linking Error)" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetErrorCallback(error_callback);
	glfwSetMouseButtonCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD couldn't be loaded!!!" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	worldShader = Shader("shaders/Void/VoidVertex.vs", "shaders/Void/VoidFragment.fs");

	glGenVertexArrays(1, &VAO);

	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//glPointSize(10);
		//glLineWidth(2.5);

		worldShader.use();

		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		worldShader.setMat4("projection", projection);

		glm::mat4 view = camera.GetViewMatrix();
		worldShader.setMat4("view", view);

		//glBindVertexArray(VAO);
		for (unsigned int i = 0; i < 1; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePos[i]);
			float angle = 0.0f;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			worldShader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}

static void error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera.MoveCamera(CameraMovement::FORWARD, 3*deltaTime);
		else camera.MoveCamera(CameraMovement::FORWARD, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera.MoveCamera(CameraMovement::BACKWARD, 3*deltaTime);
		else camera.MoveCamera(CameraMovement::BACKWARD, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera.MoveCamera(CameraMovement::LEFT, 3*deltaTime);
		else camera.MoveCamera(CameraMovement::LEFT, deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera.MoveCamera(CameraMovement::RIGHT, 3*deltaTime);
		else camera.MoveCamera(CameraMovement::RIGHT, deltaTime);
	}

	if (mmb_down) {
		double dragCurrX, dragCurrY, xoffset, yoffset;
		glfwGetCursorPos(window, &dragCurrX, &dragCurrY);
		xoffset = dragCurrX - dragInitX;
		yoffset = dragInitY - dragCurrY;
		if (dragCurrX != dragInitX || dragCurrY != dragInitY) {
			camera.RotateCamera(xoffset, yoffset);
			dragInitX = dragCurrX;
			dragInitY = dragCurrY;
		}
	}
}

void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
		if (GLFW_PRESS == action) {
			if (!mmb_down) glfwGetCursorPos(window, &dragInitX, &dragInitY);
			mmb_down = true;
		}
		else if (GLFW_RELEASE == action) {
			mmb_down = false;
		}
	}
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ZoomCamera(yoffset);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}