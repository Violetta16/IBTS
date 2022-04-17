#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#pragma pack(push,1)

typedef struct
{
	byte Skip1[11];
	byte Byte[2];
	byte Sector;
	byte Skip2[7];
	byte MediaDescription;
	byte Skip3[2];
	byte SectorPerTrack[2];
	byte NumOfHeads[2];
	byte HidSector[4];
	byte Skip4[8];
	byte TotalSector[8];
	byte MFT[8];
	byte MFTMirr[8];
	byte RecordSeg[4];
	byte IndexBuff;
	byte Skip5[11];
	byte VolumeSerNum[8];


} NTFSBootRecord;

#pragma pack(pop)

#endif
