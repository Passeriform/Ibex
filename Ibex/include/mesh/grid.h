#pragma once

#ifndef GRID_H
#define GRID_H

#include <mesh/mesh.h>

class Grid : public Mesh {
public:
	bool show;

	Grid(std::pair<int, int>, int, glm::vec3);

	int bindAttributes() override;
	int draw(World*, DrawOptions = { GL_LINES, false }) override;

};

#endif
