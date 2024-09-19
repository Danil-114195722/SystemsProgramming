#include <iostream>


int getCharStringSize(unsigned char* charString) {
	int size = 0;
	int i = 0;
	while (charString[i] != '\0') {
		// проверка на кириллицу (в кодировке UTF-8 кодируется как два байта: 208 (или 209) и 128-191)
		if(int(charString[i]) == 208 or int(charString[i]) == 209) {
			i++;
			continue;
		}
		i++;
		size++;
	}
	return size;
}


int compareStrings(unsigned char* string1, unsigned char* string2) {
	int sizeof1 = getCharStringSize(string1);
	int sizeof2 = getCharStringSize(string2);

	// std::cout << "str1: " << sizeof1 << " | str2: " << sizeof2 << std::endl;
	if (sizeof1 == sizeof2) {
		return 0;
	} else if (sizeof1 > sizeof2) {
		return 1;
	} else {
		return -1;
	}

	return 0;
}


int main() {
	unsigned char str1[] = "red тополь";
	unsigned char str2[] = "красный ping";

	std::cout << "compareStrings result = " << compareStrings(str1, str2) << std::endl;

	return 0;
}
