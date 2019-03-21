# include "B5Page.h"

void B5Page::Print (void) 
{
	std::cout<<"[Page::header]   "<<_Header<<std::endl;
	std::cout<<"[Page::text]     "<<_text_buffer<<std::endl;
}
void B5Page::SetHeader (std::string str)
{
	_Header=str;
}
