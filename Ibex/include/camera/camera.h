#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <constants.h>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum class CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera {
public:
	// Camera Attributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	// Euler Angles
	float Yaw;
	float Pitch;

	// Camera options
	float MovementSpeed;
	float MouseSensitivity;
	float Zoom;

	Camera(
		glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		float yaw = Constants::YAW,
		float pitch = Constants::PITCH
	);

	Camera(
		float posX, float posY, float posZ,
		float upX, float upY, float upZ,
		float yaw, float pitch
	);

	// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
	glm::mat4 GetViewMatrix();

	// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
	void MoveCamera(CameraMovement direction, float deltaTime);

	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void RotateCamera(float xoffset, float yoffset, GLboolean constrainPitch = true);

	// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
	void ZoomCamera(float yoffset);

private:
	// Calculates the front vector from the Camera's (updated) Euler Angles
	void updateCameraVectors();
};

#endif
