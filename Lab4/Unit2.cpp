//---------------------------------------------------------------------------

#include <System.hpp>
#include <string>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MyTread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall MyTread::MyTread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
   dataBuffer = new byte[512];
   j=0;
   MyEvent=new TEvent(NULL,true,false,"",false);
   Tread2=new MyTread2(MyEvent,dataBuffer,true);
}
//---------------------------------------------------------------------------
void __fastcall MyTread::Execute()
{
   wchar_t *fileName =L"\\\\.\\C:";

   HANDLE fileHander=CreateFileW(fileName,
   GENERIC_READ,
   FILE_SHARE_READ | FILE_SHARE_WRITE,
   NULL,
   OPEN_EXISTING,
   FILE_ATTRIBUTE_NORMAL,
   NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
	ErrorLog(0);
	CloseHandle(fileHander);
	delete[] dataBuffer;
	Sleep(INFINITY);
	}

  j=0;
  Tread2->Start();
  while(!Terminated)
  {
  LARGE_INTEGER sectorOffset;
  sectorOffset.QuadPart=j*512;

  unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart,FILE_BEGIN);
	  if(currentPosition !=sectorOffset.LowPart){
		ErrorLog(1);
		CloseHandle(fileHander);
		delete[] dataBuffer;
		Sleep(INFINITY);
	  }
	 while (MyEvent->WaitFor(0)==wrSignaled)
		 {
			 Sleep(0);
		 }
  DWORD bytesToRead=512;
  DWORD bytesRead;
  bool readResult=ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);
	  if(readResult==false||bytesRead!=bytesToRead){
		  ErrorLog(2);
		  CloseHandle(fileHander);
		  delete[] dataBuffer;
		  Sleep(INFINITY);
	  }
  MyEvent->SetEvent();
  Synchronize(&UpdateCaption);
  Sleep(10);
  j++;
  }

  Tread2->Terminate();
  delete Tread2;

  CloseHandle(fileHander);
  delete[] dataBuffer;
}
//---------------------------------------------------------------------------
void __fastcall MyTread::UpdateCaption()
	  {
		Form1->Label1->Caption="";
		UnicodeString str;
		 for (int i = 1; i < 512; i++) {
		 str+=reinterpret_cast<char*>(dataBuffer)[i];
		 if(i%64==0)
		  str+="\n";
		  Form1->Label1->Caption+=str;
          str="";
		 }
		Form1->Label2->Caption=L"Страниц обработано: ";
        Form1->Label2->Caption+=j+1;
	  }
//---------------------------------------------------------------------------
void __fastcall MyTread::ErrorLog(int i)
	  {
		switch (i) {
			case 0:
			Form1->Label1->Caption="Error reading disk C:.";
			break;
			case 1:
			Form1->Label1->Caption=L"Error2.";
			break;
			case 2:
			Form1->Label1->Caption=L"Error3.";
			break;
		}
	  }
