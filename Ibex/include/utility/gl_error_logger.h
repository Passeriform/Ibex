#pragma once

#ifndef GL_ERROR_LOGGER_H
#define GL_ERROR_LOGGER_H

#include <iostream>
#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

inline GLenum glCheckError_(const std::string file, int line)
{
	GLenum errorCode;
	while ((errorCode = glGetError()) != GL_NO_ERROR)
	{
		std::string error;
		switch (errorCode) {
		case GL_INVALID_ENUM:
			error = "INVALID_ENUM";
			break;
		case GL_INVALID_VALUE:
			error = "INVALID_VALUE";
			break;
		case GL_INVALID_OPERATION:
			error = "INVALID_OPERATION";
			break;
		case GL_OUT_OF_MEMORY:
			error = "OUT_OF_MEMORY";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			error = "INVALID_FRAMEBUFFER_OPERATION";
			break;
		}
		std::cout << error << " | " << file << " (" << line << ")" << std::endl;
	}
	return errorCode;
}

#define glCheckError() glCheckError_(__FILE__, __LINE__)
#endif
