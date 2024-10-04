#include <iostream>
#include "./services/encode.h"
#include "./services/decode.h"


int main() {
	char word[256];
	std::cout << "Hello!" << std::endl << "It's a Caesar cipher encoder/decoder." << std::endl << std::endl;

	char mode;
	std::cout << "Enter mode [E (e) - for encode | D (d) - for decode | any - for exit] ";
	std::cin >> mode;
	int shift;

	while (mode == 'E' || mode == 'e' || mode == 'D' || mode == 'd') {
		std::cout << "Enter the shift for encoding/decoding [natural number] ";
		std::cin >> shift;

		std::cout << "Enter the word below:" << std::endl;
		std::cin >> word;

		if (mode == 'E' || mode == 'e') {
			EncodeWord(word, shift);
			std::cout << "Encoded word:" << std::endl << word << std::endl << std::endl;
		} else {
			DecodeWord(word, shift);
			std::cout << "Decoded word:" << std::endl << word << std::endl << std::endl;
		}

		std::cout << "Enter mode [E (e) - for encode | D (d) - for decode | any - for exit] ";
		std::cin >> mode;
	}

	std::cout << "Goodbye!" << std::endl;

	return 0;
}
