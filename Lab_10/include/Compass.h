# pragma once
#include <string>

class Compass 
{

	public:
		virtual std::string	CompassDirection ();
		Compass ():_direction("West"){};
		Compass (std::string str):_direction(str){};
		Compass( Compass &object)
		{
			_direction = object.get_direction();	
		}
		std::string get_direction ()
		{
			return _direction;
		}
		 static std::string North();
	protected:
		std::string _direction; 

};

