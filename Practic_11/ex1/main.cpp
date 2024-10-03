#include <iostream>
#include "./services/encode.h"
#include "./services/decode.h"


int main() {
	char word[] = "hello, world";
	std::cout << "word: " << word << std::endl;

	EncodeWord(word, 5);
	std::cout << "encrypted word: " << word << std::endl;

	DecodeWord(word, 5);
	std::cout << "decrypted word: " << word << std::endl;

	return 0;
}
