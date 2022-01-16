#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "triangle.h"

Triangle::Triangle() :
	Mesh(
		{
			/*				Position						Normal							Color							Texture				*/
			Vertex(glm::vec3(-0.5f, -0.5f, -0.5f),	glm::vec3(0.0f,  0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(0.5f,  -0.5f, -0.5f),	glm::vec3(0.0f,  0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(1.0f,  0.0f,  1.0f)),
			Vertex(glm::vec3(0.0f,   0.5f, -0.5f),	glm::vec3(0.0f,  0.0f,  1.0f),	glm::vec3(1.0f,  1.0f,  1.0f), glm::vec3(0.5f,  1.0f,  1.0f))
		},
		{
			0, 1, 2
		}
	)
{ };

Triangle::Triangle(Material* material) : Triangle() {
	this->material = material;
}

Triangle::Triangle(std::vector<Vertex> vertices, std::vector<unsigned int> locations) : Mesh(vertices, locations) { }

Triangle::Triangle(
	std::vector<Vertex> vertices,
	std::vector<unsigned int> locations,
	Material* material
) : Mesh(vertices, locations) {
	this->material = material;
}
