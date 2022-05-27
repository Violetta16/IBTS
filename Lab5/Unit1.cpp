//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "FileCtrl.hpp"

#include "Unit1.h"
#include "FSFactory.h"
#include <sqlite3.h>
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
AbstractFS FileSystem;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	VirtualStringTree1->NodeDataSize=sizeof(DBStruct);
	myThread=NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	UnicodeString Dir = "C:\\";
	if (SelectDirectory("Выбор диска:","",Dir))
		Label1->Caption = Dir;

	Dir[Dir.Length()]='\0';
	UnicodeString str="\\\\.\\"+Dir;
	wchar_t *fileName=str.t_str();
	FSFactory factory;
	FileSystem=factory.FactoryFS(fileName);

	Label2->Caption=FileSystem.Name;
	Label2->Caption+=L"\n";

	Label2->Caption+=L"Размер ФС: ";
	Label2->Caption+=FileSystem.SizeFS/1024/1024;
	Label2->Caption+=L" Мбайт\n";

	Label2->Caption+=L"Количество кластеров ФС: ";
	Label2->Caption+=FileSystem.CountClusterFS;
	Label2->Caption+=L"\n";

	Label2->Caption+=L"Размер кластера ФС: ";
	Label2->Caption+=FileSystem.ClusterSizeFS;
	Label2->Caption+=L" байт\n";
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
    Button4Click(Sender);
	myThread=new MyThread(FileSystem, false);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
		  TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
if(Node==NULL) return;
 DBStruct *nodeData=(DBStruct*)VirtualStringTree1->GetNodeData(Node);

 switch (Column) {
	case 0:{
	CellText=nodeData->Name;
	break;
	}
	case 1:{
	CellText=nodeData->Num;
	break;
	}
}
}
//---------------------------------------------------------------------------

void TForm1::UpdateTable()
{
VirtualStringTree1->Clear();
  VirtualStringTree1->BeginUpdate();

  sqlite3* Database;
  sqlite3_stmt *pStatement;
  char* filename="DBSign.db";

  if(sqlite3_open(
  filename,
  &Database
  )){
	 ShowMessage("Не удалось открыть БД");
	 sqlite3_close(Database);
  }

  char* errmsg;
  const char *str="Select * from SIGN ;";

  int result=sqlite3_prepare_v2(Database,str,-1,&pStatement,NULL);

  if(result!=SQLITE_OK){
  errmsg=(char*)sqlite3_errmsg(Database);
  }

  while(true){
  result=sqlite3_step(pStatement);
  if(result!=SQLITE_ROW) break;

  PVirtualNode entryNode=VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
  DBStruct *nodeData=(DBStruct*)VirtualStringTree1->GetNodeData(entryNode);

  int column=sqlite3_data_count(pStatement);
  for (int i = 0; i < column; i++)
	  {
		  UnicodeString otwet=(const char*)sqlite3_column_text(pStatement,i);
		  switch(i){
			  case 0:{
			  nodeData->Name=otwet;
			  break;
			  }
			  case 1:{
			  nodeData->Num =otwet.ToInt();
			  break;
			  }
		  }
	  }


  }
   sqlite3_finalize(pStatement);
   sqlite3_close(Database);
   VirtualStringTree1->EndUpdate();
}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  PVirtualNode choiseStr=VirtualStringTree1->GetFirstSelected();
  if(choiseStr==NULL) return;

  sqlite3* Database;
  char* filename="DBSign.db";

  DBStruct *nodeData=(DBStruct*)VirtualStringTree1->GetNodeData(choiseStr);
  AnsiString str="Delete from SIGN where NUM = "+(AnsiString)nodeData->Num+" ;";
  sqlite3_stmt *pStatement;
  char* errmsg;

  if(sqlite3_open(
  filename,
  &Database
  )){
	 ShowMessage("Не удалось открыть БД");
	 sqlite3_close(Database);
  }

  int result=sqlite3_prepare_v2(Database,str.c_str(),-1,&pStatement,NULL);
	if(result!=SQLITE_OK){
  errmsg=(char*)sqlite3_errmsg(Database);
  sqlite3_close(Database);
  return;
  }

  result=sqlite3_step(pStatement);
  if(result!=SQLITE_DONE){
  ShowMessage("Ошибка запроса");
	 sqlite3_finalize(pStatement);
	sqlite3_close(Database);
	return;
  }
  sqlite3_finalize(pStatement);
  sqlite3_close(Database);
  UpdateTable();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	sqlite3* Database;
  char* filename="DBSign.db";
  AnsiString str="Delete from SIGN;";

  sqlite3_stmt *pStatement;
  char* errmsg;

  if(sqlite3_open(
  filename,
  &Database
  )){
	 ShowMessage("Не удалось открыть БД");
	 sqlite3_close(Database);
  }

  int result=sqlite3_prepare_v2(Database,str.c_str(),-1,&pStatement,NULL);
	if(result!=SQLITE_OK){
  errmsg=(char*)sqlite3_errmsg(Database);
  sqlite3_close(Database);
  return;
  }

  result=sqlite3_step(pStatement);
  if(result!=SQLITE_DONE){
  ShowMessage("Ошибка запроса");
	 sqlite3_finalize(pStatement);
	sqlite3_close(Database);
	return;
  }
  sqlite3_finalize(pStatement);
  sqlite3_close(Database);
  VirtualStringTree1->Clear();
}
//---------------------------------------------------------------------------

