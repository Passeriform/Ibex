#pragma once

#ifndef CUBE_H
#define CUBE_H

#include "../mesh.h"

class Cube : public Mesh {
public:
	Cube();
	Cube(Material*);
	Cube(std::vector<Vertex>);
	Cube(std::vector<glm::vec3>);
	Cube(std::vector<glm::vec3>, std::vector<glm::vec3>, std::vector<glm::vec3>);
	int setupBuffers();
	int draw();
};

#endif
