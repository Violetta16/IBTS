#pragma once
class AbstractFS {
protected:

	HANDLE fileHander;

	unsigned long long GetDec(byte vBootRecord[],int size)
	{
		unsigned long long sum=0;
		for (int i = 0; i < size; i++)
		{
			sum+=vBootRecord[i]*std::pow(16,i*2);
		}
		return sum;
	}

	void ReedBootRecord(wchar_t* fileName, byte *dataBuffer){

    fileHander=CreateFileW(fileName,
	GENERIC_READ,
	FILE_SHARE_READ | FILE_SHARE_WRITE,
	NULL,
	OPEN_EXISTING,
	FILE_ATTRIBUTE_NORMAL,
	NULL);

	if(fileHander == INVALID_HANDLE_VALUE)
	{
		ShowMessage(L"Ошибка чтения диска C.\nПриложению нужны права администратора.\n");
		CloseHandle(fileHander);
	}

	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=0;


	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
		 ShowMessage(L"Ошибка постановки курсора.\n");
		 CloseHandle(fileHander);
		 delete[] dataBuffer;
	 }

	 DWORD bytesToRead=512;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,dataBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
     	ShowMessage(L"Ошибка чтения файла.\n");
		CloseHandle(fileHander);
		delete[] dataBuffer;
	 }

	}


public:
    wchar_t* Name;
	unsigned long long SizeFS;
	unsigned long long CountClusterFS;
	unsigned int ClusterSizeFS;


	void ReedCluster(int NumberCluster, BYTE *outBuffer){
	LARGE_INTEGER sectorOffset;
	sectorOffset.QuadPart=ClusterSizeFS*NumberCluster;

	unsigned long currentPosition = SetFilePointer(fileHander,sectorOffset.LowPart,&sectorOffset.HighPart ,FILE_BEGIN);

	 if(currentPosition != sectorOffset.LowPart)  {
	 }

	 DWORD bytesToRead=ClusterSizeFS;
	 DWORD bytesRead;
	 bool readResult = ReadFile(fileHander,outBuffer,bytesToRead,&bytesRead,NULL);

	 if(readResult == false || bytesRead != bytesToRead){
	 }
	}

};
