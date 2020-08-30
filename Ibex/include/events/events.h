#pragma once

#ifndef EVENTS_H
#define EVENTS_H

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Event {
public:
	static bool lmb_down, mmb_down, rmb_down;
	static double dragInitX, dragInitY;

	static void tick(GLFWwindow*);

	static void error_callback(int, const char*);
	static void framebuffer_size_callback(GLFWwindow*, int, int);
	static void mouse_callback(GLFWwindow*, int, int, int);
	static void scroll_callback(GLFWwindow*, double, double);
};

#endif
