#include "ObiektMiotajacy.h"
#include "MyExceptions.h"
void ObiektMiotajacy::Rzuc()
{
	throw (new typ1(this));
}