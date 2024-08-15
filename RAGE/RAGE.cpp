#include "pch.h"

#include "GLRenderer.h"

#include <iostream>
#include "RAGE.h"


GLRenderer renderer;

// Initialize OpenGL and create window
extern "C" __declspec(dllexport) void InitOpenGL()
{
    std::cout << "Hello, OpenGL!" << std::endl;

    renderer.InitRenderer();
}

extern "C" __declspec(dllexport) void RenderCube()
{
    renderer.RenderCube();
    renderer.CleanUp();
}

void Cleanup()
{
}
