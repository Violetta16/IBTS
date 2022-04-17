//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}

	HINSTANCE ViolaDll=LoadLibraryW(L"Dll_rad_Viola.dll");
	if(ViolaDll==NULL) return 0;
	PMyGroup MyGroup;
	PMyName MyName;
	MyGroup=(PMyGroup) GetProcAddress(ViolaDll,"MyGroup");
	MyName=(PMyName) GetProcAddress(ViolaDll,"MyName");
	if(MyGroup==NULL || MyName==NULL){
	FreeLibrary(ViolaDll);
	return 0;
	}

	return 0;
}
//---------------------------------------------------------------------------
