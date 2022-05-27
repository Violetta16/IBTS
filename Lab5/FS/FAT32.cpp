#include <iostream>
#include "FAT32.h"

FAT32::FAT32(wchar_t* fileName)
{
byte *dataBuffer = new byte[512];

ReedBootRecord(fileName,dataBuffer);

FAT32BootRecord* pFAT32BootRecord = (FAT32BootRecord*)dataBuffer;

int Byte=GetDec(pFAT32BootRecord->Byte,sizeof(pFAT32BootRecord->Byte));
unsigned long long Sector=GetDec(&pFAT32BootRecord->Sector,sizeof(pFAT32BootRecord->Sector));
unsigned long long TotalSector=GetDec(pFAT32BootRecord->TotalSector,sizeof(pFAT32BootRecord->TotalSector));
int Rezerv=GetDec(pFAT32BootRecord->Rezerv,sizeof(pFAT32BootRecord->Rezerv));
int FATSector=GetDec(&pFAT32BootRecord->FATSector,sizeof(pFAT32BootRecord->FATSector));
unsigned long long FATSize=GetDec(pFAT32BootRecord->FATSize,sizeof(pFAT32BootRecord->FATSize));

Name=L"FAT32";
ClusterSizeFS=Byte*Sector;
CountClusterFS=(TotalSector-Rezerv-FATSector*FATSize)/Sector;
SizeFS=CountClusterFS*ClusterSizeFS;

delete[] dataBuffer;
}
