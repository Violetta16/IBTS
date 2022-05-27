//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "IterDecorator.h"
#include <sqlite3.h>
#include "SigSearch.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------
__fastcall MyThread::MyThread(AbstractFS fileSystem,bool CreateSuspended)
	: TThread(CreateSuspended)
{
	FileSystem=fileSystem;
    load=0;
}
//---------------------------------------------------------------------------
void __fastcall MyThread::Execute()
{
    FSIterator iter=FSIterator(FileSystem);
	byte *dataBuffer = new byte[FileSystem.ClusterSizeFS];
	if(Form1->RadioGroup1->ItemIndex==1)
		iter=IterDecorator(iter);
	SigSearch search=SigSearch();

	sqlite3* Database;
	char* filename="DBSign.db";

	if(sqlite3_open(
	filename,
	&Database
	)){
	 ShowMessage("Не удалось открыть БД");
	 sqlite3_close(Database);
	}

	for(iter.First();!iter.IsDone();iter.Next()){
		iter.Reed(dataBuffer);
		AnsiString type=search.Search(dataBuffer);
        if(iter.Position%30000==0)
		{
		load=float(iter.Position)/FileSystem.CountClusterFS;
		Synchronize(&UpdateLoading);
		}
		if(type!="")
		{
			AnsiString str="INSERT INTO SIGN (NAME, NUM) VALUES ( \""+type+"\" , "+(AnsiString)iter.Position+");";
			sqlite3_exec(Database,str.c_str(),NULL,0,NULL);

		}

	}
	sqlite3_close(Database);

}
//---------------------------------------------------------------------------
void __fastcall MyThread::UpdateLoading()
{
Form1->UpdateTable();
Form1->Label3->Caption=float(int(100*load))/100;
Form1->Label3->Caption+="%";
}