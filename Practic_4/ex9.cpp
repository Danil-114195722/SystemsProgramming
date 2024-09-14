#include <iostream>


int main() {
	int count = 0;
	char stroka[] = {"Aaa1323#aa"};
	int size = sizeof(stroka) / sizeof(stroka[0]);

	for(unsigned i = 0; i < size; ++i) {
		if(stroka[i] == 'A' || stroka[i] == 'a') {
			count++;
		}
	}

	std::cout << "Count 'A' letter: " << count << std::endl;

	return 0;
}

