#pragma once
bool findpath(std::list<int> maze[], std::list<int>& visited, std::list<int>& path, int current, const int goal, bool init);

void run_pathfinder() {
	std::cout << "\nPath:" << std::endl;

	std::list<int> arr[9];
	arr[0].push_back(1);
	arr[0].push_back(3);

	arr[1].push_back(0);
	arr[1].push_back(2);

	arr[2].push_back(1);

	arr[3].push_back(0);
	arr[3].push_back(4);
	arr[3].push_back(6);

	arr[4].push_back(3);
	arr[4].push_back(5);
	arr[4].push_back(7);

	arr[5].push_back(4);

	arr[6].push_back(3);

	arr[7].push_back(4);
	arr[7].push_back(8);

	arr[8].push_back(7);

	std::list<int> visited;
	std::list<int>path;
	findpath(arr, visited, path, 0, 8, true);
	for (int iter : path)
		std::cout << iter << std::endl;
}

bool findpath(std::list<int> maze[], std::list<int>& visited, std::list<int>& path, int current, const int goal, bool init) {
	if (init) {
		init = false;
		path.push_back(current);
		visited.push_back(current);
	}
	if (current == goal) {
		return true;
	}

	for (int choice : maze[current]) {
		if (std::find(visited.begin(), visited.end(), choice) == visited.end()) {
			visited.push_back(choice);
			path.push_back(choice);
			if (findpath(maze, visited, path, choice, goal, init)) {
				return true;
			}
			else {
				path.pop_back();
			}
		}

	}
	return false;

}
