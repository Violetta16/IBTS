//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "sqlite3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	VirtualStringTree1->NodeDataSize =sizeof(DBStruct);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  VirtualStringTree1->Clear();
  VirtualStringTree1->BeginUpdate();

  sqlite3* Database;
  sqlite3_stmt *pStatement;
  char* filename="Databases.db";

  if(sqlite3_open(
  filename,
  &Database
  )){
	 ShowMessage("Не удалось открыть БД");
	 sqlite3_close(Database);
  }

  char* errmsg;
  const char *sql="Select * from databases;";

  int result=sqlite3_prepare_v2(Database,sql,-1,&pStatement,NULL);

  if(result!=SQLITE_OK){
  errmsg=(char*)sqlite3_errmsg(Database);
  }

  while(true){
  result=sqlite3_step(pStatement);
  if(result!=SQLITE_ROW) break;

  PVirtualNode entryNode=VirtualStringTree1->AddChild(VirtualStringTree1->RootNode);
  DBStruct *nodeData=(DBStruct*)VirtualStringTree1->GetNodeData(entryNode);

  int column=sqlite3_data_count(pStatement);
  for (int i = 0; i < column; i++) {
	  UnicodeString otwet=(const char*)sqlite3_column_text(pStatement,i);
	  switch(i){
		  case 0:{
		  nodeData->Id=otwet.ToInt();
		  break;
		  }
		  case 1:{
		  nodeData->Origin =otwet;
		  break;
		  }
		  case 2:{
		  nodeData->Name =otwet;
		  break;
		  }
		  case 3:{
          nodeData->Description =otwet;
		  break;
		  }
		  case 4:{
		  nodeData->Estimated_size =otwet.ToInt();
		  break;
		  }
	  }
  }


  }
   sqlite3_finalize(pStatement);

   sqlite3_close(Database);
   VirtualStringTree1->EndUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
if(Node==NULL) return;
 DBStruct *nodeData=(DBStruct*)VirtualStringTree1->GetNodeData(Node);

 switch (Column) {
	case 0:{
	CellText=(UnicodeString)nodeData->Id;
	break;
	}
	case 1:{
	CellText=(UnicodeString)nodeData->Origin;
    break;
	}
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	VirtualStringTree1->Clear();
	Label4->Caption="";
	Label5->Caption="";
	Label6->Caption="";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1AddToSelection(TBaseVirtualTree *Sender,
          PVirtualNode Node)
{
 if(Node==NULL) return;
 DBStruct *nodeData=(DBStruct*)VirtualStringTree1->GetNodeData(Node);

 Label4->Caption=nodeData->Name;
 Label5->Caption=nodeData->Description;
 Label6->Caption=nodeData->Estimated_size;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  sqlite3* Database;
  char* filename="Databases.db";
  PVirtualNode choiseStr=VirtualStringTree1->GetFirstSelected();
  if(choiseStr==NULL) return;

  DBStruct *nodeData=(DBStruct*)VirtualStringTree1->GetNodeData(choiseStr);
  AnsiString str="Delete from databases where id = "+(AnsiString)nodeData->Id+" ;";

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
}
//---------------------------------------------------------------------------

