#pragma once

#include "Pomieszczenie.h"


template <void (Pomieszczenie::*T)() >
	void Lokaj (Pomieszczenie &object)
	{
		(object.*T)();
	}

template <int>
	void Lokaj (Pomieszczenie object)
	{
		std::cout<<"Nic nie robie."<<std::endl;
	}

template <void (Pomieszczenie::*T)() >
	void Lokaj (const Pomieszczenie &object)
	{
		std::cout<<"Pomieszczenie "<<object.getName()<<" jest zamkniete."<<std::endl;
	}





