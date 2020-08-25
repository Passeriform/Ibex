#include "shader.h"
#include "void.h"
#include "camera.h"

Void::Void() : World() {
    camera.instance = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
};
Void::Void(WorldConfig world, CameraConfig camera, ShaderConfig shader, WindowConfig window) :
    World(world, camera, shader, window) {
    camera.instance = Camera(camera.origin);
};

int Void::load() {
    shader.worldShader = Shader("shaders/Void/VoidVertex.vs", "shaders/Void/VoidFragment.fs");

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    return 0;
}

int Void::onTick() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPointSize(10);
    glLineWidth(2.5);

    shader.worldShader.use();

    glm::mat4 projection = glm::perspective(glm::radians(camera.instance.Zoom), (float)window.dim.first / (float)window.dim.second, 0.1f, 100.0f);
    shader.worldShader.setMat4("projection", projection);

    glm::mat4 view = camera.instance.GetViewMatrix();
    shader.worldShader.setMat4("view", view);

    glBindVertexArray(VAO);
    for (unsigned int i = 0; i < 1; i++)
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, cubePos[i]);
        float angle = 0.0f;
        model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
        shader.worldShader.setMat4("model", model);

        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

    return 0;
}

int Void::cleanup() {
	glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    
    return 0;
}