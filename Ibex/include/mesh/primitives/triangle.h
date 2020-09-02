#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../mesh.h"

class Triangle : public Mesh {
public:
	Triangle();
	Triangle(std::vector<Vertex>);
	Triangle(std::vector<glm::vec3>);
	Triangle(std::vector<glm::vec3>, std::vector<glm::vec3>, std::vector<glm::vec3>);
	int setupBuffers();
	int draw();
};

#endif
