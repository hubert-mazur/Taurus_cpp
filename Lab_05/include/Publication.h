#pragma once
#include <string>

class Publication 
{

	public:

	virtual ~Publication () = default; 
	// wirtualny destruktor klasy

	static Publication* Create (std::string name,int number_of_pages,std::string format); 
	// statyczna funkcja tworzenia odpowiednich publikacji

	virtual int NPages(void) = 0;
	// czysto wirtualna metoda zwracajaca liczbe stron

	protected:
		std::string _name; // nazwa publikacji
		int _number_of_pages; // liczba stron publikacji
		std::string _format; // format publikacji
};