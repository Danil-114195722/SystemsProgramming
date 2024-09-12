#define SIZE 5
#include <iostream>


int main() {
	int arr[] = {5, 4, 3, 4, 9};

	int maxNumIndex = 0;
	int maxNum = arr[maxNumIndex];

	for(int i = 1; i < SIZE; i++) {
		if(arr[i] > maxNum) {
			maxNumIndex = i;
			maxNum = arr[maxNumIndex];
		}
	}

	std::cout << "maxNum: " << maxNum << " | maxNumIndex: " << maxNumIndex << std::endl;

	return 0;
}

