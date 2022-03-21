#include "main.h"


int main(void)
{
	// Map key is station ID
	map<long unsigned int, station_data> sd;
	const size_t min_years_per_slope = 20;


	if (false == get_data(sd))
		return -1;


	// Print everything to the console
	// print_all(sd);



	// Get earliest and most recent years with records
	unsigned short int min_year = 0;
	unsigned short int max_year = 0;

	get_min_and_max_years(sd, min_year, max_year);

	cout << min_year << " " << max_year << endl;
	

	// Collect all trends and gather the mean and standard deviation
	float mean = 0;
	float std_dev = 0;

	get_mean_and_std_deviation(sd, min_year, max_year, mean, std_dev, min_years_per_slope);

	cout << "Global warming (degrees per century): ";
	cout << 100 * mean << " +/- " << 100 * std_dev << endl;


	// Create a histogram and a gnuplot script
	write_trend_histogram(sd, 100, min_years_per_slope);


	return 0;
}



