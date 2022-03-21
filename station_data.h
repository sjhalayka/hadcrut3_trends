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
	bool get_data(map<long unsigned int, station_data> &sd);
	void get_min_and_max_years(const map<long unsigned int, station_data>& sd, short unsigned int& min_year, short unsigned int& max_year);
	void get_mean_and_std_deviation(map<long unsigned int, station_data>& sd, const short unsigned int min_year, const short unsigned int max_year, float& mean, float& std_dev, const size_t min_years_per_slope);
	void write_trend_histogram(const map<long unsigned int, station_data>&sd, const long unsigned int num_histogram_bins, const size_t min_samples_per_slope = 20);
	void get_local_trends(const station_data &s, const short unsigned int& first_year, const short unsigned int& last_year, vector<float>& output_trends, const size_t min_samples_per_slope);
	float standard_deviation(const vector<float> &src);


#endif
