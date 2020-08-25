#include <iostream>
#include <utility>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ibex.h"
#include "world/world.h"
#include "events/listeners.h"

using namespace Ibex;

Engine::Engine() :
    gridSize(64),
    scrWidth(64 * 64),
    scrHeight(64 * 64),
    dumped(false)
{ };

Engine& Engine::withGridSize(long gridDim) {
    gridSize = gridDim;
    return *this;
}

Engine& Engine::withScrDim(std::pair<unsigned long, unsigned long> scrDim) {
    scrWidth = scrDim.first;
    scrHeight = scrDim.second;
    return *this;
}

Engine& Engine::withScrWidth(unsigned long scrDim) {
    scrWidth = scrDim;
    return *this;
}

Engine& Engine::withScrHeight(unsigned long scrDim) {
    scrHeight = scrDim;
    return *this;
}

int Engine::init()
{
    if (!glfwInit()) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    window = glfwCreateWindow(scrWidth, scrHeight, "Ibex Engine", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Error:: Ibex failed to load up GLFW (Linking Error)" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    glfwSetWindowUserPointer(window, this);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD couldn't be loaded!!!" << std::endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    activeWorld->load();

    glfwSetFramebufferSizeCallback(window, &Event::framebuffer_size_callback);
    glfwSetErrorCallback(&Event::error_callback);
    glfwSetMouseButtonCallback(window, &Event::mouse_callback);
    glfwSetScrollCallback(window, &Event::scroll_callback);

    return 0;
}

int Engine::tick()
{
    // float currentFrame = glfwGetTime();
    // deltaTime = currentFrame - lastFrame;
    // lastFrame = currentFrame;

    Event::tick(window);
    
    activeWorld->onTick();

    glfwSwapBuffers(window);
    glfwPollEvents();

    return 0;
}

int Engine::dump()
{
    if (!dumped) {
        dumped = true;
    }

    activeWorld->cleanup();

    return 0;
}