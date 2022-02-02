#include <glad/glad.h>

#include <boost/algorithm/clamp.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) :
	front(glm::vec3(0.0f, 0.0f, -1.0f)),
	movementSpeed(Constants::SPEED),
	mouseSensitivity(Constants::SENSITIVITY),
	zoom(Constants::ZOOM),
	inverted(false),
	position(position),
	worldUp(up),
	yaw(yaw),
	pitch(pitch)
{
	updateCameraVectors();
}

// Constructor with scalar values
Camera::Camera(
	float posX, float posY, float posZ,
	float upX, float upY, float upZ,
	float yaw, float pitch
) :
	Camera(glm::vec3(posX, posY, posZ), glm::vec3(upX, upY, upZ), yaw, pitch)
{ }

glm::mat4 Camera::getViewMatrix() {
	return glm::lookAt(position, position + front, up);
}

/// Dolly, Truck and Pedestal
void Camera::moveCamera(CameraMovement direction, float deltaTime) {
	float velocity = movementSpeed * deltaTime;
	if (direction == CameraMovement::FORWARD) position += front * velocity;
	if (direction == CameraMovement::BACKWARD) position -= front * velocity;
	if (direction == CameraMovement::LEFT) position -= right * velocity;
	if (direction == CameraMovement::RIGHT) position += right * velocity;
	if (direction == CameraMovement::UP) position += up * velocity;
	if (direction == CameraMovement::DOWN) position -= up * velocity;
}


/// Pan and Tilt
///
/// Processes input received from a mouse input system. Expects the offset value
/// in both the x and y direction.
void Camera::rotateCamera(float xoffset, float yoffset, GLboolean constrainPitch) {
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	yaw += (inverted ? -xoffset : xoffset);
	pitch += (inverted ? -xoffset : yoffset);

	// Make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch) {
		pitch = boost::algorithm::clamp(pitch, -89.0f, 89.0f);
	}

	// Update front, right and up vectors using the updated Euler angles
	updateCameraVectors();
}

/// Zoom
///
/// Processes input received from a mouse scroll-wheel event. Requires input
/// on the vertical wheel-axis
void Camera::zoomCamera(float yoffset) {
	zoom = boost::algorithm::clamp(zoom - yoffset, 1.0f, 45.0f);

	// Update front, right and up vectors using the updated Euler angles
	updateCameraVectors();
}

/// Dolly
///
/// Dolly movement forwards/backwards
void Camera::dollyCamera(float offset) {
	if ((zoom - offset) == boost::algorithm::clamp(zoom - offset, 1.0f, 45.0f)) {
		zoomCamera(offset);
		moveCamera((offset < 0) ? CameraMovement::FORWARD : CameraMovement::BACKWARD, abs(offset));
	}
}

void Camera::updateCameraVectors() {
	// Calculate the new front vector
	glm::vec3 newFront;
	newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newFront.y = sin(glm::radians(pitch));
	newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(newFront);
	// Also re-calculate the right and up vector
	right = glm::normalize(glm::cross(front, worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = glm::normalize(glm::cross(right, front));
}
