#define SIZE 5
#include <iostream>


int min(int arr[SIZE]) {
	int minNum = arr[0];

	for(int i = 1; i < SIZE; i++) {
		if(arr[i] < minNum) {
			minNum = arr[i];
		}
	}
	return minNum;
}

int max(int arr[SIZE]) {
	int maxNum = arr[0];

	for(int i = 1; i < SIZE; i++) {
		if(arr[i] > maxNum) {
			maxNum = arr[i];
		}
	}
	return maxNum;
}


int main() {
	int array[SIZE] = {5, 4, 3, 4, 9};

	int subMaxMin = max(array) - min(array);
	std::cout << "Max - Min = " << subMaxMin << std::endl;

	return 0;
}
