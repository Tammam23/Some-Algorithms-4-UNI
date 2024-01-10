#include <iostream>
#include <list>
#include <map>
#include "Color_countries.h"
#include "pathFinder.h"
#include "nQueens.h"
#include "permutationsFinder.h"


int main() {
	const int countrycount = 9;

	std::list<int> arr[countrycount];



	run_color_dancer();
	run_pathfinder();
	run_permutations_finder("ABCD");

	//N Queens
	std::cout << "\nQueen positions:" << std::endl;

	int positions[8];
	find_position(positions, 0, 8);
	for (int position : positions) {
		std::cout << position << std::endl;
	}

}

