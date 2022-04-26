//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class MyTread : public TThread
{
private:
	byte *dataBuffer;
	void __fastcall UpdateCaption();
    void __fastcall ErrorLog(int i);
    int j;
protected:
	void __fastcall Execute();
public:
	__fastcall MyTread(bool CreateSuspended);
	TEvent *MyEvent;
    class MyTread2 *Tread2;
};
//---------------------------------------------------------------------------
#endif
