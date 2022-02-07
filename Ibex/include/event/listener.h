#pragma once

#ifndef LISTENER_H
#define LISTENER_H

// High latency event listeners. If high speed events required, add to events instead.
namespace Listener {
	void error_callback(int, const char*);
	void framebuffer_size_callback(GLFWwindow*, int, int);
	void mouse_callback(GLFWwindow*, int, int, int);
	void key_callback(GLFWwindow*, int, int, int, int);
	void scroll_callback(GLFWwindow*, double, double);
};

#endif
