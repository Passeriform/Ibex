#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "mesh.h"

Mesh::Mesh() :
	VAO(-1),
	VBO(-1),
	EBO(-1),
	vertices({}),
	locations({}),
	material(std::make_shared<Material>())
{ }

Mesh::Mesh(std::shared_ptr<Material> material) : Mesh() {
	this->material = material;
}

Mesh::Mesh(Material& material) : Mesh(std::make_shared<Material>(material)) { }

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> locations) : Mesh() {
	this->vertices = vertices;
	this->locations = locations;
}

Mesh::Mesh(
	std::vector<Vertex> vertices,
	std::vector<unsigned int> locations,
	std::shared_ptr<Material> material
) : Mesh(vertices, locations) {
	this->material = material;
}

Mesh::Mesh(
	std::vector<Vertex> vertices,
	std::vector<unsigned int> locations,
	Material& material
) : Mesh(vertices, locations, std::make_shared<Material>(material)) { }

int Mesh::setFlatColor(glm::vec3 flatColor) {
	for (int i = 0; i < vertices.size(); i++) {
		vertices[i].color = flatColor;
	}

	return 0;
}

int Mesh::setupBuffers() {
	/*								Buffer Generation									*/
	/* -------------------------------------------------------------------------------- */

	// Generate VAO for the component
	glGenVertexArrays(1, &VAO);

	// Generate VBO for the component
	glGenBuffers(1, &VBO);

	// Generate VBO for the component
	glGenBuffers(1, &EBO);

	/*								Buffer Binding										*/
	/* -------------------------------------------------------------------------------- */

	// Bind the VAO
	glBindVertexArray(VAO);

	// Bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	// Bind the EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, locations.size() * sizeof(unsigned int), &locations[0], GL_STATIC_DRAW);

	/*							Attribute Binding										*/
	/* -------------------------------------------------------------------------------- */

	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);

	// Bind normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
	glEnableVertexAttribArray(1);

	// Bind color attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));
	glEnableVertexAttribArray(2);

	// Bind texture attribute
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texturePosition));
	glEnableVertexAttribArray(3);

	/*
	// Bind tangent attribute
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Tangent));

	// Bind bitangent attribute
	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Bitangent));

	// ids
	glEnableVertexAttribArray(6);
	glVertexAttribIPointer(6, 4, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, m_BoneIDs));

	// weights
	glEnableVertexAttribArray(7);
	glVertexAttribPointer(7, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, m_Weights));
	*/

	/*								Cleanup												*/
	/* -------------------------------------------------------------------------------- */

	// Unbind the VAO
	glBindVertexArray(0);

	material->setupBuffers();

	return 0;
}

int Mesh::draw() {
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, locations.size(), GL_UNSIGNED_INT, NULL);
	glBindVertexArray(0);

	return 0;
}

int Mesh::deleteBuffers() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	return 0;
}
