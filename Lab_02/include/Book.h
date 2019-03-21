#pragma once
#include "B5Page.h"
#include <vector>
#include "TitlePage.h"
class Book : public Page
{

  public:
	void Print(void) override;			  // dziedziczona funkcja wypisywania
	void SetHeader(std::string) override; // dziedziczona funkcja ustawiania naglowkow
										  //Book (std::string str="empty"):_Title ("Title: "+str),_Autor("Anonym"){};
	Book(std::string title, int number_of_pages, std::string format) : _Title(title), _format(format)
	{
		_book.emplace_back(new TitlePage());
		for (int i = 1; i < number_of_pages + 1; i++)
		{
			_book.emplace_back(new B5Page());
		}
	}
	friend std::ostream &operator<<(std::ostream &ostrm, const Book &object);
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
		// delete ptr;
	}
	std::string get_title(void)
	{
		return _Title;
	}

	void AddPage(B5Page *object); // metoda dodajaca obiekty typu B5Page
  private:
	std::string _Title;
	std::string _Autor;
	std::vector<Page *> _book;	// wektor wskaznikow do obiektow Page
	std::vector<B5Page> _st_book; // wektor obiektow B5page
	std::string _format;
};
inline std::ostream &operator<<(std::ostream &ostrm, const Book &object)
{
	ostrm << "[Book::Title]        " << object._Title << " (" << dynamic_cast<TitlePage *>(object._book[0])->get_subtitle() << ")";
	ostrm << std::endl;
	ostrm << "[Book::Author]       " << dynamic_cast<TitlePage *>(object._book[0])->get_autor();
	ostrm << std::endl;
	for (int i = 1; i < static_cast<int>(object._book.size()); i++)
	{
		if (dynamic_cast<B5Page *>(object._book[i])->get_header() != "empty")
		{
			ostrm << "[Page(" << i - 1 << ")::header]    " << dynamic_cast<B5Page *>(object._book[i])->get_header();
			ostrm << std::endl;
		}
		ostrm << "[Page(" << i - 1 << ")::text]      " << dynamic_cast<B5Page *>(object._book[i])->get_text_buffer();
		ostrm << std::endl;
	}

	return ostrm;
}