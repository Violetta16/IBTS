#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <cmath>



void DEC(byte byte[],int length,wchar_t *str){
	std::wcout<<std::dec<<str;
	int summ=0;
	for(int i=0;i<length;i++){
		summ+=byte[i]*std::pow(16,i*2);
	}
	std::wcout<<summ<<"\n";
}

void HEX(byte byte[],int length,wchar_t *str){
	std::wcout<<std::hex<<str;
	for(int i=0;i<length;i++){
		std::wcout<<byte[i]<<" ";
	}
	std::wcout<<std::dec<<"\n";
}
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
  setlocale(LC_ALL,"");
  wchar_t *fileName=L"\\\\.\\C:";

  HANDLE fileHander=CreateFileW(
  fileName,
  GENERIC_READ,
  FILE_SHARE_READ | FILE_SHARE_WRITE,
  NULL,
  OPEN_EXISTING,
  FILE_ATTRIBUTE_NORMAL,
  NULL);

  if(fileHander==INVALID_HANDLE_VALUE){
  wcout<<L"������ ������ ����� C.\n���������� ����� ����� ��������������.";
  cin.get();
  return 0;
  }

  std::byte *dataBuffer = new std::byte[512];

  LARGE_INTEGER sectorOffset;
  sectorOffset.QuadPart=0;

  unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart,FILE_BEGIN);
  if(currentPosition !=sectorOffset.LowPart){
   return 0;
  }

  DWORD bytesToRead=512;
  DWORD bytesRead;
  bool readResult=ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);
  if(readResult==false||bytesRead!=bytesToRead){
   return 0;
  }

	NTFSBootRecord* PNTFSBootRecord=(NTFSBootRecord*)dataBuffer;

	DEC(PNTFSBootRecord->Byte,sizeof(PNTFSBootRecord->Byte),L"���� � �������:");
	DEC(&PNTFSBootRecord->Sector,sizeof(PNTFSBootRecord->Sector),L"�������� � ��������:");
	HEX(&PNTFSBootRecord->MediaDescription,sizeof(PNTFSBootRecord->MediaDescription),L"��� �����:");
	DEC(PNTFSBootRecord->SectorPerTrack,sizeof(PNTFSBootRecord->SectorPerTrack),L"�������� �� �������:");
	DEC(PNTFSBootRecord->NumOfHeads,sizeof(PNTFSBootRecord->NumOfHeads),L"���������� �����:");
	DEC(PNTFSBootRecord->HidSector,sizeof(PNTFSBootRecord->HidSector),L"������� �������:");
	DEC(PNTFSBootRecord->TotalSector,sizeof(PNTFSBootRecord->TotalSector),L"�������� � ����:");
	HEX(PNTFSBootRecord->MFT,sizeof(PNTFSBootRecord->MFT),L"��������� ������� MFT:");
	HEX(PNTFSBootRecord->MFTMirr,sizeof(PNTFSBootRecord->MFTMirr),L"��������� ������� ����� MFT:");
	DEC(PNTFSBootRecord->RecordSeg,sizeof(PNTFSBootRecord->RecordSeg),L"�������� MFT:");
	DEC(&PNTFSBootRecord->IndexBuff,sizeof(PNTFSBootRecord->IndexBuff),L"�������� ��������� ������:");
	HEX(PNTFSBootRecord->VolumeSerNum,sizeof(PNTFSBootRecord->VolumeSerNum),L"�������� ����� ����:");

  cin.get();

  CloseHandle(fileHander);
  delete[] dataBuffer;
  return 0;

}
