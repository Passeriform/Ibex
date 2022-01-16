#pragma once

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <material/material.h>
#include <mesh/vertex.h>
#include <shader/texture.h>

class Mesh {
protected:
	unsigned int VAO, VBO, EBO;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> locations;

public:
	Material* material;

	Mesh();

	Mesh(Material*);
	Mesh(std::vector<Vertex>, std::vector<unsigned int>);
	Mesh(std::vector<Vertex>, std::vector<unsigned int>, Material*);

	int setFlatColor(glm::vec3);

	virtual int setupBuffers();
	virtual int draw();
	virtual int deleteBuffers();
};

#endif
