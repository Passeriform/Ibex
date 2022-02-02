#pragma once

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <material/material.h>
#include <mesh/vertex.h>
#include <camera/camera.h>
#include <shader/shader.h>
#include <shader/texture.h>

class Mesh {
protected:
	unsigned int VAO, VBO, EBO;
	std::vector<Vertex> vertices;
	std::vector<unsigned int> locations;
	std::string vertexShaderPath, fragmentShaderPath;
	std::unique_ptr<Shader> meshShader;

	// Chunk buffer setup methods to individually overload.
	virtual int genBuffers();
	virtual int bindBuffers();
	virtual int bindAttributes();

public:
	std::shared_ptr<Material> material;

	Mesh();
	Mesh(Material&);
	Mesh(std::shared_ptr<Material>);
	Mesh(std::vector<Vertex>, std::vector<unsigned int>);
	Mesh(std::vector<Vertex>, std::vector<unsigned int>, Material&);
	Mesh(std::vector<Vertex>, std::vector<unsigned int>, std::shared_ptr<Material>);

	Shader& getShader();
	int setFlatColor(glm::vec3);

	// Necessary overloadable caller methods.
	virtual int setupBuffers();
	virtual int draw(std::shared_ptr<Camera>, std::pair<float, float>, GLenum drawMode = GL_TRIANGLES);
	virtual int deleteBuffers();
};

#endif
