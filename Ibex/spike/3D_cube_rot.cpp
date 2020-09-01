#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Shader.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

bool lmb_down = false;
bool rmb_down = false;
bool mmb_down = false;

double dragInitX, dragInitY;

int main()
{
	glfwInit();

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

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD couldn't be loaded!!!" << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Shader worldShader("Shaders/worldShader.vs", "Shaders/worldShader.fs");

	float vertices[] = {
		-0.5f, -0.5f, -0.5f,		0.0f,  0.0f,  0.5f,
		 0.5f, -0.5f, -0.5f,		0.2f,  0.3f,  1.0f,
		 0.5f,  0.5f, -0.5f,		0.3f,  0.6f,  0.5f,
		 0.5f,  0.5f, -0.5f,		0.4f,  1.0f,  1.0f,
		-0.5f,  0.5f, -0.5f,		0.6f,  0.0f,  0.5f,
		-0.5f, -0.5f, -0.5f,		0.7f,  0.3f,  1.0f,
	};

	glm::vec3 cubePos[] = {
		glm::vec3( 0.0f,  0.0f,  0.0f)
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		worldShader.use();

		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		worldShader.setMat4("projection", projection);
		worldShader.setMat4("view", view);

		glBindVertexArray(VAO);
		for (unsigned int i = 0; i < 1; i++)
		{
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePos[i]);
			float angle = 20.0f * (float)glfwGetTime();
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			worldShader.setMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
		}

		//int vertexColorLocation = glGetUniformLocation(worldShader.ID, "vertexColor");
		//glUniform4f(vertexColorLocation, 0.0f, 0.0f, 0.0f, 1.0f);

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	glfwTerminate();
	return 0;
}

void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (GLFW_PRESS == action) {
			if (!lmb_down) glfwGetCursorPos(window, &dragInitX, &dragInitY);
			std::cout << "Start the party!\n";
			lmb_down = true;
		}
		else if (GLFW_RELEASE == action) {
			std::cout << "End Macabre!\n";
			lmb_down = false;
		}
	}
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	else if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		std::cout << "Gay";
	else if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		std::cout << "Lel";
	glfwSetMouseButtonCallback(window, mouse_callback);

	if (lmb_down) {
		double dragCurrX, dragCurrY;
		glfwGetCursorPos(window, &dragCurrX, &dragCurrY);
		if (dragCurrX != dragInitX || dragCurrY != dragInitY) {
			std::cout << "Shift more by>> (" << dragCurrX - dragInitX << ", " << dragCurrY - dragInitY << ")\n";
			dragInitX = dragCurrX;
			dragInitY = dragCurrY;
		}
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}