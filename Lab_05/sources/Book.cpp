#include "Book.h"
#include "B5Page.h"
#include "A4Page.h"
int Book::NPages()
{
	return _number_of_pages;
}
Book& Book::operator++()
{
	_number_of_pages+=1;
	if (this->_format == "B5")
	this->pages.emplace_back(new B5Page);
	else
	{
		this->pages.emplace_back(new A4Page);
	}
	return *this;
}

Book& Book::operator=(const Book& object)
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
	 		this->pages.emplace_back(new B5Page(dynamic_cast<B5Page&>(*object.pages[i])));
	 	else
	 		this->pages.emplace_back(new A4Page(dynamic_cast<A4Page&>(*object.pages[i])));
	 }
	this->_number_of_pages = object._number_of_pages;
	return *this;
}