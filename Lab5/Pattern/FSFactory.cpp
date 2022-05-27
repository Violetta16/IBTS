#include "FSFactory.h"
#include <string.h>

FSFactory::FSFactory(){

}
AbstractFS FSFactory::FactoryFS(wchar_t* fileName){
   AbstractFS  FileSystem;

   byte *dataBuffer = new byte[512];
   FileSystem.ReedBootRecord(fileName,dataBuffer);
   switch(CheckFS(dataBuffer)){
   case(0):
   FileSystem=NTFS(fileName);
   break;

   case(1):
   FileSystem=FAT32(fileName);
   break;

   }
   delete[] dataBuffer;
   return FileSystem;

}
int FSFactory::CheckFS(byte *dataBuffer){
		std::string FS[]={"NTFS","MSDOS5.0"};
   for(int i=0; i<sizeof(FS);i++){
		for(int j=0;j<sizeof(FS[i]);j++){
		 if(dataBuffer[3+j]!=FS[i][j])
			break;
		 return i;
		}
   }
   return 2;
}

