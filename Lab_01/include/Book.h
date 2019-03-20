# pragma once
# include "B5Page.h"
# include <vector>
class Book : public Page {

	public:
		void Print (void) override; // dziedziczona funkcja wypisywania
		void SetHeader(std::string) override; // dziedziczona funkcja ustawiania naglowkow
			 Book (std::string str="empty"):_Title ("Title: "+str),_Autor("Anonym"){};
				// konstruktor klasy Book
		void AddPage (B5Page* object); // metoda dodajaca obiekty typu B5Page
	private:
		std::string _Title;
		std::string _Autor;
		std::vector <B5Page*> _book; // wektor wskaznikow do obiektow B5Page
		std::vector <B5Page> _st_book; // wektor obiektow B5page
};