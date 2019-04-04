#pragma once
#include "Haversine.h"

/**
 * This is a class representing point on map?
 */
class Gps: public Coordinate{
public:
	/**
 	 * Gps default constructor 
 	 */
	Gps() = default;

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

};