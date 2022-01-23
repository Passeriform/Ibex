#include "event.h"
#include "listener.h"

void Listener::error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void Listener::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

// TODO: Convert events to GLFWKeyCallback

void Listener::mouse_callback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
		if (GLFW_PRESS == action) {
			if (!Event::mmb_down) glfwGetCursorPos(window, &Event::dragInitX, &Event::dragInitY);
			Event::mmb_down = true;
		}
		else if (GLFW_RELEASE == action) {
			Event::mmb_down = false;
		}
	}
}

void Listener::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	std::unique_ptr<Ibex::Engine, Ibex::EngineDeleter> engine(
		static_cast<Ibex::Engine*>(glfwGetWindowUserPointer(window)),
		Ibex::defaultEngineDeleter
	);
	std::shared_ptr<Camera> camera = engine->getActiveWorld()->getActiveCamera();
	camera->ZoomCamera(yoffset);
}