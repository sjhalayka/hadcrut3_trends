
#ifndef main_H
#define main_H

#include "station_data.h"



#include <ctime>


#include <sstream>
using std::ostringstream;

#include <string>
using std::string;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include <ios>
using std::ios_base;
using std::ios;

#include <iomanip>
using std::setiosflags;
using std::setprecision;



// If you merge this code into a larger project, you should probably
// at least wrap these global variables/functions in a namespace.

map<size_t, station_data> sd;
const float pi = 4.0f * atanf(1.0f);





void latlon_to_xyz(const double &lat, const double &lon, double &x, double &y, double &z)
{
	double theta = 2*pi*(lon + 180.0)/360.0;
	double phi = pi*(lat + 90.0)/180.0;

	x = -(cos(theta)*sin(phi));
	z = -(sin(theta)*sin(phi));
	y = -cos(phi);
}


void xyz_to_latlon(const double &x, const double &y, const double &z, double &lat, double &lon)
{
	double theta = pi + atan2(z, x);
	double phi = acos(-y);

	lat = phi/pi*180.0 - 90.0;
	lon = theta/(2*pi)*360.0 - 180.0;
}



#endif