#pragma once
#include "Publication.h"

class Magazine : public Publication
{
	public:
	 std::string DOI (void) override;
	 // zdefiniowanie interfejsu DOI dla klasy Magazine
};