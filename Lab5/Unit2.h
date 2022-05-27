//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include "AbstractFS.h"
//---------------------------------------------------------------------------
class MyThread : public TThread
{
private:
	AbstractFS FileSystem;
protected:
	void __fastcall Execute();
public:
	__fastcall MyThread(AbstractFS fileSystem,bool CreateSuspended);
	void __fastcall UpdateLoading();
    float load;
};
//---------------------------------------------------------------------------
#endif
