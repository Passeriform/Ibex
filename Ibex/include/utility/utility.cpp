#include "utility.h"

GLFWwindowDeleter defaultWindowDeleter = [](GLFWwindow* window) { glfwSetWindowShouldClose(window, true); };
GLFWwindowDeleter emptyWindowDeleter = [](GLFWwindow*) {};
