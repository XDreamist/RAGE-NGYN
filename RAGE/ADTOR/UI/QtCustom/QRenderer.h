#pragma once

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtOpenGL/QOpenGLFunctions_4_5_Core>
#include <QtOpenGL/QOpenGLShaderProgram>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <QtCore/QTimer>

class QRenderer : public QOpenGLWidget, protected QOpenGLFunctions_4_5_Core {
    Q_OBJECT

public:
    QRenderer(QWidget* parent = nullptr)
        : QOpenGLWidget(parent), angle(0.0f), vao(0), vbo(0), ebo(0), shaderProgram(nullptr) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &QRenderer::updateRotation);
        timer->start(16); // Approximately 60 FPS
    }

    ~QRenderer() override {
        makeCurrent();
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
        glDeleteVertexArrays(1, &vao);
        delete shaderProgram;
        doneCurrent();
    }

protected:
    void initializeGL() override {
        initializeOpenGLFunctions();

        // Enable depth testing
        glEnable(GL_DEPTH_TEST);

        // Compile and link shaders
        shaderProgram = new QOpenGLShaderProgram(this);
        if (!shaderProgram->addShaderFromSourceFile(QOpenGLShader::Vertex, "shaders/vertex_shader.glsl") ||
            !shaderProgram->addShaderFromSourceFile(QOpenGLShader::Fragment, "shaders/fragment_shader.glsl") ||
            !shaderProgram->link()) {
            qDebug() << "Shader Program Error:" << shaderProgram->log();
            return;
        }

        // Define cube vertices and indices
        float vertices[] =
        {
            // Positions          // Normals
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,// Front face
             0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
             0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,// Back face
             0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
             0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,// Left face
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
             0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,// Right face
             0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
             -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,// Top face
              0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
              0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
             -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
             -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,// Bottom face
              0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
              0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
             -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f
        };

        unsigned int indices[] =
        {
            0, 1, 2, 2, 3, 0,   // Front face
            4, 5, 6, 6, 7, 4,   // Back face
            8, 9, 10, 10, 11, 8,  // Left face
            12, 13, 14, 14, 15, 12, // Right face
            16, 17, 18, 18, 19, 16, // Top face
            20, 21, 22, 22, 23, 20  // Bottom face
        };

        // Generate and bind VAO, VBO, and EBO
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &ebo);

        glBindVertexArray(vao);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);
    }

    void resizeGL(int w, int h) override {
        glViewport(0, 0, w, h);
    }

    void paintGL() override {
        glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram->bind();

        // Set transformation matrices
        glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(1.0f, 1.0f, 0.0f));
        glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), float(width()) / float(height()), 0.1f, 100.0f);

        // Set light and object color
        glm::vec3 lightPos(1.0f, 1.0f, 1.0f);
        glm::vec3 viewPos(0.0f, 0.0f, 3.0f);
        glm::vec3 lightColor(1.0f, 1.0f, 1.0f); // White light
        glm::vec3 objectColor(1.0f, 0.5f, 0.31f); // Example object color

        // Pass uniforms to shader
        shaderProgram->setUniformValue("model", QMatrix4x4(glm::value_ptr(model)).transposed());
        shaderProgram->setUniformValue("view", QMatrix4x4(glm::value_ptr(view)).transposed());
        shaderProgram->setUniformValue("projection", QMatrix4x4(glm::value_ptr(projection)).transposed());
        shaderProgram->setUniformValue("lightPos", QVector3D(lightPos.x, lightPos.y, lightPos.z));
        shaderProgram->setUniformValue("viewPos", QVector3D(viewPos.x, viewPos.y, viewPos.z));
        shaderProgram->setUniformValue("lightColor", QVector3D(lightColor.x, lightColor.y, lightColor.z));
        shaderProgram->setUniformValue("objectColor", QVector3D(objectColor.x, objectColor.y, objectColor.z));

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        shaderProgram->release();
    }

private slots:
    void updateRotation() {
        angle += 0.5f; // Rotate 0.5 degrees per frame
        if (angle > 360.0f) angle -= 360.0f;
        update();
    }

private:
    QTimer* timer;
    float angle;

    GLuint vao, vbo, ebo;
    QOpenGLShaderProgram* shaderProgram;
};