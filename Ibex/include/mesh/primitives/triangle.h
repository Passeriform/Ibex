#pragma once

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../mesh.h"

class Triangle : public Mesh {
public:
	Triangle();
	int setupBuffers();
	int draw();
};

#endif
