#include "pch.h"

#include "GLRenderer.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>


const char* vertexShaderSource = R"(
#version 330 core
layout (location = 0) in vec3 aPos;
uniform mat4 model;
void main() {
    gl_Position = model * vec4(aPos, 1.0);
}
)";

const char* fragmentShaderSource = R"(
#version 330 core
out vec4 FragColor;
void main() {
    FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Red color
}
)";

// Initialize OpenGL and create window
//extern "C" __declspec(dllexport) void InitOpenGL()
//{
//    std::cout << "Hello, OpenGL!" << std::endl;
//
//    GLRenderer renderer;
//    renderer.RenderCube();
//    renderer.CleanUp();
//}

// Shader loading utility functions
static GLuint CompileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    // Check for compile errors
    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLint length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        std::string infoLog(length, ' ');
        glGetShaderInfoLog(shader, length, &length, &infoLog[0]);
        std::cerr << "Shader compilation failed: " << infoLog << std::endl;
    }
    return shader;
}

static GLuint CreateShaderProgram(const char* vertexSource, const char* fragmentSource) {
    GLuint vertexShader = CompileShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fragmentShader = CompileShader(GL_FRAGMENT_SHADER, fragmentSource);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    // Check for linking errors
    GLint success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success) {
        GLint length;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
        std::string infoLog(length, ' ');
        glGetProgramInfoLog(program, length, &length, &infoLog[0]);
        std::cerr << "Program linking failed: " << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

static void MultiplyMatrix(float* result, const float* m1, const float* m2) {
    float temp[16]{};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i * 4 + j] = 0.0f;
            for (int k = 0; k < 4; ++k) {
                temp[i * 4 + j] += m1[i * 4 + k] * m2[k * 4 + j];
            }
        }
    }
    std::copy(std::begin(temp), std::end(temp), result);
}

// Create a rotation matrix
static void CreateRotationMatrix(float* matrix, float angle, float x, float y, float z) {
    float radians = angle * 3.14159f / 180.0f;
    float c = cosf(radians);
    float s = sinf(radians);
    float t = 1.0f - c;

    matrix[0] = t * x * x + c;
    matrix[1] = t * x * y - s * z;
    matrix[2] = t * x * z + s * y;
    matrix[3] = 0.0f;

    matrix[4] = t * x * y + s * z;
    matrix[5] = t * y * y + c;
    matrix[6] = t * y * z - s * x;
    matrix[7] = 0.0f;

    matrix[8] = t * x * z - s * y;
    matrix[9] = t * y * z + s * x;
    matrix[10] = t * z * z + c;
    matrix[11] = 0.0f;

    matrix[12] = 0.0f;
    matrix[13] = 0.0f;
    matrix[14] = 0.0f;
    matrix[15] = 1.0f;
}

extern "C" __declspec(dllexport) void InitOpenGL()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    // Set GLFW error callback
    //glfwSetErrorCallback(glfwErrorCallback);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(1200, 600, "OpenGL Rendering", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return;
    }

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    glViewport(0, 0, 800, 600);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Define vertices for a cube
    float vertices[] = {
        // Positions          
        -0.5f, -0.5f, -0.5f,  // Front-bottom-left
         0.5f, -0.5f, -0.5f,  // Front-bottom-right
         0.5f,  0.5f, -0.5f,  // Front-top-right
        -0.5f,  0.5f, -0.5f,  // Front-top-left
        -0.5f, -0.5f,  0.5f,  // Back-bottom-left
         0.5f, -0.5f,  0.5f,  // Back-bottom-right
         0.5f,  0.5f,  0.5f,  // Back-top-right
        -0.5f,  0.5f,  0.5f   // Back-top-left
    };

    unsigned int indices[] = {
        0, 1, 3, 1, 2, 3,  // Front face
        4, 5, 7, 5, 6, 7,  // Back face
        0, 1, 4, 1, 5, 4,  // Bottom face
        2, 3, 6, 3, 7, 6,  // Top face
        0, 3, 4, 3, 7, 4,  // Left face
        1, 2, 5, 2, 6, 5   // Right face
    };

    // Create VAO, VBO, and EBO
    GLuint VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Compile shaders
    GLuint shaderProgram = CreateShaderProgram(vertexShaderSource, fragmentShaderSource);

    // Set up transformation
    float model[16] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    float rotationMatrix[16];
    float angle = 0.0f;

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Update rotation
        angle = 0.01f; // Increment angle
        CreateRotationMatrix(rotationMatrix, angle, 0.5f, 1.0f, 0.0f);
        MultiplyMatrix(model, rotationMatrix, model);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(shaderProgram);

        // Set model matrix
        GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model);

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0); // Draw the cube

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();
}

static void glfwErrorCallback(int error, const char* description) 
{
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}