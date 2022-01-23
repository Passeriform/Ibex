#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "cube.h"

Cube::Cube() :
	Mesh(
		{
			/*				Position						Normal													Color							Texture				*/
			/* SPIKE: Check why this configuration doesn't work
			Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	glm::vec3(-1 / sqrt(3),	-1 / sqrt(3),	1 / sqrt(3)),	glm::vec3(1.0f,  1.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),			// left-bottom-front
			Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	glm::vec3(1 / sqrt(3),	-1 / sqrt(3),	1 / sqrt(3)),	glm::vec3(1.0f,  1.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),			// right-bottom-front
			Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	glm::vec3(-1 / sqrt(3),	1 / sqrt(3),	1 / sqrt(3)),	glm::vec3(1.0f,  1.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),			// left-top-front
			Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(1 / sqrt(3),	1 / sqrt(3),	1 / sqrt(3)),	glm::vec3(1.0f,  1.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),			// right-top-front
			Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(-1 / sqrt(3),	-1 / sqrt(3),	-1 / sqrt(3)),	glm::vec3(1.0f,  1.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),			// left-bottom-back
			Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(1 / sqrt(3),	-1 / sqrt(3),	-1 / sqrt(3)),	glm::vec3(1.0f,  1.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),			// right-bottom-back
			Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	glm::vec3(-1 / sqrt(3),	1 / sqrt(3),	-1 / sqrt(3)),	glm::vec3(1.0f,  1.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),			// left-top-back
			Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	glm::vec3(1 / sqrt(3),	1 / sqrt(3),	-1 / sqrt(3)),	glm::vec3(0.0f,  1.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f)),			// right-top-back
			*/

			// Front
			Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  1.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(0.0f,   0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  1.0f,  1.0f)),

			// Back
			Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  1.0f,  1.0f)),
			Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	glm::vec3(0.0f,   0.0f, -1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  1.0f,  1.0f)),

			// Top
			Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  1.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	glm::vec3(0.0f,   1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  1.0f,  1.0f)),

			// Bottom
			Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  1.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	glm::vec3(0.0f,  -1.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  1.0f,  1.0f)),

			// Left
			Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(-0.5f, -0.5f,  0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(-0.5f,  0.5f, -0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  1.0f,  1.0f)),
			Vertex(glm::vec3(-0.5f,  0.5f,  0.5f),	glm::vec3(-1.0f,  0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  1.0f,  1.0f)),

			// Right
			Vertex(glm::vec3(0.5f,  -0.5f,  0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,   0.5f,  0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  1.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,   0.5f, -0.5f),	glm::vec3(1.0f,   0.0f,  0.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  1.0f,  1.0f)),
		},
		{
			/* Front */		/* Back */
			/*
			0,	1,	3,		5,	4,	6,
			0,	3,	2,		5,	6,	7,
			*/

			/* Top */		/* Bottom */
			/*
			2,	3,	7,		1,	0,	4,
			2,	7,	6,		1,	4,	5,
			*/

			/* Left */		/* Right */
			/*
			4,	0,	2,		7,	1,	5,
			4,	2,	6,		7,	3,	1
			*/

			/* Front */		/* Back */
			0,	1,	3,		4,	5,	7,
			0,	3,	2,		4,	7,	6,

			/* Top */		/* Bottom */
			8,	9,	11,		12,	13,	15,
			8,	11,	10,		12,	15,	14,

			/* Left */		/* Right */
			16, 17,	19,		20,	21,	23,
			16,	19,	18,		20,	23,	22
		}
	)
{ };

Cube::Cube(std::shared_ptr<Material> material) : Cube() {
	this->material = material;
}

Cube::Cube(Material& material) : Cube(std::make_shared<Material>(material)) { }

Cube::Cube(std::vector<Vertex> vertices, std::vector<unsigned int> locations) : Mesh(vertices, locations) { }

Cube::Cube(
	std::vector<Vertex> vertices,
	std::vector<unsigned int> locations,
	std::shared_ptr<Material> material
) : Cube(vertices, locations) {
	this->material = material;
}

Cube::Cube(
	std::vector<Vertex> vertices,
	std::vector<unsigned int> locations,
	Material& material
) : Cube(vertices, locations) {
	this->material = std::make_shared<Material>(material);
}
