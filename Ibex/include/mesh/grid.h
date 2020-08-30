#pragma once

#ifndef GRID_H
#define GRID_H

#include "mesh.h"

class Grid : public Mesh {
	unsigned int IBO;

	std::vector<glm::uvec4> indices;

public:
	Grid(std::pair<int, int>, int, glm::vec3);
	int setupBuffers();
	int draw();
};

#endif
