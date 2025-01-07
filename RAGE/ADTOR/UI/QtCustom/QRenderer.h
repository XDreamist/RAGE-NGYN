#pragma once

#include <QtOpenGLWidgets/QOpenGLWidget>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QSurfaceFormat>
#include <QtCore/QTimer>
#include <QtCore/QDebug>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class QRenderer : public QOpenGLWidget {
    Q_OBJECT

public:
    QRenderer(QWidget* parent = nullptr) : QOpenGLWidget(parent), angle(0.0f) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &QRenderer::updateRotation);
        timer->start(16);  // Approximately 60 FPS
    }

    ~QRenderer() override = default;

private:
    QTimer* timer;
    float angle;

protected:
    void initializeGL() override {
        glEnable(GL_DEPTH_TEST);  // Enable depth testing
        glEnable(GL_CULL_FACE);  // Enable back-face culling
        glCullFace(GL_BACK);     // Cull back faces
    }

    void resizeGL(int w, int h) override {
        glViewport(0, 0, w, h);

        // Set up the projection matrix using GLM
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), float(w) / float(h), 0.1f, 100.0f);

        // Load the projection matrix into OpenGL
        glMatrixMode(GL_PROJECTION);
        glLoadMatrixf(glm::value_ptr(projection));

        glMatrixMode(GL_MODELVIEW);
    }

    void paintGL() override {
        glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Define cube vertices
        float vertices[] = {
            // Front face
            -0.5f, -0.5f,  0.5f,
             0.5f, -0.5f,  0.5f,
             0.5f,  0.5f,  0.5f,
            -0.5f,  0.5f,  0.5f,
            // Back face
            -0.5f, -0.5f, -0.5f,
            -0.5f,  0.5f, -0.5f,
             0.5f,  0.5f, -0.5f,
             0.5f, -0.5f, -0.5f,
        };

        GLubyte indices[] = {
            0, 1, 2, 2, 3, 0,  // Front
            4, 5, 6, 6, 7, 4,  // Back
            0, 3, 5, 5, 4, 0,  // Left
            1, 7, 6, 6, 2, 1,  // Right
            3, 2, 6, 6, 5, 3,  // Top
            0, 4, 7, 7, 1, 0   // Bottom
        };

        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, -3.0f);

        // Apply rotation using GLM
        glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        glMultMatrixf(glm::value_ptr(model));

        // Draw the cube
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
        glDisableClientState(GL_VERTEX_ARRAY);
    }

private slots:
    void updateRotation() {
        angle += 1.0f;  // Rotate 1 degree per frame
        if (angle > 360.0f) angle -= 360.0f;
        update();  // Trigger a repaint
    }
};
