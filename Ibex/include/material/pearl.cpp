#include "pearl.h"

Pearl::Pearl() : Material(
	glm::vec3(0.25f, 0.20725f, 0.20725f),
	glm::vec3(1.0f, 0.829f, 0.829f),
	glm::vec3(0.296648f, 0.296648f, 0.296648f),
	11.264f
) { }

Pearl::Pearl(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shine) : Material(ambient, diffuse, specular, shine) { }
