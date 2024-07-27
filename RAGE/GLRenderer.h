#pragma once


class GLRenderer
{
public:
	GLRenderer();
	~GLRenderer();

	void ChangeRenderView(const char* view);

	void RenderCube();

	void CleanUp();

private:
	struct GLFWwindow* window = nullptr;

	float angle = 0.0f;
};