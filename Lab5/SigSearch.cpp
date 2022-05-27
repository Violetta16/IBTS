#include "SigSearch.h"

byte jpeg[]={0xFF,0xD8,0xFF,0xE0};
byte png[]={0x89,0x50,0x4E,0x47,0x0D,0x0A,0x1A,0x0A};
byte zip[]={0x50,0x4B,0x03,0x04};
byte rar[]={0x52,0x61,0x72,0x21,0x1A,0x07,0x01};
byte gzip[]={0x1F,0x8B,0x08,0x00};
byte zip7[]={0x37,0x7A,0xBC,0xAF,0x27};
byte *sign[]={jpeg,png,zip,rar,gzip,zip7};

SigSearch::SigSearch(){

}

String SigSearch::Search(byte *outBuffer){
String type[]={"JPEG","PNG","ZIP","RAR","GZIP","7-ZIP"};
int num=Check(outBuffer);
if(num>=0)
return type[num];
else
return "";
}

int SigSearch::Check(byte *outBuffer){

for(int i=0;i<6;i++){
   for(int j=0;j<sizeof(sign[i]);j++){
	if(outBuffer[j]==sign[i][j])
	{
	if(j==sizeof(sign[i])-1)
    return i;
	}
	else
    break;
   }
}
return -1;
}

