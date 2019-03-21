#pragma once
#include <iostream>
#include "Publication.h"

class Book : public Publication
{
	std::string DOI (void) override;
	// zdefiniowanie interfejsu DOI dla klasy Book
};