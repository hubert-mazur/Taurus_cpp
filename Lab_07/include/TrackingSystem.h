# pragma once

#include "Compass.h"
class TrackingSystem : virtual public Compass 
{
	public:

	TrackingSystem (): Compass("North"){};
	std::string CompassDirection () override 
	{
		return "T/" + _direction;
	}

};