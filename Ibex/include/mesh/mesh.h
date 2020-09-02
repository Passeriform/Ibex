#pragma once

#ifndef MESH_H
#define MESH_H

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <material/material.h>

class Vertex {
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	Vertex(glm::vec3);
	Vertex(glm::vec3, glm::vec3, glm::vec3);
};

class Mesh {
public:
	unsigned int VAO, VBO;
	std::vector<Vertex> vertices;
	std::vector<glm::vec3> locations;

	Material* material;

	Mesh();
	Mesh(Material*);
	Mesh(std::vector<Vertex>);
	Mesh(std::vector<glm::vec3>);
	Mesh(std::vector<glm::vec3>, std::vector<glm::vec3>, std::vector<glm::vec3>);
	virtual int setupBuffers();
	virtual int draw();
	virtual int deleteBuffers();
};

#endif
