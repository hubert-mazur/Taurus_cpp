#pragma once
#include "Publication.h"

class TitlePage : public Publication {

	public:
		void SetTitle (std::string str) // metoda ustawiajaca tytul 
		{
			_Title = str;
		}

		std::string GetTitle  (void) // metoda zwracajaca tytul
		{
			return _Title;
		}

		int NPages(void) override // nadpisana metoda zwracajaca liczbe stron
		{
			return 1;
		}

	protected:
		std::string _Title; // zmienna przechowujaca tytul publikacji

};