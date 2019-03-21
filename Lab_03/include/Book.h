#pragma once
#include "B5Page.h"
#include <vector>
#include "TitlePage.h"
class Book : public Page
{

  public:
	friend std::ostream &operator<<(std::ostream &ostrm, const Book &object);

	void Print(void) override{};			// dziedziczona funkcja wypisywania
	void SetHeader(std::string) override{}; // dziedziczona funkcja ustawiania naglowkow

	Book(std::string title, int number_of_pages, std::string format) : _format(format), _Title(title)
	{
		_book.emplace_back(new TitlePage);
		for (int i = 0; i < number_of_pages; i++)
			_book.emplace_back(new B5Page());
	}

	int size(void)
	{
		return _book.size();
	}

	TitlePage *TitlePagePtr(void)
	{
		return dynamic_cast<TitlePage *>(_book[0]);
	}

	Page *operator[](int iterator)
	{
		return _book[iterator];
	}

	~Book(void)
	{
		for (int i = 0; i < (int)_book.size(); i++)
			delete _book[i];
	}
	std::string Format(void)
	{
		return _format;
	}
	std::string get_title(void)
	{
		return _Title;
	}

	virtual std::string Text(void) { return _text_buffer; };

  private:
	std::string _Autor;
	std::vector<Page *> _book; // wektor wskaznikow do obiektow Page
	std::string _format;
	std::string _Title;
};

inline std::ostream &operator<<(std::ostream &ostrm, const Book &object)
{

	ostrm << "[Book::Title]    " << object._Title;
	ostrm << std::endl;
	ostrm << "[Book::Author]   " << dynamic_cast<TitlePage *>(object._book[0])->get_autor();
	ostrm << std::endl;
	int i;
	for (i = 1; i < (int)object._book.size(); i++)
	{
		if (dynamic_cast<B5Page *>(object._book[i])->get_text_buffer() != "empty")
			break;
	}
	ostrm << "[Page(" << i << ")::text]  " << dynamic_cast<B5Page *>(object._book[i])->get_text_buffer();
	ostrm << std::endl;
	ostrm << std::endl;
	return ostrm;
}
