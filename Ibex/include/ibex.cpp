#include <iostream>
#include <event/event.h>
#include <event/listener.h>

#include "ibex.h"

using namespace Ibex;

EngineDeleter Ibex::defaultEngineDeleter = [](Engine* core) { core->dump(); };
EngineDeleter Ibex::emptyEngineDeleter = [](Engine*) {};

Engine::Engine() :
	window(std::unique_ptr<GLFWwindow, GLFWwindowDeleter> {nullptr, defaultWindowDeleter}),
	activeWorld(std::unique_ptr<World>(nullptr)),
	isDumped(false)
{ };

Engine::Engine(Engine& engine) :
	window(std::move(engine.window)),
	activeWorld(std::move(engine.activeWorld)),
	isDumped(engine.isDumped)
{}

int Engine::init() {
	// Window dimensions
	// TODO: [Waiting for Qt] Fetch from the client window preferences.
	float scrWidth = 32 * 32, scrHeight = 32 * 32;

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
	GLFWwindow* window(glfwCreateWindow(scrWidth, scrHeight, "Ibex Engine", NULL, NULL));
	if (window == nullptr) {
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
	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
	{
		std::cout << "GLAD couldn't be loaded!!!" << std::endl;
		return -1;
	}

	this->window.reset(window);

	// Enable testing with the depth buffer
	glEnable(GL_DEPTH_TEST);

	// Explicitly set window dimensions
	activeWorld->setWindowDim(scrWidth, scrHeight);

	// Load the world
	activeWorld->load();

	// Bind event callbacks
	glfwSetFramebufferSizeCallback(window, &Listener::framebuffer_size_callback);
	glfwSetErrorCallback(&Listener::error_callback);
	glfwSetMouseButtonCallback(window, &Listener::mouse_callback);
	glfwSetScrollCallback(window, &Listener::scroll_callback);
	glfwSetKeyCallback(window, &Listener::key_callback);

	return 0;
}

int Engine::tick() {
	// Tick events and process
	Event::tick(
		std::shared_ptr<GLFWwindow>(window.get(), emptyWindowDeleter)
	);

	// Call the world tick callback
	activeWorld->onTick();

	// Swap buffers
	glfwSwapBuffers(window.get());

	// Poll for GLFW events
	glfwPollEvents();

	return 0;
}

int Engine::dump() {
	// Verify if core dumped
	if (!dumped) {
		isDumped = true;
	}

	// Perform cleanup on the active world
	activeWorld->cleanup();

	glfwTerminate();

	return 0;
}

std::unique_ptr<World>& Engine::getActiveWorld() {
	return activeWorld;
}
