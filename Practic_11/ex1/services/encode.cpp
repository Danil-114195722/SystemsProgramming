#include <iostream>
#include "./coder.h"


void EncodeWord(char* word, int shift) {
	int* iterCharIdx = new int;
	*iterCharIdx = 0;
	char* iterChar = new char;
	*iterChar = word[*iterCharIdx];

	while (*iterChar != '\0') {
		// если буква входит в диапазон обрабатываемых кодируемых символов
		if (*iterChar >= 97 && *iterChar <= 122 || *iterChar >= 65 && *iterChar <= 90) {
			word[*iterCharIdx] = CaesarCipher(*iterChar, shift, true);
		}
		
		(*iterCharIdx)++;
		*iterChar = word[*iterCharIdx];
	}

	delete iterCharIdx;
	delete iterChar;
}
