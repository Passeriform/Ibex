#pragma once

#ifndef LISTENER_H
#define LISTENER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <ibex.h>

class Listener {
public:
	static void error_callback(int, const char*);
	static void framebuffer_size_callback(GLFWwindow*, int, int);
	static void mouse_callback(GLFWwindow*, int, int, int);
	static void scroll_callback(GLFWwindow*, double, double);
};

#endif
