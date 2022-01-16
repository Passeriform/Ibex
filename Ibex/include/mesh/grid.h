#pragma once

#ifndef GRID_H
#define GRID_H

#include "mesh.h"

class Grid : public Mesh {
public:
	Grid(std::pair<int, int>, int, glm::vec3);

	virtual int draw();
};

#endif
