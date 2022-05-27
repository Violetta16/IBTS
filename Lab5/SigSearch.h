#ifdef _WIN32
#include "Unit1.h"

class SigSearch{
public:
	SigSearch();
	String Search(byte *outBuffer);
private:
	int Check(byte *outBuffer);

};

#endif