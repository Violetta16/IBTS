#include "FSIterator.h"

FSIterator::FSIterator(){

}

FSIterator::FSIterator(AbstractFS fileSystem){
FileSystem=fileSystem;

}

void FSIterator::First(){
Position=0;
}

void FSIterator::Next(){
Position++;
}

bool FSIterator::IsDone(){
return(Position>FileSystem.CountClusterFS);
}

void FSIterator::Reed(byte *outBuffer){
  FileSystem.ReedCluster(Position,outBuffer);
}


