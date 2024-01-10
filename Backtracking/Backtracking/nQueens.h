#pragma once

bool right(int arr[], int index, int val) {
	for (int i = 0; i < index; i++) {
		if (arr[i] == val || (abs(arr[i] - val) == abs(i - index)))
			return false;
	}
	return true;
}
bool find_position(int arr[], int index, int size) {
	if (index == size) { return true; }
	for (int i = 0; i < size; i++) {
		if (right(arr, index, i)) {
			arr[index] = i;
			if (find_position(arr, index + 1, size)) {
				return true;
			}
		}

	}
	return false;

}