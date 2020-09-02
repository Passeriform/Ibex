#include "grid.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

Grid::Grid(std::pair<int, int> dim, int gridSize, glm::vec3 color) : Mesh() {
	int slicex = dim.first / (float)gridSize;
	int slicey = dim.second / (float)gridSize;

	for (int i = -(slicey / 2); i < (slicey / 2); i++) {
		for (int j = -(slicex / 2); j < (slicex / 2); j++) {
			float x = (float)j;
			float y = 0;
			float z = (float)i;

			vertices.push_back(Vertex(glm::vec3(x, y, z), glm::vec3(0.0f, 0.0f, 0.0f), color));
		}
	}

	for (int i = 0; i < slicey - 1; i++) {
		for (int j = 0; j < slicex - 1; j++) {
			int topLeft = (i * (slicex)) + j;
			int topRight = topLeft + 1;

			int bottomLeft = ((i + 1) * (slicex)) + j;
			int bottomRight = bottomLeft + 1;

			// Top-Right triangle
			indices.push_back(glm::uvec4(topLeft, topRight, topRight, bottomRight));
			// Bottom-Left triangle
			indices.push_back(glm::uvec4(bottomRight, bottomLeft, bottomLeft, topLeft));
		}
	}
}

int Grid::setupBuffers() {
	// Separate VAO for each component initialized only once
	glGenVertexArrays(1, &VAO);

	// Bind the VAO
	glBindVertexArray(VAO);

	// Generate VBO for the component
	glGenBuffers(1, &VBO);

	// Bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	// Bind color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);

	// Generate IBO for the grid
	glGenBuffers(1, &IBO);

	// Bind the IBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(glm::uvec4), indices.data(), GL_STATIC_DRAW);

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}

int Grid::draw() {
	glBindVertexArray(VAO);
	glDrawElements(GL_LINES, indices.size() * 4, GL_UNSIGNED_INT, NULL);
	glBindVertexArray(0);

	return 0;
}
