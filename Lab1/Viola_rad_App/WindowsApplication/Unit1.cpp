//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HINSTANCE ViolaDll=LoadLibraryW(L"Dll_rad_Viola.dll");
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	PMyGroup MyGroup;
	MyGroup=(PMyGroup)GetProcAddress(ViolaDll,"MyGroup");
	Label1->Caption=MyGroup();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	PMyName MyName;
	MyName=(PMyName)GetProcAddress(ViolaDll,"MyName");
	char *name=MyName(name);
	Label1->Caption=name;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    FreeLibrary(ViolaDll);
}
//---------------------------------------------------------------------------
