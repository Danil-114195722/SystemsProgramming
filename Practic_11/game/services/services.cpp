#include <iostream>
#include <ctime>
#include "./services.h"

using namespace std;


// получение случайного числаиз диапазона start..end
int Randint(int start, int end) {
    srand(time(0));
    return (rand() % (start-end - 1)) + start;
}

// возвращает true, если num есть в массиве arr
bool InArray(int* arr, int size, int num) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}
