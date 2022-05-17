#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include<AbstractFS.h>

#pragma pack(push,1)

typedef struct
{
	byte Skip1[11];
	byte Byte[2];
	byte Sector;
	byte Skip2[18];
	byte TotalSector[4];
} FAT32BootRecord;

#pragma pack(pop)

#endif
