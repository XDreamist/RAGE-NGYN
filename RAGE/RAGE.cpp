#include "pch.h"

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GLFW/glfw3.h>

#include <iostream>
using namespace std;

extern "C" __declspec(dllexport) void printHello() {
    cout << "Hello, World!" << endl;
}

// Global variables
static GLFWwindow* window;
static GLfloat angle = 0.0f;

// Initialize OpenGL and create window
extern "C" __declspec(dllexport) void InitOpenGL()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(800, 600, "OpenGL Cube", NULL, NULL);
    if (!window)
    {
        fprintf(stderr, "Failed to create GLFW window\n");
        glfwTerminate();
        return;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW or GLAD here if needed for OpenGL function loading

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Set clear color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Function to render the cube
extern "C" __declspec(dllexport) void RenderCube()
{
    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Clear the framebuffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Render the cube
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -5.0f);
        glRotatef(angle, 1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        // Front face
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        // Back face
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        // Top face
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        // Bottom face
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        // Right face
        glColor3f(1.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, -1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        // Left face
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, -1.0f);
        glEnd();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();

        angle += 0.5f; // Increment rotation angle
    }
}

// Cleanup function
extern "C" __declspec(dllexport) void Cleanup()
{
    // Close GLFW window and terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
}