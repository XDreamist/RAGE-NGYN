#ifndef RAGE_H
#define RAGE_H

extern "C" 
{
	__declspec(dllexport) void printHello();
	__declspec(dllexport) void InitOpenGL();
	__declspec(dllexport) void RenderCube();
	__declspec(dllexport) void Cleanup();
}

#endif