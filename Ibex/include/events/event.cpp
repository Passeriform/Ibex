#include <ibex.h>

#include "event.h"

bool Event::lmb_down = false, Event::rmb_down = false, Event::mmb_down = false;
double Event::dragInitX = DBL_MAX, Event::dragInitY = DBL_MAX;

void Event::tick(std::shared_ptr<GLFWwindow> window) {
	std::unique_ptr<Ibex::Engine, Ibex::EngineDeleter> engine(
		static_cast<Ibex::Engine*>(glfwGetWindowUserPointer(window.get())),
		Ibex::defaultEngineDeleter
	);
	std::shared_ptr<Camera> camera = engine->getActiveWorld()->getActiveCamera();

	// TODO: Recheck if qualifiers are string enough `const &`

	if (glfwGetKey(window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS) engine->dump();

	// TODO: Refactor all floats to double
	auto movementSpeed = camera->MovementSpeed;

	if (glfwGetKey(window.get(), GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) movementSpeed *= 3;

	if (glfwGetKey(window.get(), GLFW_KEY_W) == GLFW_PRESS) {
		camera->MoveCamera(CameraMovement::FORWARD, movementSpeed);
	}

	if (glfwGetKey(window.get(), GLFW_KEY_S) == GLFW_PRESS) {
		camera->MoveCamera(CameraMovement::BACKWARD, movementSpeed);
	}

	if (glfwGetKey(window.get(), GLFW_KEY_A) == GLFW_PRESS) {
		camera->MoveCamera(CameraMovement::LEFT, movementSpeed);
	}

	if (glfwGetKey(window.get(), GLFW_KEY_D) == GLFW_PRESS) {
		camera->MoveCamera(CameraMovement::RIGHT, movementSpeed);
	}

	if (mmb_down) {
		double dragCurrX, dragCurrY, xoffset, yoffset;

		glfwGetCursorPos(window.get(), &dragCurrX, &dragCurrY);

		if (dragInitX == DBL_MAX || dragInitY == DBL_MAX) {
			dragInitX = dragCurrX;
			dragInitY = dragCurrY;
		}

		xoffset = dragCurrX - dragInitX;
		yoffset = dragInitY - dragCurrY;

		if (dragCurrX != dragInitX || dragCurrY != dragInitY) {
			camera->RotateCamera(xoffset, yoffset);
			dragInitX = dragCurrX;
			dragInitY = dragCurrY;
		}
	}
}
