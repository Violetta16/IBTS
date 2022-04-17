// Приведенный ниже блок ifdef — это стандартный метод создания макросов, упрощающий процедуру
// экспорта из библиотек DLL. Все файлы данной DLL скомпилированы с использованием символа DLLVIOLA_EXPORTS
// Символ, определенный в командной строке. Этот символ не должен быть определен в каком-либо проекте,
// использующем данную DLL. Благодаря этому любой другой проект, исходные файлы которого включают данный файл, видит
// функции DLLVIOLA_API как импортированные из DLL, тогда как данная DLL видит символы,
// определяемые данным макросом, как экспортированные.
#ifdef DLLVIOLA_EXPORTS
#define DLLVIOLA_API __declspec(dllexport)
#else
#define DLLVIOLA_API __declspec(dllimport)
#endif

// Этот класс экспортирован из библиотеки DLL
class DLLVIOLA_API CDllViola {
public:
	CDllViola(void);
	// TODO: добавьте сюда свои методы.
};

extern DLLVIOLA_API int nDllViola;

DLLVIOLA_API int fnDllViola(void);
