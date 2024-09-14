#include <iostream>


int main() {
	char stroka[] = {"aaaabbbbccccdddd"};
	int size = sizeof(stroka) / sizeof(stroka[0]);

	std::cout << stroka << std::endl;

	// size-1 - костыль для пропуска \0
	for(int i = 0; i < (size-1); ++i) {
		stroka[i] -= 32;
	}

	std::cout << stroka << std::endl;
	
	return 0;
}
