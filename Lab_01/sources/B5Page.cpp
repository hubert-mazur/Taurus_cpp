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
B5Page* B5Page::Copy (void)
{
	return new B5Page (_Header,_text_buffer);
}