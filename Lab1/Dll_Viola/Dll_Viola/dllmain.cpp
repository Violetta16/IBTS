// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <string>
#include "Dll_Viola.h"

__declspec(dllexport)
int __stdcall MyGroup()
{
	int a = 571227;
	return a;
}


__declspec(dllexport)
std::string MyName()
{
	std::string b = "Violetta_Tokareva";
	return b;
}
