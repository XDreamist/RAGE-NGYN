#include <QtCore/QCoreApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtGui/QWindow>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLFunctions>
#include <QtGui/QSurfaceFormat>
#include <QtCore/QTimer>
#include <QtCore/QDebug>
#include <QtCore/QTranslator>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class QTriangleWindow : public QWindow, protected QOpenGLFunctions {
    QOpenGLContext* context;
    QTimer* timer;
    float angle;

public:
    QTriangleWindow() : angle(0.0f) {
        setSurfaceType(QWindow::OpenGLSurface);

        QSurfaceFormat format;
        format.setVersion(2, 1);
        format.setProfile(QSurfaceFormat::NoProfile);
        setFormat(format);

        context = new QOpenGLContext(this);
        context->setFormat(format);
        if (!context->create()) {
            qDebug() << "Failed to create OpenGL context!";
        }
    }

protected:
    void exposeEvent(QExposeEvent*) override {
        if (isExposed()) {
            context->makeCurrent(this);
            initializeOpenGLFunctions();

            // Timer to update the rotation angle
            timer = new QTimer(this);
            connect(timer, &QTimer::timeout, this, &QTriangleWindow::updateRotation);
            timer->start(16);  // Approximately 60 FPS
        }
    }

    void updateRotation() {
        angle += 0.5f;  // Adjust the speed of rotation here
        if (angle > 360.0f) {
            angle -= 360.0f;
        }
        render();
    }

    void render() {
        if (!context->makeCurrent(this)) {
            qDebug() << "Failed to make context current!";
            return;
        }

        glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

             // Left face
             -0.5f, -0.5f, -0.5f,
             -0.5f, -0.5f,  0.5f,
             -0.5f,  0.5f,  0.5f,
             -0.5f,  0.5f, -0.5f,

             // Right face
              0.5f, -0.5f, -0.5f,
              0.5f,  0.5f, -0.5f,
              0.5f,  0.5f,  0.5f,
              0.5f, -0.5f,  0.5f,

              // Top face
              -0.5f,  0.5f, -0.5f,
              -0.5f,  0.5f,  0.5f,
               0.5f,  0.5f,  0.5f,
               0.5f,  0.5f, -0.5f,

               // Bottom face
               -0.5f, -0.5f, -0.5f,
                0.5f, -0.5f, -0.5f,
                0.5f, -0.5f,  0.5f,
               -0.5f, -0.5f,  0.5f
        };

        GLubyte indices[] = {
            // Front face
            0, 1, 2,  2, 3, 0,
            // Back face
            4, 5, 6,  6, 7, 4,
            // Left face
            8, 9, 10, 10, 11, 8,
            // Right face
            12, 13, 14, 14, 15, 12,
            // Top face
            16, 17, 18, 18, 19, 16,
            // Bottom face
            20, 21, 22, 22, 23, 20
        };

        glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        glPushMatrix();
        glMultMatrixf(glm::value_ptr(model));

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, indices);
        glDisableClientState(GL_VERTEX_ARRAY);

        glPopMatrix();

        context->swapBuffers(this);
    }
};