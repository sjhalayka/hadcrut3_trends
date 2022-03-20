#ifndef STATION_DATA_H
#define STATION_DATA_H



#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
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

	float regline_slope(vector<float> &x, vector<float> &y);
	bool get_data(map<size_t, station_data> &sd);
	void write_trend_histogram(const map<size_t, station_data>&sd, long unsigned int num_histogram_bins, const size_t min_samples_per_slope = 20);
	void get_local_trends(const map<size_t, station_data>& sd, const size_t& station_id, const short unsigned int& first_year, const short unsigned int& last_year, vector<float>& output_trends, const size_t min_samples_per_slope);
	float standard_deviation(const vector<float> &src);


#endif
