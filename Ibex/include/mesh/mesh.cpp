#include "mesh.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Mesh::Mesh() { }


}

int Mesh::setupBuffers() {
	return 0;
}

int Mesh::draw() {
	return 0;
}

int Mesh::deleteBuffers() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

	return 0;
}

Vertex::Vertex(glm::vec3 position) {
	this->position = position;
}

Vertex::Vertex(glm::vec3 position, glm::vec3 color) {
	this->position = position;
	this->color = color;
}
