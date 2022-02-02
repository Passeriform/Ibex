#include <algorithm>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "mesh.h"

Mesh::Mesh() :
	VAO(-1),
	VBO(-1),
	EBO(-1),
	vertices({}),
	locations({}),
	material(std::make_shared<Material>()),
	meshShader(nullptr),
	vertexShaderPath("shaders/meshShader.vert"),
	fragmentShaderPath("shaders/meshShader.frag")
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

Shader& Mesh::getShader() {
	return *meshShader;
}

int Mesh::setFlatColor(glm::vec3 flatColor) {
	std::for_each(
		vertices.begin(),
		vertices.end(),
		[&flatColor](Vertex& vertex) {
			vertex.color = flatColor;
		}
	);

	return 0;
}

int Mesh::genBuffers() {
	// Generate VAO for the component
	glGenVertexArrays(1, &VAO);

	// Generate VBO for the component
	glGenBuffers(1, &VBO);

	// Generate EBO for the component
	glGenBuffers(1, &EBO);

	return 0;
}

int Mesh::bindBuffers() {
	// Bind the VAO
	glBindVertexArray(VAO);

	// Bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

	// Bind the EBO
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, locations.size() * sizeof(unsigned int), &locations[0], GL_STATIC_DRAW);

	return 0;
}

int Mesh::bindAttributes() {
	// Bind vertex position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));
	glEnableVertexAttribArray(0);

	// Bind normal attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, normal)));
	glEnableVertexAttribArray(1);

	// Bind color attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, color)));
	glEnableVertexAttribArray(2);

	// Bind texture attribute
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, texturePosition)));
	glEnableVertexAttribArray(3);

	/*
	// Bind tangent attribute
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Tangent)));

	// Bind bitangent attribute
	glEnableVertexAttribArray(5);
	glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Bitangent)));

	// ids
	glEnableVertexAttribArray(6);
	glVertexAttribIPointer(6, 4, GL_INT, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, m_BoneIDs)));

	// weights
	glEnableVertexAttribArray(7);
	glVertexAttribPointer(7, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, m_Weights)));
	*/

	return 0;
}

int Mesh::setupBuffers() {
	// Initialize mesh shader
	meshShader = std::make_unique<Shader>(vertexShaderPath, fragmentShaderPath);

	genBuffers();
	bindBuffers();
	bindAttributes();

	// Cleanup: Unbind VAO
	glBindVertexArray(0);

	// Setup material buffers
	material->setupBuffers();

	return 0;
}

int Mesh::draw(std::shared_ptr<Camera> camera, std::pair<float, float> scrDim, GLenum drawMode) {
	// Using mesh shader
	meshShader->use();

	// Setting up model, view and projection matrices
	glm::mat4 model = glm::mat4(1.0f);
	glm::mat4 view = camera->getViewMatrix();
	glm::mat4 projection = glm::perspective(glm::radians(camera->zoom), static_cast<float>(scrDim.first) / static_cast<float>(scrDim.second), 0.1f, 100.0f);

	// Setting model, view and projection matrices in the shader
	meshShader->setMat4("model", model);
	meshShader->setMat4("view", view);
	meshShader->setMat4("projection", projection);

	// Set updated camera view position
	meshShader->setVec3("viewPos", camera->position);

	// Set material-light interaction parameters
	meshShader->setVec3("material.ambient", material->materialLightMap.ambient);		// Add ambient strength to shader

	// Set offset layout pointer for registered textures
	if (material->isTextured()) {
		meshShader->setInt("material.diffuse", 0);
		meshShader->setInt("material.specular", 1);
	}
	// Add explicit diffuse and specular strengths to shader
	else {
		meshShader->setVec3("material.diffuse", material->materialLightMap.diffuse);
		meshShader->setVec3("material.specular", material->materialLightMap.specular);
	}

	meshShader->setFloat("material.shininess", material->materialLightMap.shininess);	// Add shininess to shader

	// Bind the VAO before drawing lightSources
	glBindVertexArray(VAO);

	// Draw the elements
	glDrawElements(drawMode, locations.size(), GL_UNSIGNED_INT, NULL);

	// Unbind the VAO
	glBindVertexArray(0);

	return 0;
}

int Mesh::deleteBuffers() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	return 0;
}
