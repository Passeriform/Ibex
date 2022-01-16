#pragma once

#ifndef CUBE_H
#define CUBE_H

#include <mesh/mesh.h>

class Cube : public Mesh {
public:
	Cube();

	Cube(Material*);
	Cube(std::vector<Vertex>, std::vector<unsigned int>);
	Cube(std::vector<Vertex>, std::vector<unsigned int>, Material*);
};

#endif
