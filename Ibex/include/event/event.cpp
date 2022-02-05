#include <algorithm>

#include <ibex.h>

#include "event.h"

bool Event::lmbDown = false, Event::rmbDown = false, Event::mmbDown = false;
double Event::dragInitX = DBL_MAX, Event::dragInitY = DBL_MAX, Event::dragCurrX = DBL_MAX, Event::dragCurrY = DBL_MAX, Event::xOffset = 0, Event::yOffset = 0;
std::unordered_map<unsigned int, bool> Event::keyPressMap;

bool Event::anyDragInitiatorDown() { return lmbDown || rmbDown || mmbDown; }

void Event::refreshKeyMap(std::shared_ptr<GLFWwindow> window) {
	std::for_each(
		validKeys.begin(),
		validKeys.end(),
		[&window](const unsigned int& key) {
			keyPressMap[key] = glfwGetKey(window.get(), key) == GLFW_PRESS;
		}
	);
}

void Event::computeDrag(std::shared_ptr<GLFWwindow> window) {
	glfwGetCursorPos(window.get(), &dragCurrX, &dragCurrY);

	// First initialization of previous state.
	if (dragInitX == DBL_MAX || dragInitY == DBL_MAX) {
		dragInitX = dragCurrX;
		dragInitY = dragCurrY;
	}

	xOffset = dragCurrX - dragInitX;
	yOffset = dragInitY - dragCurrY;

	dragInitX = dragCurrX;
	dragInitY = dragCurrY;
}

void Event::resetDragInit() {
	dragInitX = DBL_MAX;
	dragInitY = DBL_MAX;
}

void Event::tick(std::shared_ptr<GLFWwindow> window) {
	refreshKeyMap(window);
	if (anyDragInitiatorDown()) {
		computeDrag(window);
	}
	else {
		resetDragInit();
	}

	std::unique_ptr<Ibex::Engine, Ibex::EngineDeleter> engine(
		static_cast<Ibex::Engine*>(glfwGetWindowUserPointer(window.get())),
		Ibex::emptyEngineDeleter
	);
	std::shared_ptr<Camera> camera = engine->getActiveWorld()->getActiveCamera();

	// TODO: Add `const &` wherever required

	if (keyPressMap[GLFW_KEY_ESCAPE]) engine->dump();

	auto movementSpeed = camera->movementSpeed;

	if (Event::keyPressMap[GLFW_KEY_LEFT_SHIFT]) movementSpeed *= 3;

	if (keyPressMap[GLFW_KEY_W]) camera->moveCamera(CameraMovement::FORWARD, movementSpeed);
	if (keyPressMap[GLFW_KEY_A]) camera->moveCamera(CameraMovement::LEFT, movementSpeed);
	if (keyPressMap[GLFW_KEY_S]) camera->moveCamera(CameraMovement::BACKWARD, movementSpeed);
	if (keyPressMap[GLFW_KEY_D]) camera->moveCamera(CameraMovement::RIGHT, movementSpeed);

	if (xOffset || yOffset) {
		if (mmbDown) {
			// TODO: Rotate across selected object orbit. [ALT]
			// TODO: Roll across axis. [CONTROL]
			if (keyPressMap[GLFW_KEY_LEFT_SHIFT]) {
				camera->moveCamera(yOffset > 0 ? CameraMovement::UP : CameraMovement::DOWN, movementSpeed);
			}
			else {
				camera->rotateCamera(xOffset, yOffset);
			}
		}
	}
}
