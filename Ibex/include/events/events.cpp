#include <float.h>

#include "events.h"

#include "ibex.h"

bool Event::lmb_down = false, Event::rmb_down = false, Event::mmb_down = false;

double Event::dragInitX = DBL_MAX, Event::dragInitY = DBL_MAX;

void Event::tick(GLFWwindow* window)
{
	Ibex::Engine* engine = (Ibex::Engine*)glfwGetWindowUserPointer(window);

	Camera* camera = &engine->activeWorld->camera.instance;

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		engine->dumped = true;

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera->MoveCamera(CameraMovement::FORWARD, 3 * camera->MovementSpeed);
		else camera->MoveCamera(CameraMovement::FORWARD, camera->MovementSpeed);
	}

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera->MoveCamera(CameraMovement::BACKWARD, 3 * camera->MovementSpeed);
		else camera->MoveCamera(CameraMovement::BACKWARD, camera->MovementSpeed);
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera->MoveCamera(CameraMovement::LEFT, 3 * camera->MovementSpeed);
		else camera->MoveCamera(CameraMovement::LEFT, camera->MovementSpeed);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera->MoveCamera(CameraMovement::RIGHT, 3 * camera->MovementSpeed);
		else camera->MoveCamera(CameraMovement::RIGHT, camera->MovementSpeed);
	}

	if (mmb_down) {
		double dragCurrX, dragCurrY, xoffset, yoffset;

		glfwGetCursorPos(window, &dragCurrX, &dragCurrY);

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
