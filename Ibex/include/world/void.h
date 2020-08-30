#pragma once

#ifndef VOID_H
#define VOID_H

#include <string>
#include <utility>

#include "shader.h"
#include "world.h"
#include "camera.h"

class Void : public World {
    unsigned int VAO, VBO;

    float vertices[36] = {
        -0.5f, -0.5f, -0.5f,		0.0f,  0.0f,  0.5f,
         0.5f, -0.5f, -0.5f,		0.2f,  0.3f,  1.0f,
         0.5f,  0.5f, -0.5f,		0.3f,  0.6f,  0.5f,
         0.5f,  0.5f, -0.5f,		0.4f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,		0.6f,  0.0f,  0.5f,
        -0.5f, -0.5f, -0.5f,		0.7f,  0.3f,  1.0f,
    };

    glm::vec3 cubePos[1] = {
        glm::vec3(0.0f,  0.0f,  0.0f)
    };

public:
	Void();
	Void(WorldConfig, CameraConfig, ShaderConfig, WindowConfig);
	int load();
	int onTick();
	int cleanup();
};

#endif
