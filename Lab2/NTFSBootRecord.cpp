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
  wcout<<L"Ошибка чтения диска C.\nПриложению нужны права администратора.";
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

	DEC(PNTFSBootRecord->Byte,sizeof(PNTFSBootRecord->Byte),L"Байт в секторе:");
	DEC(&PNTFSBootRecord->Sector,sizeof(PNTFSBootRecord->Sector),L"Секторов в кластере:");
	HEX(&PNTFSBootRecord->MediaDescription,sizeof(PNTFSBootRecord->MediaDescription),L"Тип диска:");
	DEC(PNTFSBootRecord->SectorPerTrack,sizeof(PNTFSBootRecord->SectorPerTrack),L"Секторов на дорожку:");
	DEC(PNTFSBootRecord->NumOfHeads,sizeof(PNTFSBootRecord->NumOfHeads),L"Количество голов:");
	DEC(PNTFSBootRecord->HidSector,sizeof(PNTFSBootRecord->HidSector),L"Скрытые сектора:");
	DEC(PNTFSBootRecord->TotalSector,sizeof(PNTFSBootRecord->TotalSector),L"Секторов в томе:");
	HEX(PNTFSBootRecord->MFT,sizeof(PNTFSBootRecord->MFT),L"Стартовый кластер MFT:");
	HEX(PNTFSBootRecord->MFTMirr,sizeof(PNTFSBootRecord->MFTMirr),L"Стартовый кластер копии MFT:");
	DEC(PNTFSBootRecord->RecordSeg,sizeof(PNTFSBootRecord->RecordSeg),L"Кластеры MFT:");
	DEC(&PNTFSBootRecord->IndexBuff,sizeof(PNTFSBootRecord->IndexBuff),L"Кластеры индексной записи:");
	HEX(PNTFSBootRecord->VolumeSerNum,sizeof(PNTFSBootRecord->VolumeSerNum),L"Серийный номер тома:");

  cin.get();

  CloseHandle(fileHander);
  delete[] dataBuffer;
  return 0;

}
