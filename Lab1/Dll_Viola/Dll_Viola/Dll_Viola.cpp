// Dll_Viola.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "framework.h"
#include "Dll_Viola.h"


// Пример экспортированной переменной
DLLVIOLA_API int nDllViola=0;

// Пример экспортированной функции.
DLLVIOLA_API int fnDllViola(void)
{
    return 0;
}

// Конструктор для экспортированного класса.
CDllViola::CDllViola()
{
    return;
}
