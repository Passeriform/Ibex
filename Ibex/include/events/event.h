#pragma once

#ifndef EVENT_H
#define EVENT_H

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Event {
public:
	static bool lmb_down, mmb_down, rmb_down;
	static double dragInitX, dragInitY;

	static void tick(std::shared_ptr<GLFWwindow>);
};

#endif
