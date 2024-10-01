#define SIZE 5
#include <iostream>


void change(int* arr, int* num) {
	arr[*num] = 0;
	*num++;
}


void printArr(int* arr, int size) {
	std::cout << "arr = [ ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;

}


int main() {
	int arr[SIZE] = {5, 24, 60, 32, 10};

	int num;
	std::cout << "Введите число (меньше " << SIZE << "): ";
	std::cin >> num;

	std::cout << "ДО" << std::endl;
	printArr(arr, SIZE);
	std::cout << "num: " << num << std::endl;

	change(arr, &num);
	
	std::cout << "ПОСЛЕ" << std::endl;
	printArr(arr, SIZE);
	std::cout << "num: " << num << std::endl;

	return 0;
}
