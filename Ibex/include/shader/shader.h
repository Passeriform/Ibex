#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Shader {
	unsigned int setupShader(unsigned int, const std::string&);
	std::string loadSource(const std::string&);
	unsigned int compileSource(unsigned int, std::string);
	unsigned int bind(std::initializer_list<unsigned int>);

	void checkCompileErrors(GLuint, std::string);

public:
	unsigned int ID;

	Shader();

	Shader(const std::string&, const std::string&);
	Shader(const std::string&, const std::string&, const std::string&);

	void use();

	// Convenience shader varianble setters
	void setBool(const std::string&, bool) const;
	void setInt(const std::string&, int) const;
	void setFloat(const std::string&, float) const;
	void setVec2(const std::string&, const glm::vec2&) const;
	void setVec2(const std::string&, float, float) const;
	void setVec3(const std::string&, const glm::vec3&) const;
	void setVec3(const std::string&, float, float, float) const;
	void setVec4(const std::string&, const glm::vec4&) const;
	void setVec4(const std::string&, float, float, float, float);
	void setMat2(const std::string&, const glm::mat2&) const;
	void setMat3(const std::string&, const glm::mat3&) const;
	void setMat4(const std::string&, const glm::mat4&) const;

	// Utility method for debug output
	std::string getLogTypeString(unsigned int);
};

#endif
