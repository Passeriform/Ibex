#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>

#include "shader.h"

Shader::Shader() : ID(-1) { }

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) : Shader() {
	unsigned int vertexShaderId = setupShader(GL_VERTEX_SHADER, vertexShaderPath);
	unsigned int fragmentShaderId = setupShader(GL_FRAGMENT_SHADER, fragmentShaderPath);

	bind({ vertexShaderId, fragmentShaderId });
}

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath, const std::string& geometryPath) : Shader(vertexShaderPath, fragmentShaderPath) {
	unsigned int geometryShaderId = setupShader(GL_GEOMETRY_SHADER, geometryPath);

	bind({ geometryShaderId });
}

unsigned int Shader::setupShader(unsigned int shaderType, const std::string& shaderPath) {
	std::string shaderCode;

	try {
		shaderCode = loadSource(shaderPath);
	}
	// TODO: Define proper exceptions and print them.
	catch (std::exception&) {
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	return compileSource(shaderType, shaderCode);
}

std::string Shader::loadSource(const std::string& shaderPath) {
	std::string shaderCode;
	std::ifstream shaderFile;

	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		shaderFile.open(shaderPath);

		std::stringstream shaderStream;

		shaderStream << shaderFile.rdbuf();

		shaderFile.close();

		shaderCode = shaderStream.str();

		return shaderCode;
	}
	catch (std::ifstream::failure e) {
		std::throw_with_nested(std::runtime_error("Invalid shader source"));
	}
}

unsigned int Shader::compileSource(unsigned int shaderType, std::string shaderSource) {
	const GLchar* shaderCode = shaderSource.c_str();
	unsigned int shader;

	shader = glCreateShader(shaderType);
	glShaderSource(shader, 1, &shaderCode, NULL);

	glCompileShader(shader);

	checkCompileErrors(shader, getLogTypeString(shaderType));

	return shader;
}

unsigned int Shader::bind(std::initializer_list<unsigned int> shaderIds) {
	if (ID == -1) {
		ID = glCreateProgram();
	}

	for (auto const& shaderId : shaderIds) {
		glAttachShader(ID, shaderId);
	}

	glLinkProgram(ID);

	checkCompileErrors(ID, getLogTypeString(GL_CURRENT_PROGRAM));

	for (auto const& shaderId : shaderIds) {
		glDeleteShader(shaderId);
	}

	return 0;
}

std::string Shader::getLogTypeString(unsigned int shaderType) {
	switch (shaderType) {
	case GL_CURRENT_PROGRAM:
		return "PROGRAM";
	case GL_VERTEX_SHADER:
		return "VERTEX";
	case GL_FRAGMENT_SHADER:
		return "FRAGMENT";
	case GL_GEOMETRY_SHADER:
		return "GEOMETRY";
	}
}

void Shader::use() {
	glUseProgram(ID);
}

void Shader::checkCompileErrors(GLuint shader, std::string type) {
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM") {
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << std::endl << infoLog << std::endl << " -- --------------------------------------------------- -- " << std::endl;
		}
	}
	else {
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << std::endl << infoLog << std::endl << " -- --------------------------------------------------- -- " << std::endl;
		}
	}
}

void Shader::setBool(const std::string& name, bool value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<int>(value));
}

void Shader::setInt(const std::string& name, int value) const {
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const {
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVec2(const std::string& name, const glm::vec2& value) const {
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::setVec2(const std::string& name, float x, float y) const {
	glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}

void Shader::setVec3(const std::string& name, const glm::vec3& value) const {
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::setVec3(const std::string& name, float x, float y, float z) const {
	glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void Shader::setVec4(const std::string& name, const glm::vec4& value) const {
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w) {
	glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void Shader::setMat2(const std::string& name, const glm::mat2& mat) const {
	glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat3(const std::string& name, const glm::mat3& mat) const {
	glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void Shader::setMat4(const std::string& name, const glm::mat4& mat) const {
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
