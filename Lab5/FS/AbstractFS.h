#pragma once
#include <iostream>
#include "Unit1.h"


class AbstractFS {
protected:
	unsigned long long GetDec(BYTE vBootRecord[],int size);

public:
    HANDLE fileHander;
    wchar_t* Name;
	unsigned long long SizeFS;
	unsigned long long CountClusterFS;
	unsigned int ClusterSizeFS;
	void ReedBootRecord(wchar_t* fileName, BYTE *outBuffer);
	void ReedCluster(unsigned long long NumberCluster, BYTE *outBuffer);
};
