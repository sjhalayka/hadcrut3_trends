#include "main.h"


int main(int argc, char** argv)
{
	if (false == get_data(sd))
		return -1;

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

	//for (map<size_t, station_data>::const_iterator cs = sd.begin(); cs != sd.end(); cs++)
	//{
	//	vector<float> output_trends;

	//	cout << cs->second.country << " " << cs->second.name << endl;

	//	get_local_trends(sd, cs->first, min_year, max_year, output_trends, 20);
	//	
	//	cout << output_trends.size() << endl;
	//}
	

	write_trend_histogram(sd, 100, 20);



	return 0;
}



