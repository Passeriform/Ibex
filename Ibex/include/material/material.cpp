#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "material.h"

Material::Material() :
	ambient(glm::vec3(0.05f, 0.05f, 0.05f)),
	diffuse(glm::vec3(0.5f, 0.5f, 0.5f)),
	specular(glm::vec3(0.7f, 0.7f, 0.7f)),
	shininess(10) { }

Material::Material(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 specular, float shine) :
	ambient(ambient),
	diffuse(diffuse),
	specular(specular),
	shininess(shine) { }
