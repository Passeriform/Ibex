#pragma once

#ifndef EVENT_H
#define EVENT_H

#include <memory>
#include <vector>
#include <unordered_map>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Low latency event processing
namespace Event {
	namespace {
		std::vector<unsigned int> validKeys = {
			GLFW_KEY_W,
			GLFW_KEY_A,
			GLFW_KEY_S,
			GLFW_KEY_D,
			GLFW_KEY_ESCAPE,
			GLFW_KEY_LEFT_SHIFT
		};
	}

	extern std::unordered_map<unsigned int, bool> keyPressMap;

	extern bool lmbDown, rmbDown, mmbDown;

	extern double dragInitX, dragInitY, dragCurrX, dragCurrY, xOffset, yOffset;

	// Helper methods to populate the periphery states to enact on. Must be called before taking any action
	void refreshKeyMap(std::shared_ptr<GLFWwindow> window);
	void computeDrag(std::shared_ptr<GLFWwindow> window);
	void resetDragInit();

	// Event ticking method. To be called every render cycle. Remove call to disable all controls.
	void tick(std::shared_ptr<GLFWwindow>);

	// Convenience shorthand for checking press state for any button that can initiate a drag.
	bool anyDragInitiatorDown();
};

#endif
