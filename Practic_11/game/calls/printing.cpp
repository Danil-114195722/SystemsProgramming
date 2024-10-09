#include <iostream>
#include "./printing.h"

#include "./calls.h"

using namespace std;


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
