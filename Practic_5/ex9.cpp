#include <iostream>


int main() {
	int num = 5;
	int *pNum = new int;
	*pNum = num;

	std::cout << "Number before: " << *pNum << std::endl;

	*pNum = 10;
	std::cout << "Number after: " << *pNum << std::endl;
	
	float *pFloat = new float;
	*pFloat = 5.5;
	std::cout << "Float value: " << *pFloat << std::endl;
	
	int arr[5] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	delete pNum;
	delete pFloat;

	return 0;
}
