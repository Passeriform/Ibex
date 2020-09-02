#include "mesh.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Mesh::Mesh() { }

Mesh::Mesh(std::vector<Vertex> vertices) : vertices(vertices) { }

Mesh::Mesh(std::vector<glm::vec3> rawVecVertices) {
	auto vertexAttribCount = 3; // Position, Normal and Color
	for (auto i = 0; i < rawVecVertices.size() - (vertexAttribCount - 1); i += vertexAttribCount) {
		vertices.push_back(Vertex(rawVecVertices[i], rawVecVertices[i + 1], rawVecVertices[i + 2]));
	}
}

Mesh::Mesh(std::vector<glm::vec3> posVec, std::vector<glm::vec3> normVec, std::vector<glm::vec3> colorVec) {
	auto vertexAttribCount = 3; // Position, Normal and Color
	for (auto i = 0;
		i < posVec.size() &&
		i < normVec.size() &&
		i < colorVec.size();
		i++) {
		vertices.push_back(Vertex(posVec[i], normVec[i], colorVec[i]));
	}
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

Vertex::Vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color) {
	this->position = position;
	this->normal = normal;
	this->color = color;
}
