#ifndef MAIN_H
#define MAIN_H


#include "station_data.h"

#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <complex>
using namespace std;


void get_min_and_max_years(const map<long unsigned int, station_data>& sd, short unsigned int& min_year, short unsigned int& max_year)
{
	unsigned short int min = 10000;
	unsigned short int max = 0;

	for (map<long unsigned int, station_data>::const_iterator cs = sd.begin(); cs != sd.end(); cs++)
	{
		for (map<short unsigned int, year_data>::const_iterator cy = cs->second.years.begin(); cy != cs->second.years.end(); cy++)
		{
			if (cy->first < min)
				min = cy->first;

			if (cy->first > max)
				max = cy->first;
		}
	}

	min_year = min;
	max_year = max;
}

void get_mean_and_std_deviation(map<long unsigned int, station_data>& sd, const short unsigned int min_year, const short unsigned int max_year, float& mean, float& std_dev, const size_t min_years_per_slope)
{
	vector<float> all_output_trends;

	for (map<long unsigned int, station_data>::const_iterator cs = sd.begin(); cs != sd.end(); cs++)
	{
		vector<float> local_output_trends;

		get_local_trends(sd[cs->first], min_year, max_year, local_output_trends, min_years_per_slope);

		// cout << cs->first << ' ' << cs->second.name << ' ' << cs->second.country << ' ' << local_output_trends.size() << " trends" << endl;

		for (size_t i = 0; i < local_output_trends.size(); i++)
			all_output_trends.push_back(local_output_trends[i]);
	}

	float slope_mean = 0;

	for (size_t i = 0; i < all_output_trends.size(); i++)
		slope_mean += all_output_trends[i];

	slope_mean /= all_output_trends.size();

	mean = slope_mean;
	std_dev = standard_deviation(all_output_trends);
}


#endif
