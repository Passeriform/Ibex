#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ibex.h"
#include "world/camera.h"
#include "events.h"

void Event::error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void Event::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void Event::mouse_callback(GLFWwindow* window, int button, int action, int mods) {
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


void Event::scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	Ibex::Engine* engine = (Ibex::Engine*)glfwGetWindowUserPointer(window);
	
	Camera* camera = &engine->activeWorld->camera.instance;

	camera->ZoomCamera(yoffset);
}