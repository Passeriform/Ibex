#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <constants.h>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum class CameraMovement {
	// Dolly
	FORWARD,
	BACKWARD,

	// Truck
	LEFT,
	RIGHT,

	// Pedestal
	UP,
	DOWN,
};

// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
class Camera {
public:
	// Camera Attributes
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	// Euler Angles
	float yaw;
	float pitch;

	// Camera options
	float movementSpeed;
	float mouseSensitivity;
	float zoom;
	bool inverted;

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
	glm::mat4 getViewMatrix();

	// Move camera across scene
	void moveCamera(CameraMovement, float);

	// Yaw, pan and (eventually) roll
	void rotateCamera(float, float, GLboolean constrainPitch = true);

	// Set zoom level for camera
	void zoomCamera(float);

	// Move dolly camera forwards/backwards
	void dollyCamera(float);

private:
	// Calculates the front vector from the Camera's (updated) Euler Angles
	void updateCameraVectors();
};

#endif
