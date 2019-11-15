#include "starting_location.hpp"

// This file contains the definiton of "start", which askes users to input the starting location and returns the location information
// and "lat", whicch is for abstracting the latitude from the location information from start() and return it
// and "lon", whicch is for abstracting the longtitude from the location information from start() and return it
// and "loc", whicch is for abstracting the name of the location from the location information from start() and return it

std::string start()
{
	std::string latitude, longitude,location,s;
	
	std::cin >> latitude;
	std::cin >> longitude;
	std::cin.ignore(1);
	std::getline(std::cin, location);

	s=latitude+" "+longitude+" "+location;
	return s;
}


std::string lat(std::string s)
{
	std::string r = s.substr(0,s.find('/')+2);
	return r;
}

std::string lon(std::string s)
{
	std::string r = s.substr(s.find('/')+3, s.find('/',9)-s.find('/')-1);
	return r;
}

std::string loc(std::string s)
{
	std::string r = s.substr(s.find('/',9)+3,-1);
	return r;
}