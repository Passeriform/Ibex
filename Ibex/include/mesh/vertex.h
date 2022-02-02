#pragma once

#ifndef VERTEX_H
#define VERTEX_H

#include <vector>
#include <glm/glm.hpp>

#include <material/material.h>

class Vertex {
public:
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec3 texturePosition;
	/*
	glm::vec3 Tangent;
	glm::vec3 Bitangent;
	unsigned int m_BoneIDs[MAX_BONE_INFLUENCE];
	float m_Weights[MAX_BONE_INFLUENCE];
	*/

	// Constructors with default fallbacks (Will accept values in order of parameters)
	Vertex(glm::vec3);
	Vertex(glm::vec3, glm::vec3, glm::vec3);
	Vertex(glm::vec3, glm::vec3, glm::vec3, glm::vec3);

	// Group composition builders (Will accept packed values and zip accordingly)
	std::vector<Vertex> fromRaw(std::vector<glm::vec3>);
	std::vector<Vertex> fromComponents(std::vector<glm::vec3>, std::vector<glm::vec3>, std::vector<glm::vec3>, std::vector<glm::vec3>);
};

#endif
