#include "../pch.h"
#include "GLRenderer.h"

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "../BaseObj.h"

GLRenderer::GLRenderer() {}

GLRenderer::~GLRenderer() { CleanUp(); }

void GLRenderer::InitRenderer()
{
    InitGLFW();
    InitGLEW();

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void GLRenderer::InitGLFW()
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    window = glfwCreateWindow(800, 600, "Game Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
}

void GLRenderer::InitGLEW() {
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return;
    }
}

void GLRenderer::Render() {

    BaseObj testObj;
    testObj.Yaaa();

    // Example render loop
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render your scene here

        testObj.Loop();

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        {
            glfwSetWindowShouldClose(window, true);
        }
    }
}

void GLRenderer::ChangeRenderView(const char* view)
{
    // Placeholder method for changing render view, can be implemented as needed
}

void GLRenderer::CleanUp() 
{
    glfwDestroyWindow(window);
    glfwTerminate();
}