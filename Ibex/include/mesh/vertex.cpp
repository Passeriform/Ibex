#include "vertex.h"

Vertex::Vertex(glm::vec3 position) : position(position) { }

Vertex::Vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color) : Vertex(position) {
	this->normal = normal;
	this->color = color;
}

Vertex::Vertex(glm::vec3 position, glm::vec3 normal, glm::vec3 color, glm::vec3 texturePosition) : Vertex(position, normal, color) {
	this->texturePosition = texturePosition;
}


std::vector<Vertex> Vertex::fromRaw(std::vector<glm::vec3> rawVec) {
	auto vertexAttribCount = 4; // Position, Normal, Color and Texture
	std::vector<Vertex> vertices;

	for (auto i = 0; i < rawVec.size() - (vertexAttribCount - 1); i += vertexAttribCount) {
		vertices.emplace_back(Vertex(rawVec[i], rawVec[i + 1], rawVec[i + 2], rawVec[i + 3]));
	}

	return vertices;
}

std::vector<Vertex> Vertex::fromComponents(
	std::vector<glm::vec3> posVec,
	std::vector<glm::vec3> normVec,
	std::vector<glm::vec3> colorVec,
	std::vector<glm::vec3> texturePosVec
) {
	std::vector<Vertex> vertices;

	// TODO: Use algorithms instead.
	for (auto i = 0;
		i < posVec.size() &&
		i < normVec.size() &&
		i < colorVec.size() &&
		i < texturePosVec.size();
		i++) {
		vertices.emplace_back(Vertex(posVec[i], normVec[i], colorVec[i], texturePosVec[i]));
	}

	return vertices;
}