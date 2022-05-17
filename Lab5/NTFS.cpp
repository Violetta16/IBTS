#include <iostream>
#include<NTFS.h>

class NTFS : public AbstractFS
{
public:
	NTFS(wchar_t* fileName)
	{
	byte *dataBuffer = new byte[512];

	ReedBootRecord(fileName,dataBuffer);

	NTFSBootRecord* pNTFSBootRecord = (NTFSBootRecord*)dataBuffer;

	int Byte=GetDec(pNTFSBootRecord->Byte,sizeof(pNTFSBootRecord->Byte));
	unsigned long long Sector=GetDec(&pNTFSBootRecord->Sector,sizeof(pNTFSBootRecord->Sector));
	unsigned long long TotalSector=GetDec(pNTFSBootRecord->TotalSector,sizeof(pNTFSBootRecord->TotalSector));

	Name=L"NTFS";
	ClusterSizeFS=Byte*Sector;
	CountClusterFS=TotalSector/Sector;
	SizeFS=CountClusterFS*ClusterSizeFS;

	delete[] dataBuffer;
	}

	~NTFS(){
		ClusterSizeFS=0;
		CountClusterFS=0;
		SizeFS=0;
		CloseHandle(fileHander);
	}
};
