#include <iostream>
#include <ctime>
#include "./services.h"

using namespace std;


// получение случайного числаиз диапазона start..end
int Randint(int start, int end) {
    srand(time(0));
    return (rand() % (start-end - 1)) + start;
}
