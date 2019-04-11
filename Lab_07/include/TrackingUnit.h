#pragma once

#include "Gps.h"
#include "TrackingSystem.h"

class TrackingUnit : public Gps, public TrackingSystem
{
	public:
		
		 TrackingUnit():Compass("South"){};

		std::string CompassDirection () override
		{
			return "TUnit/" + _direction;
		}

		void Start ()
		{

		}
		
		double LocationInfo ()
		{
			return 0.0;
		}

};