# pragma once
# include "Page.h"
class B5Page : public Page {

	public:
		void Print (void) override; // dziedziczona funkcja wypisywania
		void SetHeader (std::string) override; // dziedziczona funkcja ustawiania naglowkow
		B5Page (std::string header="empty",std::string text_buffer="empty"):Page (header,text_buffer){};
		// konstruktor klasy
		B5Page* Copy (void); // funkcja kopiujaca
		std::string get_header (void) // getter naglowka
			{
				return _Header;
			}
		std::string get_text_buffer (void) // getter tekstu
			{
				return _text_buffer;
			}
			 virtual std::string Text (void) override 
			 {
				 return _text_buffer;
			 };

};