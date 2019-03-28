#pragma once
#include "Publication.h"

class Magazine : public Publication
{
	public:

	 int NPages() override // nadpisanie metody zwracajacej liczbe stron
	 {
		 return _number_of_pages;
	 }
};