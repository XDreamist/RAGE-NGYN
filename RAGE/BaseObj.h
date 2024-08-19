#pragma once

#include <GL/glew.h>

#include "Core/Object.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class BaseObj : RObject
{
public:
	~BaseObj();

	void Yaaa();
	void Loop();

	GLuint VAO, VBO, EBO, shaderProgram;
	glm::mat4 model;

	static GLuint CompileShader(GLenum type, const char* filePath);
	static GLuint CreateShaderProgram(const char* vertexSource, const char* fragmentSource);
};

