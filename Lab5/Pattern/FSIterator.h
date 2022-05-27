#include "AbstractFS.h"

class FSIterator{
public:
FSIterator();
FSIterator(AbstractFS fileSystem);
AbstractFS FileSystem;

unsigned long long Position;
void First();
void Next();
bool IsDone();
virtual void Reed(byte *outBuffer);

};
