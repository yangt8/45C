#include "destination.hpp"

// This file contains the function destination, which is actual main function for the whole programs

void destination()
{
	std::string s,start_lat,start_lon,start_loc;
	s = start();
	start_lat = lat(s);
	start_lon = lon(s);
	start_loc = loc(s);

	unsigned int number;
	std::cin>>number;

	double x = lati_long(start_lat);
	double y = lati_long(start_lon);

	double max, min;
	std::string farthest, closest, f_lat, f_lon, c_lat, c_lon;

	for (unsigned int i=0; i<number; i++)
	{
		std::string latitude, longitude, target_location;

		std::cin >> latitude;
		std::cin >> longitude;
		std::cin.ignore(1);
		std::getline(std::cin, target_location);

		double a = lati_long(latitude);
		double b = lati_long(longitude);

		if (i==0) 
		{
			max = distance(x,a,y,b);
			min = distance(x,a,y,b);
			farthest = closest = target_location;
			f_lat=c_lat=latitude;
			f_lon=c_lon=longitude;

		}
		else
		{
			if (max < distance(x,a,y,b))
			{
				max = distance(x,a,y,b);
				farthest = target_location;
				f_lat=latitude;
				f_lon=longitude;
			}
			if (min > distance(x,a,y,b))
			{
				min = distance(x,a,y,b);
				closest = target_location;
				c_lat=latitude;
				c_lon=longitude;
			}
		}
	}


	std::cout << "Start Location: "<< start_lat << " " << start_lon << " (" << start_loc << ")" << std::endl;

	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) //
	<< "Closest Location: "<< c_lat << " " << c_lon << " (" << closest //
	<< ") (" << min << " miles)" << std::endl;

	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) //
	<< "Farthest Location: "<< f_lat << " " << f_lon << " (" << farthest //
	<< ") (" << max << " miles)" << std::endl;
    
}
