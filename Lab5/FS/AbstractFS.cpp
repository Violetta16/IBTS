#include "AbstractFS.h"

unsigned long long AbstractFS::GetDec(byte vBootRecord[],int size)
{
	unsigned long long sum=0;
	for (int i = 0; i < size; i++)
	{
		sum+=vBootRecord[i]*std::pow(16,i*2);
	}
	return sum;
}

void AbstractFS::ReedBootRecord(wchar_t* fileName, byte *outBuffer){

	fileHander=CreateFileW(fileName,
	GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
		ShowMessage("Ошибка чтения диска C.\nПриложению нужны права администратора.");
		CloseHandle(fileHander);
	}

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=0;

	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
		 ShowMessage("Ошибка постановки курсора.");
		 CloseHandle(fileHander);
		 delete[] outBuffer;
	 }

	DWORD bytesToRead=512;
	DWORD bytesRead;
	bool readResult = ReadFile(fileHander,outBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
		ShowMessage("Ошибка чтения файла.");
		CloseHandle(fileHander);
		delete[] outBuffer;
	 }

}

void AbstractFS::ReedCluster(unsigned long long NumberCluster, BYTE *outBuffer){

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=ClusterSizeFS*NumberCluster;
	unsigned long long currentPosition;
	currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	if(currentPosition != sectorOffset.LowPart)  {
	}

	DWORD bytesToRead=ClusterSizeFS;
	DWORD bytesRead;
	bool readResult = ReadFile(fileHander,outBuffer,bytesToRead,&bytesRead,NULL);

	if(readResult == false || bytesRead != bytesToRead){
	}
}


