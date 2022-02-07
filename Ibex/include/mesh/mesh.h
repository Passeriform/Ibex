#pragma once

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <memory>

#include <material/material.h>
#include <mesh/vertex.h>
#include <shader/shader.h>

class World;

struct DrawOptions {
	GLenum drawMode;
	bool showWireframe;

	DrawOptions();
	DrawOptions(GLenum, bool);
};

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
	virtual int draw(World*, DrawOptions = { GL_TRIANGLES, false });
	virtual int deleteBuffers();
};

#endif
