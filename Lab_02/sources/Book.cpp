# include "Book.h"

void Book::AddPage (B5Page* object)
{
	bool check=false;
	for (int i=0;i<(int)(_book.size());i++)
	{
		if (_book[i]==object)
		{
			std::cout<<"[WARNING]:: Trying to add already existing page!"<<std::endl;
			check = true;
		}
	}
	if (!check)
	_book.emplace_back (object);
	_st_book.emplace_back (*object);
}

void Book::Print (void)
{
	std::cout<<std::endl;
	std::cout<<"[Book::autor]       "<<_Autor<<std::endl;
	std::cout<<"[Page(0)::text]     "<<_Title<<std::endl;
	for (int i=0;i<(int)(_book.size());i++)
		{
			std::cout<<"[Page("<<i+1<<")::header]   "<<_st_book[i].get_header()<<std::endl;
			std::cout<<"[Page("<<i+1<<")::text]     "<<_st_book[i].get_text_buffer()<<std::endl;
		}
}
void Book::SetHeader (std::string str)
{
	for (int i=0;i<(int)(_st_book.size());i++)
	{
		_st_book[i].SetHeader(str);
	}
}