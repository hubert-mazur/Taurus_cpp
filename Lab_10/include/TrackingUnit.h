#pragma once

#include "Gps.h"
#include "TrackingSystem.h"
#include "Haversine.h"
class TrackingUnit : public Gps, public TrackingSystem
{
public:
	friend std::ostream &operator<<(std::ostream &, const TrackingUnit &object); // operatot, that provides output

	TrackingUnit() : Compass("South"){obj = NULL;}; // class constructor intializing direction

	~TrackingUnit() = default; // deconstructor
	// {
	// 	// delete obj;
	// }

	std::string CompassDirection() override //inherited method, that returns direction
	{
		return "TUnit/" + _direction;
	}

	void Start() // setting starting point
	{
		if (!obj)
		obj = new class Distance(*this, *this);
		else
		{
			obj->Start(Coordinate(Latitude(),Longitude()));
		}
			
	}

	TrackingUnit (const Gps &object):Gps(" ",object.Longitude(),object.Latitude()),TrackingSystem()
	{
		Longitude(object.Longitude());
		Latitude(object.Latitude());
	};

	TrackingUnit &LocationInfo()
	{
		return *this;
	}

	void Location(const Coordinate &object) // info about location
	{
		Longitude(object.Latitude());
		Latitude(object.Longitude());
	}

	void Go(double x, std::string str) // moving in direction
	{
		this->MoveInDirection(x, str);
		obj->End(*this);
	}

	double Distance() // distance between points
	{
		return obj->Value();
	}

	TrackingUnit& operator= (const TrackingUnit &object)
	{
		Longitude(object.Longitude());
		Latitude (object.Latitude());
		return *this;
	}

private:
	class Distance *obj; // pointer to distance class, necessary due to distance calculations
};

inline std::ostream &operator<<(std::ostream &os, const TrackingUnit &object)
{
	os << "Longitude: " << object.Longitude() << " Latitude: " << object.Latitude();
	return os;
}