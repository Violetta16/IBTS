//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class MyTread2 : public TThread
{
private:
	TEvent *MyEvent;
	byte *DataBuffer;
    int heshsum;
protected:
	void __fastcall Execute();
	void __fastcall UpdateCaption();

public:
	__fastcall MyTread2(TEvent *myEvent,byte *dataBuffer,bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
