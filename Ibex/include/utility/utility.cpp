#include "utility.h"

GLFWwindowDeleter defaultWindowDeleter = [](GLFWwindow* window) { glfwSetWindowShouldClose(window, true); };
GLFWwindowDeleter emptyWindowDeleter = [](GLFWwindow*) {};

void run_contextually(std::function<void()> ctor, std::function<void()> dtor, std::function<void()> delegate) {
	ctor();
	delegate();
	dtor();
	return;
}
