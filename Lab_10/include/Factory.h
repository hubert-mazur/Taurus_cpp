#pragma once

#include "Gps.h"
#include "TrackingUnit.h"

class Factory {

	public:

	Factory () = default;


	template <typename T>
	void prototype (const T &object)
	{
		library<T> (false,object);
	}


	template <typename T>
	T produce ()
	{
		 return library <T> (true,Gps ());
	}



	template <typename T>
	T library (bool do_return,const T &object)
	{
		static T temporary;

		if (!do_return)
		{
			 temporary = object;
		}

		return temporary;
	}


};