#ifndef STATION_DATA_H
#define STATION_DATA_H



#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <complex>
using namespace std;


	class year_data
	{
	public:
		float temperatures[12];

		year_data(void);
		bool operator==(const year_data &rhs) const;
		friend ostream& operator<<(ostream &out, const year_data &y);
	};

	class station_data
	{
	public:
		string name;
		string country;
		float latitude;
		float longitude;
		map<short unsigned int, year_data> years;

		station_data(void);
		bool operator==(const station_data &rhs) const;
		friend ostream& operator<<(ostream &out, const station_data &s);
	};

	float regline_slope(const vector<complex<float>> &xy);
	bool get_data(map<size_t, station_data> &sd);
	void write_trend_histogram(const map<size_t, station_data>&sd, const long unsigned int num_histogram_bins, const size_t min_samples_per_slope = 20);
	void get_local_trends(const station_data &s, const short unsigned int& first_year, const short unsigned int& last_year, vector<float>& output_trends, const size_t min_samples_per_slope);
	float standard_deviation(const vector<float> &src);


#endif
