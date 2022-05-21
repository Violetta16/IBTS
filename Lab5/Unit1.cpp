//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "NTFS.cpp"
#include "FAT32.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AbstractFS FileSystem;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Label1->Caption=FileSystem.Name;
    Label1->Caption+=L"\n";

	Label1->Caption+=L"Размер ФС: ";
	Label1->Caption+=FileSystem.SizeFS/1024/1024;
	Label1->Caption+=L" Мбайт\n";

	Label1->Caption+=L"Количество кластеров ФС: ";
	Label1->Caption+=FileSystem.CountClusterFS;
	Label1->Caption+=L"\n";

	Label1->Caption+=L"Размер кластера ФС: ";
	Label1->Caption+=FileSystem.ClusterSizeFS;
	Label1->Caption+=L" байт\n";


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	wchar_t *fileName=L"\\\\.\\C:";
	FileSystem=NTFS(fileName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	wchar_t *fileName=L"\\\\.\\C:";
	Label1->Caption="";
	long NumCluster=0;
   byte *dataBuffer = new byte[FileSystem.ClusterSizeFS];
	if(Edit1->Text!=""){
	   long EditNum=StrToLong(Edit1->Text);
	   if(EditNum>0 && EditNum<=FileSystem.CountClusterFS)
		   NumCluster=StrToInt(Edit1->Text);
	   FileSystem.ReedCluster(fileName,NumCluster,dataBuffer);

		for(int i=0;i<FileSystem.ClusterSizeFS; i++){
			Label1->Caption+=dataBuffer[i];
			Label1->Caption+=" ";
			 if(i%31==0 && i!=0)
				Label1->Caption+="\n";
		}
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	wchar_t *fileName=L"\\\\.\\E:";
	FileSystem=FAT32(fileName);
}
//---------------------------------------------------------------------------

