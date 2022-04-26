//---------------------------------------------------------------------------

#include <System.hpp>
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
//      void __fastcall MyTread2::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall MyTread2::MyTread2(TEvent *myEvent,byte *dataBuffer,bool CreateSuspended)
	: TThread(CreateSuspended)
{
	MyEvent=myEvent;
	DataBuffer=dataBuffer;
    heshsum=0;
}
//---------------------------------------------------------------------------
void __fastcall MyTread2::Execute()
{
 //"Ïîäñ÷åò" õýøÑóììû
while(!Terminated){

		if(MyEvent->WaitFor(0)==wrSignaled)
		{
		int sum=heshsum;
			for (int i = 0; i < 512; i++)
			{
			 sum+=(int)DataBuffer[i];
			}
		heshsum=sum%(INT_MAX/2);
		MyEvent->ResetEvent();
        Synchronize(&UpdateCaption);
		}

	}



}
//---------------------------------------------------------------------------
void __fastcall MyTread2::UpdateCaption()
	  {
		Form1->Label3->Caption = "ÕåøÑóììà: ";
		Form1->Label3->Caption += heshsum;
	  }