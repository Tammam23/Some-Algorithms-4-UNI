#pragma once


bool find_colors(bool init, std::list<int> countries[], int size, int country_colors[], int current_country);
void run_color_dancer() {
	std::cout << "\nColors:" << std::endl;
	const int countrycount = 9;

	std::list<int> arr[countrycount];

	arr[0].push_back(1);
	arr[0].push_back(2);
	arr[0].push_back(3);
	arr[0].push_back(4);


	arr[1].push_back(0);
	arr[1].push_back(2);
	arr[1].push_back(4);

	arr[2].push_back(0);
	arr[2].push_back(1);
	arr[2].push_back(4);

	arr[3].push_back(0);
	arr[3].push_back(4);
	arr[3].push_back(6);

	arr[4].push_back(0);
	arr[4].push_back(1);
	arr[4].push_back(2);
	arr[4].push_back(3);
	arr[4].push_back(5);
	arr[4].push_back(7);
	arr[4].push_back(8);

	arr[5].push_back(4);

	arr[6].push_back(3);

	arr[7].push_back(4);
	arr[7].push_back(8);

	arr[8].push_back(7);
	arr[8].push_back(4);

	std::map<int, std::string> color_dictionary;

	color_dictionary[0] = "NULL";
	color_dictionary[1] = "RED";
	color_dictionary[2] = "Green";
	color_dictionary[3] = "BLUE";
	color_dictionary[4] = "VIOLET";

	int country_colors[countrycount];
	find_colors(true, arr, countrycount, country_colors, 0);
	for (int i = 0; i < countrycount; i++) {
		std::cout << i + 1 << "th country: " << color_dictionary[country_colors[i]] << std::endl;
	}

}

bool neighbours_not_have(int color, std::list<int> neighbours, int country_colors[]) {
	for (int neighbour : neighbours) {
		if (color == country_colors[neighbour]) {
			return false;
		}

	}
	return true;
}

bool find_colors(bool init, std::list<int> countries[], int size, int country_colors[], int current_country) {
	if (init) {
		init = false;
		for (int i = 0; i < size; i++) {
			country_colors[i] = 0;
		}
	}
	if (country_colors[size - 1] != 0) {
		return true;
	}
	for (int color = 1; color <= 4; color++) {
		if (neighbours_not_have(color, countries[current_country], country_colors)) {
			country_colors[current_country] = color;
			if (find_colors(init, countries, size, country_colors, current_country + 1)) {
				return true;
			}
			else {
				country_colors[current_country] = 0;
			}
		}
	}
	return false;

}