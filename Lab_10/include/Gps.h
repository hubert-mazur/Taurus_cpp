#pragma once
#include "Haversine.h"
#include "Compass.h"
#include <string>

/**
 * This is a class representing point on map?
 */
class Gps : public Coordinate, virtual public Compass
{
public:
	/**
 	 * Gps default constructor 
 	 */
	Gps(std::string, double x, double y):Compass ("North"),Coordinate(x,y)
	{
		_direction = "East";

		// Latitude(x);
		// Longitude(y);
		// std::cout<<x<<std::endl;
	}

	Gps() = default;

	/**
 	 * Creates new Coordinate object with given paramaters
 	 * @param x - given x
 	 * @param y - given y 
 	 */

	Gps (const Gps &object):Coordinate(object.Latitude(),object.Longitude())
	{
		// std::cout<<"operator = "<<Longitude()<<std::endl;
	}


	Coordinate Location(double x, double y) // method, that intialize values
	{
		Latitude(y);
		Longitude(x);
		return Coordinate(x, y);
	}

	Coordinate LocationInfo() // method returning Coordinate object, obligatory for other another method in class TrackingUnit
	{
		// return *this;
		return Coordinate (Longitude(),Latitude());
	};

	std::string CompassDirection() override // inherited method, that returns direction
	{
		return "G/" + _direction;
	}

	Gps& operator= (const Gps &object)
	{
		// std::cout<<"operator = "<<object.Longitude()<<std::endl;
		Longitude(object.Longitude());
		Latitude (object.Latitude());
		return *this;
	}
};

std::ostream& operator<< (std::ostream& ostr,Coordinate object)
{
	ostr << "Longitude: "<<object.Longitude()<<" Latitude: "<<object.Latitude();
	return ostr; 
}