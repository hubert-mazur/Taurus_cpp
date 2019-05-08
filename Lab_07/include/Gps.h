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
	Gps(std::string, double x, double y)
	{
		_direction = "East";

		Latitude(x);
		Longitude(y);
	}

	Gps() = default;

	/**
 	 * Creates new Coordinate object with given paramaters
 	 * @param x - given x
 	 * @param y - given y 
 	 */

	Coordinate Location(double x, double y) // method, that intialize values
	{
		Latitude(y);
		Longitude(x);
		return Coordinate(x, y);
	}

	Coordinate Location() // method returning Coordinate object, obligatory for other another method in class TrackingUnit
	{
		return *this;
	};

	std::string CompassDirection() override // inherited method, that returns direction
	{
		return "G/" + _direction;
	}
};