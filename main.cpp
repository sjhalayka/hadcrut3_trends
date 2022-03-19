#include "main.h"


int main(void)
{
	if (false == get_data(sd))
		return -1;
	
	size_t min_years_per_slope = 20;

	unsigned short int min_year = 10000;
	unsigned short int max_year = 0;

	for (map<size_t, station_data>::const_iterator cs = sd.begin(); cs != sd.end(); cs++)
	{
		for (map<short unsigned int, year_data>::const_iterator cy = cs->second.years.begin(); cy != cs->second.years.end(); cy++)
		{
			if (cy->first < min_year)
				min_year = cy->first;

			if (cy->first > max_year)
				max_year = cy->first;
		}
	}

	cout << min_year << " " << max_year << endl;

	vector<float> all_output_trends;

	for (map<size_t, station_data>::const_iterator cs = sd.begin(); cs != sd.end(); cs++)
	{
		vector<float> local_output_trends;

		get_local_trends(sd, cs->first, min_year, max_year, local_output_trends, min_years_per_slope);

		for (size_t i = 0; i < local_output_trends.size(); i++)
			all_output_trends.push_back(local_output_trends[i]);
	}
	
	double slope_mean = 0;

	for (size_t i = 0; i < all_output_trends.size(); i++)
		slope_mean += all_output_trends[i];

	slope_mean /= static_cast<double>(all_output_trends.size());
	cout << "Global warming (degrees per century): ";
	cout << 100*slope_mean << " +/- " << 100 * standard_deviation(all_output_trends) << endl;





	//write_trend_histogram(sd, 100, min_years_per_slope);



	return 0;
}



