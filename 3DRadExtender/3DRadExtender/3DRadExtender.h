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
	void DLLEXPORT ShowMsgBoxOK(float *args);
	void DLLEXPORT ShowMsgBoxOKInform(float *args);
	void DLLEXPORT ShowMsgBoxOKWarn(float *args);
	void DLLEXPORT ShowMsgBoxYesNo(float *args);
	void DLLEXPORT ShowMsgBoxYesNoCancel(float *args);
	void DLLEXPORT ShowMsgBoxRetryCancel(float *args);
	void DLLEXPORT ShowMessageBox(float *args);
}
void ShowMessageBoxFlags(float *args, int flag);