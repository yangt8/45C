#include "calculating.hpp"

// This file contaisn the definition of "deistance" and "lati_long"
// "distance" is for calculating the great-circle distance between 2 locations given their latitudes and longitudes
// "lati_long" is to get the latitudes or longtitudes with considerating the direction for calculating the distance


double distance(double lat1, double lat2, double lon1, double lon2)
{
	double dlat = lat1-lat2;
	double dlon = lon1-lon2;

	double a = (sin(dlat/2*M_PI/180))*(sin(dlat/2*M_PI/180)) + cos(lat1*M_PI/180)//
	 * cos(lat2*M_PI/180) * sin(dlon/2*M_PI/180)* sin((dlon/2)*M_PI/180);
	double c = 2 * atan2(sqrt(a),sqrt(1-a));
	double d = 3959.9 *c;
	return d;
}


double lati_long(std::string i)
{
	char direction = i.at(i.length()-1);
	double u=std::stod(i.substr(0,i.length()-2));
	if (direction=='S' or direction =='W')
	{
		u=-1*u;
	}
	return u;
}