#include <iostream>


int main() {
	int count = 0;
	char stroka[] = {"AaBbCcDdEeFfGgggggg"};
	int size = sizeof(stroka) / sizeof(stroka[0]);

	for(unsigned i = 0; i < size; ++i) {
		if (stroka[i] >= 65 && stroka[i] <= 90) {
			count++;
		}
	}

	std::cout << "Count capital letters: " << count << std::endl;

	return 0;
}
