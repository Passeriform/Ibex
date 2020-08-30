#pragma once

#ifndef MESH_H
#define MESH_H

#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "camera.h"
#include "../shader.h"

class Vertex {
public:
	glm::vec3 position;
	glm::vec3 color;
	Vertex(glm::vec3);
	Vertex(glm::vec3, glm::vec3);
};

class Mesh {
public:
	unsigned int VAO, VBO;
	std::vector<Vertex> vertices;
	std::vector<glm::vec3> locations;

	Mesh();
	virtual int setupBuffers();
	virtual int draw();
	virtual int deleteBuffers();
};

#endif