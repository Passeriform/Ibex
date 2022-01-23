#include <glad/glad.h>

#include <boost/algorithm/clamp.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) :
	Front(glm::vec3(0.0f, 0.0f, -1.0f)),
	MovementSpeed(Constants::SPEED),
	MouseSensitivity(Constants::SENSITIVITY),
	Zoom(Constants::ZOOM)
{
	Position = position;
	WorldUp = up;
	Yaw = yaw;
	Pitch = pitch;
	updateCameraVectors();
}

// Constructor with scalar values
Camera::Camera(
	float posX, float posY, float posZ,
	float upX, float upY, float upZ,
	float yaw, float pitch
) :
	Front(glm::vec3(0.0f, 0.0f, -1.0f)),
	MovementSpeed(Constants::SPEED),
	MouseSensitivity(Constants::SENSITIVITY),
	Zoom(Constants::ZOOM)
{
	Position = glm::vec3(posX, posY, posZ);
	WorldUp = glm::vec3(upX, upY, upZ);
	Yaw = yaw;
	Pitch = pitch;
	updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() {
	return glm::lookAt(Position, Position + Front, Up);
}

void Camera::MoveCamera(CameraMovement direction, float deltaTime) {
	float velocity = MovementSpeed * deltaTime;
	if (direction == CameraMovement::FORWARD) Position += Front * velocity;
	if (direction == CameraMovement::BACKWARD) Position -= Front * velocity;
	if (direction == CameraMovement::LEFT) Position -= Right * velocity;
	if (direction == CameraMovement::RIGHT) Position += Right * velocity;
}

// Processes input received from a mouse input system. Expects the offset value
// in both the x and y direction.
void Camera::RotateCamera(float xoffset, float yoffset, GLboolean constrainPitch) {
	xoffset *= MouseSensitivity;
	yoffset *= MouseSensitivity;

	Yaw += xoffset;
	Pitch += yoffset;

	// Make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch) {
		Pitch = boost::algorithm::clamp(Pitch, -89.0f, 89.0f);
	}

	// Update Front, Right and Up Vectors using the updated Euler angles
	updateCameraVectors();
}

// Processes input received from a mouse scroll-wheel event. Only requires input
// on the vertical wheel-axis
void Camera::ZoomCamera(float yoffset) {
	Zoom = boost::algorithm::clamp(Zoom - yoffset, 1.0f, 45.0f);
}

void Camera::updateCameraVectors() {
	// Calculate the new Front vector
	glm::vec3 front;
	front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	front.y = sin(glm::radians(Pitch));
	front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	Front = glm::normalize(front);
	// Also re-calculate the Right and Up vector
	Right = glm::normalize(glm::cross(Front, WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	Up = glm::normalize(glm::cross(Right, Front));
}
