#pragma once
#include <Windows.h>
#include <fstream>
#define DLLEXPORT __declspec(dllexport)
extern "C"
{
	void DLLEXPORT MyFunction(float *args);
	void DLLEXPORT MSGBOX(float *args);
	void DLLEXPORT HideMouseCursor(float *args);
	void DLLEXPORT ShowMouseCursor(float *args);
}