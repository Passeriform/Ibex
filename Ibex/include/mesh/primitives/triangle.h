#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <mesh/mesh.h>

class Triangle : public Mesh {
public:
	Triangle();

	Triangle(Material&);
	Triangle(std::vector<Vertex>, std::vector<unsigned int>);
	Triangle(std::vector<Vertex>, std::vector<unsigned int>, Material&);
};

#endif
