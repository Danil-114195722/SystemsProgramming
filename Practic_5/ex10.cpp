#include <iostream>


int main() {	
	float fValue = 3.14;
	float *pfValue;
	pfValue = &fValue;
	
	std::cout << "Float value: " << *pfValue << std::endl;
	
	int arr[5] = {1, 2, 3, 4, 5};
	int *pArr = new int[5];
	
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
		pArr[i] = arr[i];
	}
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << pArr[i] << " ";
	}
	std::cout << std::endl;
	
	pfValue = nullptr;

	delete pfValue;
	delete[] pArr;

	return 0;
}

