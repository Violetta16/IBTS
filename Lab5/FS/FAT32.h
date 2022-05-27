#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#include "AbstractFS.h"

class FAT32 : public AbstractFS
{
public:
	FAT32(wchar_t* fileName);
};

#pragma pack(push,1)

typedef struct
{
	byte Skip1[11];
	byte Byte[2];
	byte Sector;
	byte Rezerv[2];
	byte FATSector;
	byte Skip2[15];
	byte TotalSector[4];
	byte FATSize[4];
} FAT32BootRecord;

#pragma pack(pop)

#endif
