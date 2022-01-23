#pragma once

#ifndef CUBE_H
#define CUBE_H

#include <mesh/mesh.h>

class Cube : public Mesh {
public:
	Cube();

	Cube(std::shared_ptr<Material>);
	Cube(Material&);
	Cube(std::vector<Vertex>, std::vector<unsigned int>);
	Cube(std::vector<Vertex>, std::vector<unsigned int>, std::shared_ptr<Material>);
	Cube(std::vector<Vertex>, std::vector<unsigned int>, Material&);
};

#endif
