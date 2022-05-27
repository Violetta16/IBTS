#include "Decorator.h"

class IterDecorator : public Decorator
{
public:
	FSIterator iter;
	IterDecorator(FSIterator Iter);
   	void Reed(byte *outBuffer) override;
};
