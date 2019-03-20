# pragma once
# include <string>
# include <iostream>
class Page {

	public:

		virtual ~Page () = default; // wirtualny destruktor
		virtual void Print (void) = 0; // wirtualna funkcja wypisywania
		virtual void SetHeader (std::string) = 0; // wirtualna funkcja ustawiania naglowkow
		Page (std::string header="empty",std::string text_buffer="empty"):_Header(header),_text_buffer(text_buffer){};
			// konstruktor klasy
	protected:
		std::string _Header;
		std::string _text_buffer;
};