#include <iostream>


int main() {
	int sumFor = 0, sumWhile = 0;

	int arr[] = {500, 4, 24, 15, 100, 105};
	int size = sizeof(arr) / sizeof(arr[0]);

	for(int i = 0; i < size; i++) {
		sumFor += arr[i];
	}

	int j = 0;
	while(j < size) {
	    sumWhile += arr[j];
	    j++;
	}

	std::cout << "sumFor = " << sumFor << std::endl;
	std::cout << "sumWhile = " << sumWhile << std::endl;

	return 0;
}
