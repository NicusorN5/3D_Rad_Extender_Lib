#pragma once
#define DLLEXPORT __declspec(dllexport)
extern "C"
{
	void DLLEXPORT MyFunction(float *args);
}