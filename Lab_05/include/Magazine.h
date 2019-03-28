#pragma once
#include "Publication.h"

class Magazine : public Publication
{
	public:

	 int NPages(void) override // nadpisanie metody zwracajacej liczbe stron
	 {
		 return _number_of_pages;
	 }
};