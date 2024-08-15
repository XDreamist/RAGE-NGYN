#pragma once

#include <iostream>
#include <GL/glew.h>

class GLRenderer
{
public:
	GLRenderer();
	~GLRenderer();

	void InitRenderer();

	void ChangeRenderView(const char* view);

	void RenderCube();

	static std::string LoadShaderSource(const char* filePath);

	static GLuint CompileShader(GLenum type, const char* filePath);

	static GLuint CreateShaderProgram(const char* vertexSource, const char* fragmentSource);

	static void MultiplyMatrix(float* result, const float* m1, const float* m2);

	static void CreateRotationMatrix(float* matrix, float angle, float x, float y, float z);

	void CleanUp();

private:
	struct GLFWwindow* window = nullptr;

	float angle = 0.0f;
};