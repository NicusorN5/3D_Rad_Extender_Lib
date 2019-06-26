// 3DRadExtender.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "3DRadExtender.h"

void DLLEXPORT MyFunction(float *args)
{
	args[2] = args[0] + args[1];
}
void DLLEXPORT MSGBOX(float *args)
{
	char *message = new char[255];
	char *title = new char[255];
	int i;
	for (i =0 ; i < 255; i++)
	{
		if ((int)args[i]) message[i] = (int)args[i];
		else
		{
			message[i] = 0;
			break;
		}
	}
	int j = 0;
	i += 1;
	for (; i < 512; i++, j++)
	{
		if ((int)args[i]) title[j] = (int)args[i];
		else
		{
			title[j] = 0;
			break;
		}
	}
	MessageBoxA(nullptr, message, title, MB_OK + MB_ICONINFORMATION);
	delete[] message;
	delete[] title;
}

void DLLEXPORT HideMouseCursor(float* atgs)
{
	ShowCursor(false);
}

void DLLEXPORT ShowMouseCursor(float* atgs)
{
	ShowCursor(true);
}