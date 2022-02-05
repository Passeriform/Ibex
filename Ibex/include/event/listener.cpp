#include <event/event.h>

#include "listener.h"

void Listener::error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void Listener::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Listener::mouse_callback(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		if (button == GLFW_MOUSE_BUTTON_LEFT) Event::lmbDown = true;
		if (button == GLFW_MOUSE_BUTTON_RIGHT) Event::rmbDown = true;
		if (button == GLFW_MOUSE_BUTTON_MIDDLE) Event::mmbDown = true;
	}
	else if (action == GLFW_RELEASE) {
		if (button == GLFW_MOUSE_BUTTON_LEFT) Event::lmbDown = false;
		if (button == GLFW_MOUSE_BUTTON_RIGHT) Event::rmbDown = false;
		if (button == GLFW_MOUSE_BUTTON_MIDDLE) Event::mmbDown = false;
	}
}

// Handles toggles events unlike event keyboard map that handles polled keys
void Listener::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	std::unique_ptr<Ibex::Engine, Ibex::EngineDeleter> engine(
		static_cast<Ibex::Engine*>(glfwGetWindowUserPointer(window)),
		Ibex::emptyEngineDeleter
	);
	std::unique_ptr<World>& world = engine->getActiveWorld();

	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_Z) world->toggleWireframe();
	}
}

void Listener::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	std::unique_ptr<Ibex::Engine, Ibex::EngineDeleter> engine(
		static_cast<Ibex::Engine*>(glfwGetWindowUserPointer(window)),
		Ibex::emptyEngineDeleter
	);
	std::shared_ptr<Camera> camera = engine->getActiveWorld()->getActiveCamera();

	if (Event::keyPressMap[GLFW_KEY_LEFT_SHIFT]) {
		camera->dollyCamera(static_cast<float>(yoffset));
	}
	else {
		camera->zoomCamera(static_cast<float>(yoffset));
	}
}