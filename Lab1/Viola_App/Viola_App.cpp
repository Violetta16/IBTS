// Viola_App.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include"Dll_Viola.h"
#include "pch.h"
#include "framework.h"

#define DLLVIOLA_API __declspec(dllimport MyGroup);

int main()
{
	MyGroup();
	std::cout << "I have done this!\n";
}

