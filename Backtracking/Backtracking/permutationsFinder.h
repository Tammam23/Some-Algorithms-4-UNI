#pragma once



bool exists(std::string& item, std::list<std::string>& permutations) {
	return std::find(permutations.begin(), permutations.end(), item) != permutations.end();
}

void find_permutations(std::list<std::string>& permutations, std::string elements, std::string item) {
	if (elements.empty()) {
		if (!exists(item, permutations)) {
			permutations.push_back(item);
		}
	}
	else {
		for (int i = 0; i < elements.length(); i++) {
			std::string new_elements = elements.substr(0, i) + elements.substr(i + 1, elements.length());
			std::string new_item = item + elements[i];
			find_permutations(permutations, new_elements, new_item);
		}
	}

}


void run_permutations_finder(std::string strr) {
	std::cout << "\nPermutations of: " << strr << std::endl;

	std::list<std::string> perms;
	find_permutations(perms, strr, "");
	for (std::string s : perms) {
		std::cout << s << std::endl;
	}
}