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
	ShowMessageBoxFlags(args, MB_OK + MB_ICONINFORMATION);
}

void DLLEXPORT HideMouseCursor(float* atgs)
{
	ShowCursor(false);
}

void DLLEXPORT ShowMouseCursor(float* atgs)
{
	ShowCursor(true);
}

void ShowMessageBoxFlags(float *args, int flag)
{
	char *message = new char[255];
	char *title = new char[255];
	int i;
	for (i = 0; i < 255; i++)
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
	MessageBoxA(nullptr, message, title, flag);
	delete[] message;
	delete[] title;
}
void DLLEXPORT ShowMsgBoxOK(float *args)
{
	ShowMessageBoxFlags(args, MB_OK);
}
void DLLEXPORT ShowMsgBoxOKInform(float *args)
{
	ShowMessageBoxFlags(args, MB_OK+MB_ICONINFORMATION);
}
void DLLEXPORT ShowMsgBoxOKWarn(float *args)
{
	ShowMessageBoxFlags(args, MB_OK + MB_ICONWARNING);
}
void DLLEXPORT ShowMsgBoxYesNo(float *args)
{
	ShowMessageBoxFlags(args, MB_YESNO);
}
void DLLEXPORT ShowMsgBoxYesNoCancel(float *args)
{
	ShowMessageBoxFlags(args, MB_YESNOCANCEL);
}
void DLLEXPORT ShowMsgBoxRetryCancel(float *args)
{
	ShowMessageBoxFlags(args, MB_RETRYCANCEL);
}
void DLLEXPORT ShowMessageBox(float *args)
{
	int flag = (int)args[0];
	ShowMessageBoxFlags(args + 1, flag);
}

char * ParseStringFromFloatArray(float * args)
{
	char *str = new char[16383]; //Oh yes, that's how many arguments the args[] can have, as documented in 3D Rad's documentation.
	int s;
	for (int i = 0; ; i++)
	{
		str[i] = (uint8_t)args[i];
		if (args[i] == 0)
		{
			s = i;
			break;
		}
	}
	char * ret = new char[s+1];
	for (int i = 0; i <= s; i++)
	{
		ret[i] = str[i];
	}
	delete[] str;
	return ret; //This is prone to memory leaks if not used correctly.
	//Store the result in a separate string and then delete it.
}

void DLLEXPORT ExecuteBatch(float * args)
{
	char *argument = ParseStringFromFloatArray(args);
	std::system(argument);
	delete[] argument;
}
