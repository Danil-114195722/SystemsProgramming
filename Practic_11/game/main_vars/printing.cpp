#include <iostream>
#include "./printing.h"

#include "./main_vars.h"

using namespace std;


// печать символа N раз
void PrintNTimes(char symbol, int n) {
    for (int i=0; i<n; i++) {
        cout << symbol;
    }
}

// печать сердечек здоровья героя
void PrintHealth() {
    for (int i=0; i<health; i++) {
        cout << "♥";
    }
    for (int i=0; i<(maxHealth-health); i++) {
        cout << "♡";
    }
}

// печать состояния героя
void PrintState() {
    cout << "Возраст: " << age;
    cout << " | Заслуга: " << score;
    cout << " | Кэш: " << cash;
    PrintNTimes(' ', 20);
    cout << "Боекомплект: " << ammunition;
    cout << " | Здоровье: ";
    PrintHealth();
    cout << endl;
}
