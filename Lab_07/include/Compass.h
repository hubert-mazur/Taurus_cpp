# pragma once
#include <string>

class Compass 
{

	public:
		virtual std::string	CompassDirection ();
		Compass ():_direction("West"){};
		Compass (std::string str):_direction(str){};
		 static std::string North();
	protected:
		std::string _direction; 

};

