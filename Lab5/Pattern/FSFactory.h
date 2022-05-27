#include "FAT32.h"
#include "NTFS.h"


class FSFactory
{
 public:
	FSFactory();
	AbstractFS FactoryFS(wchar_t* fileName);
    int CheckFS(byte *dataBuffer);
};