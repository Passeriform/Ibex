#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "cube.h"

Cube::Cube() : Mesh({
	/*                Position                         Normal						    Color           */
	Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),

	Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),

	Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),

	Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),

	Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),

	Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),
	Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f))
	}) { }

}

Cube::Cube(std::vector<Vertex> vertices) : Mesh(vertices) { }

Cube::Cube(std::vector<glm::vec3> rawVec) : Mesh(rawVec) { }

Cube::Cube(std::vector<glm::vec3> posVec, std::vector<glm::vec3> normVec, std::vector<glm::vec3> colorVec) : Mesh(posVec, normVec, colorVec) { }

int Cube::setupBuffers() {
	// Separate VAO for each component initialized only once
	glGenVertexArrays(1, &VAO);

	// Bind the VAO
	glBindVertexArray(VAO);

	// Generate VBO for the component
	glGenBuffers(1, &VBO);

	// Bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	// Bind normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(1);

	// Bind color attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(2);

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}

int Cube::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glBindVertexArray(0);

	return 0;
}
