#ifndef RAGE_H
#define RAGE_H

#pragma once

extern "C" 
{
	__declspec(dllexport) void InitOpenGL();
	__declspec(dllexport) void RenderCube();
	__declspec(dllexport) void Cleanup();
}

#endif