#include <iostream>
#include "../main_vars/main_vars.h"
#include "../calls/calls.h"

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
    cout << "Боекомплект: " << amunition;
    cout << " | Здоровье: ";
    PrintHealth();
    cout << endl;
}

// краткая печать вызова
void PrintShortCall(Call callStruct) {
    cout << "Место: " << callStruct.place;
    cout << " | Кол-во нарушителей: " << callStruct.people;
    cout << " | Кэш за успешное выполнение: " << callStruct.cash << endl;
}

// полная печать вызова
void PrintFullCall(Call callStruct) {
    cout << "Место: " << callStruct.place << endl;
    cout << "Описание: " << callStruct.desc << endl;
    cout << "Кол-во нарушителей: " << callStruct.people << endl;
    cout << "Опасность (от 1 до 10): " << callStruct.danger << endl;
    cout << "Очки заслуги за успешное выполнение: " << callStruct.score << endl;
    cout << "Кэш за успешное выполнение: " << callStruct.cash << endl;
    cout << "Время выполнения: " << callStruct.timeDuration << endl;
}
