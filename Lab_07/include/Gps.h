#pragma once
#include "Haversine.h"
#include "Compass.h"
#include <string>

/**
 * This is a class representing point on map?
 */
class Gps: public Coordinate, virtual public Compass{
public:
	/**
 	 * Gps default constructor 
 	 */
	Gps(std::string,double x, double y)
	{
		_direction = "East";
	}
	Gps () = default ;

	/**
 	 * Creates new Coordinate object with given paramaters
 	 * @param x - given x
 	 * @param y - given y 
 	 */

	Coordinate Location(double x, double y){
		Latitude(y);
		Longitude(x);
		return Coordinate(x,y);
	}

	void Location (const Coordinate &object) 
	{
		
	};

	Coordinate Location () 
	{
		return *this;
	};

	double Distance ()
	{
		return 0.0;
	}

	void Go (double x,std::string str)
	{
		
	}



	std::string CompassDirection () override
	{
		return "G/" + _direction;
	}

};