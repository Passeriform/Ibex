#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "triangle.h"

Triangle::Triangle() : Mesh() {
	vertices = {
		/*             Position                           Color           */
		Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f,  0.0f,  0.5f)),
		Vertex(glm::vec3(0.5f, -0.5f, -0.5f),  glm::vec3(0.2f,  0.3f,  1.0f)),
		Vertex(glm::vec3(0.5f,  0.5f, -0.5f),  glm::vec3(0.3f,  0.6f,  0.5f))
	};
}

int Triangle::setupBuffers() {
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

	// Bind color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(1);

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}

int Triangle::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, vertices.size());
	glBindVertexArray(0);

	return 0;
}
