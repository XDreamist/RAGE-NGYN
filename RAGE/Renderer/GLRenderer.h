#pragma once


class GLRenderer
{
public:

	GLRenderer();
	~GLRenderer();

	void InitRenderer();
	void InitGLFW();
	void InitGLEW();

	void Render();
	void ChangeRenderView(const char* view);

	void CleanUp();


private:
	struct GLFWwindow* window = nullptr;

	float angle = 0.0f;
};