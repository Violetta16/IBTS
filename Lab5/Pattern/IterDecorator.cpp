#include "IterDecorator.h"

IterDecorator::IterDecorator(FSIterator Iter){
 iter=Iter;
 FileSystem=iter.FileSystem;
}

void IterDecorator::Reed(byte *outBuffer)
{
bool Empty=true;
while(Empty)
	{
	  iter.Reed(outBuffer);
	  for(int i=0;i<512;i++)
	  {
		if(outBuffer[i]!=0)
		  {
			  Empty = false;
			  break;
		  }
	  }
	  if(Empty)
		iter.Next();
	}
}
