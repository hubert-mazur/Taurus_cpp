#pragma once
#include <iostream>
#include "Publication.h"
#include "TitlePage.h"

#include <vector>
#include "Page.h"
class Book : public Publication
{
	public:

		int NPages() override;
		// nadpisanie funkcji wirtualnej z klasy bazowej


		Book ():Publication() // konstruktor klasy Book
		{
			_TitlePage_ptr = new TitlePage;

		}

		TitlePage* TitlePagePtr () // metoda zwracajaca tytul publikacji
		{
			return _TitlePage_ptr;
		} 

		Book& operator=( const Book& object);
		// operator przypisania

		Book& operator++();
		// operator inkrementacji liczby stron

		~Book () override // dekonstruktor klasy Book
		{
			for (int i=0;i<_number_of_pages; i++)
			{
				delete pages[i];
			}
			delete _TitlePage_ptr;
		}

		std::vector <Page*> pages;

	protected:
		TitlePage* _TitlePage_ptr; // wskaznik do strony tytulowej
		
};

