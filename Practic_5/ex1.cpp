#include <iostream>


int main() {
	int number;
	std::cout << "Введите число: ";
	std::cin >> number;

	// ERROR!!!
	// if (number = 10) {
	if (number == 10) {
		std::cout << "Вы ввели 10" << std::endl;
	}

	return 0;
}
