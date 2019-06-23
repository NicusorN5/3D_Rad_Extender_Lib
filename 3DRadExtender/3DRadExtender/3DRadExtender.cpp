// 3DRadExtender.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "3DRadExtender.h"

void DLLEXPORT MyFunction(float *args)
{
	args[2] = args[0] + args[1];
}