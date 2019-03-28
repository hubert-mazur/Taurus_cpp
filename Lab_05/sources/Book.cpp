#include "Book.h"
#include "B5Page.h"
#include "A4Page.h"
int Book::NPages(void)
{
	return _number_of_pages;
}
Book& Book::operator++()
{
	_number_of_pages+=1;
	return *this;
}

void Book::operator=(Book& object)
{

	if (this->_format != object._format)
	{
		std::cout<<"[ERROR]:: Trying to assign different formats!\n";
	}

	for (int i=0;i<this->_number_of_pages;i++)
	{
		delete this->pages[i];
	}
	
	this->pages.clear();

	for (int i=0;i<object._number_of_pages;i++)
	{
		if (object._format == "B5")
			this->pages.emplace_back(new B5Page);
		else
			this->pages.emplace_back(new A4Page);
	}
	this->_number_of_pages = object._number_of_pages;
}