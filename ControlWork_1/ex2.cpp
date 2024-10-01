#include <iostream>

int main() {
	int arr[] = {5, 4, 3, 4, 9};
	int size = sizeof(arr) / sizeof(arr[0]);

	int maxElemIdx = 0;
	int maxElem = arr[maxElemIdx];
	for (int i = 1; i < size; ++i) {
		if (arr[i] > maxElem) {
			maxElemIdx = i;
			maxElem = arr[maxElemIdx];
		}
	}
	std::cout << "Максимальный элемент: " << maxElem << " | индекс: " << maxElemIdx << std::endl;

	return 0;
}