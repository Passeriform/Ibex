#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <mesh/mesh.h>
#include <events/listeners.h>

#include "ibex.h"

using namespace Ibex;

Engine::Engine() : dumped(false) { };

int Engine::init() {
	// Window dimensions
	// (Better if fetched directly from the client window preferences.)
	double scrWidth = 32 * 32, scrHeight = 32 * 32;

	// Initialize GLFW
	if (!glfwInit()) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	// Set GLFW metadata
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Compatibility with OSX
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Create drawing window
	window = glfwCreateWindow(scrWidth, scrHeight, "Ibex Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Error:: Ibex failed to load up GLFW (Linking Error)" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Set current context
	glfwMakeContextCurrent(window);

	// Bind engine instance to the window
	glfwSetWindowUserPointer(window, this);

	// Disabled mouse cursor (To be enabled after iframe integration)
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Load GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "GLAD couldn't be loaded!!!" << std::endl;
		return -1;
	}

	// Enable testing with the depth buffer
	glEnable(GL_DEPTH_TEST);

	// Explicitly set window dimensions
	activeWorld->setWindow(
		WindowConfig{
			std::make_pair(scrWidth, scrHeight)     // dim
		}
	);

	// Load the world
	activeWorld->load();

	// Bind event callbacks
	glfwSetFramebufferSizeCallback(window, &Event::framebuffer_size_callback);
	glfwSetErrorCallback(&Event::error_callback);
	glfwSetMouseButtonCallback(window, &Event::mouse_callback);
	glfwSetScrollCallback(window, &Event::scroll_callback);

	return 0;
}

int Engine::tick() {
	// Tick events and process
	Event::tick(window);

	// Call the world tick callback
	activeWorld->onTick();

	// Swap buffers
	glfwSwapBuffers(window);

	// Poll for GLFW events
	glfwPollEvents();

	return 0;
}

int Engine::dump() {
	// Verify if core dumped
	if (!dumped) {
		dumped = true;
	}

	// Perform cleanup on the active world
	activeWorld->cleanup();

	glfwTerminate();

	return 0;
}
