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
// возврат символа N раз в виде string
string StringNTimes(char symbol, int n) {
    string nTimes = "";
    for (int i=0; i<n; i++) {
        nTimes += symbol;
    }
    return nTimes;
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
// возврат сердечек здоровья героя в виде string
string StringHealth() {
    string healthStr = "";

    for (int i=0; i<health; i++) {
        healthStr += "♥";
    }
    for (int i=0; i<(maxHealth-health); i++) {
        healthStr += "♡";
    }
    return healthStr;
}

// печать состояния героя
void PrintState() {
    // преобразование age из float в строку
    char* buf = new char[5];
    sprintf(buf,"%.1lf",age);
    string* ageStr = new string;
    *ageStr = buf;

    // из всех данных собираем строку, чтобы узнать её длину
    string* stateStr = new string;
    *stateStr = "| Возраст: " + *ageStr + " | Заслуга: " + to_string(score) + " | Кэш: " + to_string(cash);
    *stateStr += StringNTimes(' ', 19) + "Боекомплект: " + to_string(ammunition);
    *stateStr += " | Выносливость: " + to_string(stamina) + " | Здоровье: " + StringHealth() + " |";

    // вычитаем 2й байт кириллицы и 2й и 3й байты сердечек для печати строки минусов
    PrintNTimes('-', (*stateStr).length()-58);
    // печать основного текста
    cout << endl << *stateStr << endl;
    // печать строки минусов
    PrintNTimes('-', (*stateStr).length()-58);
    cout << endl;

    delete[] buf;
    delete ageStr;
    delete stateStr;
}
