#include "pch.h"

#include "Renderer/GLRenderer.h"

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
    renderer.Render();
}

extern "C" __declspec(dllexport) void Cleanup()
{
    //renderer.CleanUp();
}
