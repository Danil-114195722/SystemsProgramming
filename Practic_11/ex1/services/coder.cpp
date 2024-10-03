#include <iostream>
#include "./coder.h"


// кодирование/декодирование одного символа
char CaesarCipher(char ch, int shift, bool encrypt) {
	shift %= 26;

	// a - 97
	// z - 122

	// A - 65
	// Z - 90

	// кодирование
	if (encrypt) {
		if (ch >= 97 && ch <= 122 && ch+shift > 122 || ch >= 65 && ch <= 90 && ch+shift > 90) {
			return char(ch+shift-26);
		}
		return char(ch+shift);
	// декодирование
	} else {
		if (ch >= 65 && ch <= 90 && ch-shift < 65 || ch >= 97 && ch <= 122 && ch-shift < 97) {
			return char(ch-shift+26);
		}
		return char(ch-shift);
	}
}
