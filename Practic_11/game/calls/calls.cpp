#include <iostream>
#include <cmath>
#include <unistd.h>
#include "./calls.h"
#include "./printing.h"

#include "../main_vars/main_vars.h"
#include "../main_vars/printing.h"
#include "../services/services.h"

using namespace std;


// список мест по возрастанию опасности
string placesList[10] = {
    "Библиотека",
    "Больница",
    "Рынок",
    "Бар",
    "Гипермаркет",
    "Гостиница",
    "Музей",
    "Театр",
    "Банк",
    "Главная городская площадь",
};


// получение описания вызова
string GetCallDesc(int placeIdx, int peopleDanger, int people) {
    // определение описания человека/людей
    string peolpeDesc = "";
    switch (peopleDanger) {
        case 1:
            if (people == 1) {
                peolpeDesc = "Мужчина в нетрезвом состоянии";
            } else {
                peolpeDesc = "Компания из " + to_string(people) + " пьяных обормотов";
            }
            break;
        case 2:
            if (people == 1) {
                peolpeDesc = "Сумасшедший мужчина";
            } else {
                peolpeDesc = "Группа из " + to_string(people) + " сумасшедших";
            }
            break;
        case 3:
            if (people == 1) {
                peolpeDesc = "Неизвестный вооружённый в маске";
            } else if (people <= 4) {
                peolpeDesc = "Группа вооружённых из " + to_string(people) + " человек";
            } else {
                peolpeDesc = "Банда вооружённых, насчитывающая " + to_string(people) + " человек,";
            }
            break;
    }

    string desc = "";
    switch (placeIdx) {
        case 0:
            desc = "Вызов в библиотеку. " + peolpeDesc + " нарушает правопорядок. Звонок поступил от постоянного посетителя библиотеки.";
            break;
        case 1:
            desc = "Вызов в больницу. " + peolpeDesc + " нарушает спокойствие больных. Звонок поступил от главврача больницы №2.";
            break;
        case 2:
            desc = "Вызов на северный рынок. " + peolpeDesc + " действует против закона. Звонок поступил от посетителя рынка.";
            break;
        case 3:
            desc = "Вызов в бар. " + peolpeDesc + " устраивает непорядки. Поступило сразу несколько звонков от бармена и посетителей.";
            break;
        case 4:
            desc = "Вызов в гипермаркет. " + peolpeDesc + " обрушивает витрины и другими способами показывает своё недовольство. Звонок поступил от покупателя, который сообщил, что это недовольство как-то связано с криптовалютой.";
            break;
        case 5:
            desc = "Вызов в гостиницу. " + peolpeDesc + " нарушает правила гостиницы. Звонок поступил от администратора этой гостиницы.";
            break;
        case 6:
            desc = "Вызов в музей. " + peolpeDesc + " нарушает закон. Звонок поступил от музейного смотрителя.";
            break;
        case 7:
            desc = "Вызов в театр. " + peolpeDesc + " прерывает постановку и устраивает непорядки. Поступило несколько звонков от важных особ, возмущённых происходящим.";
            break;
        case 8:
            if (people == 1) {
                desc = "Вызов в банк. " + peolpeDesc + " совершает попытку ограбления. Звонок поступил от клиента, который успел выйти из здания до начала происходящего.";
            } else {
                desc = "Вызов в банк. " + peolpeDesc + " совершает попытку ограбления. Звонок поступил от клиента, который успел выйти из здания до начала происходящего. По его словам, в лицах грабителей он узнал очередную команду хакатонщиков, которой не удаётся выиграть уже много лет.";
            }
            break;
        case 9:
            desc = "Вызов на главную городскую площадь. " + peolpeDesc + " прерывает важное мероприятие, нарушая закон. Поступило множество звонков от посетителей и организаторов мероприятия.";
            break;
    }
    return desc;
}


// получение случайного вызова
void GetRandomCall(Call* emptyCall) {
    sleep(1);

    // получение случайного id для случайного места
    int* randPlaceIdx = new int;
    *randPlaceIdx = Randint(0, 9);

    // получение случайного места
    string* randPlace = new string;
    *randPlace = placesList[Randint(0, 9)];

    // получение случайного кол-ва людей
    int* randPeople = new int;
    *randPeople = Randint(1, 8) + Randint(0, *randPlaceIdx/3+2);

    // получение случайной опасности людей
    int* randPeopleDanger = new int;
    *randPeopleDanger = Randint(1, 3);

    // получение описания вызова
    string* callDesc = new string;
    *callDesc = GetCallDesc(*randPlaceIdx, *randPeopleDanger, *randPeople);

    // расчёт общей опасности вызова
    int* callDanger = new int;
    *callDanger = ceil(float((*randPlaceIdx) + (*randPeople) + (*randPeopleDanger-1)) / 2.5);

    // расчёт счёта за успешное выполнение задачи
    int* callScore = new int;
    *callScore = (*callDanger) * (*randPeople) + Randint(10, 40);

    // расчёт денег за успешное выполнение задачи
    int* callCash = new int;
    *callCash = (*callDanger) + Randint(10, 30);

    // расчёт времени на выполнение задачи
    float* callTimeDuration = new float;
    *callTimeDuration = *callDanger / 10.0;

    (*emptyCall).isOccupied = true;
    (*emptyCall).place = *randPlace;
    (*emptyCall).desc = *callDesc;
    (*emptyCall).people = *randPeople;
    (*emptyCall).peopleDanger = *randPeopleDanger;
    (*emptyCall).danger = *callDanger;
    (*emptyCall).score = *callScore;
    (*emptyCall).cash = *callCash;
    (*emptyCall).timeDuration = *callTimeDuration;

    delete randPlaceIdx;
    delete randPlace;
    delete randPeople;
    delete randPeopleDanger;
    delete callDesc;
    delete callDanger;
    delete callScore;
    delete callCash;
    delete callTimeDuration;
}


// выполнение вызова (пересчёт жизней и патронов, засчитывание счёта, лет жизни и денег)
// возвращает true, если вызов был успешно выполнен, иначе - false
bool PerformCall(Call callStruct) {
    cout << "\nБорьба с нарушителями..." << endl;

    // эмуляция борьбы с нарушителями
    int* randPatronsForPeople = new int;
    for (int i = 0; i < callStruct.people; ++i) {
        cout << "Осталось нарушителей: " << callStruct.people - i << " (осталось патронов: " << ammunition << " | здоровье: ";
        PrintHealth();
        cout << ")" << endl;
        sleep(1);

        // если закончились патроны, то отнимаем сердечко
        if (ammunition <= 0) {
            ammunition = 0;
            cout << "патроны кончились" << endl;
            cout << "-♥" << endl;
            health--;
        } else {
            // 100% выпадает 1 патрон
            if (ammunition == 1) {
                *randPatronsForPeople = 1;
            // рандомно выпадает от 1 до 2 патронов
            } else if (ammunition == 2) {
                *randPatronsForPeople = Randint(1, 70);
            // рандомно выпадает от 1 до 3 патронов
            } else if (ammunition == 3) {
                *randPatronsForPeople = Randint(1, 90);
            // рандомно выпадает от 1 до 4 патронов
            } else {
                *randPatronsForPeople = Randint(1, 100);
            }

            // затрачивается 1 патрон (30%)
            if (*randPatronsForPeople <= 30) {
                cout << "-1 патрон" << endl;
                ammunition--;
            // затрачивается 2 патрона (40%)
            } else if (*randPatronsForPeople <= 70) {
                cout << "-2 патрона" << endl;
                ammunition -= 2;
            // затрачивается 3 патрона (20%) и может потратиться 1 сердечко (20%)
            } else if (*randPatronsForPeople <= 90) {
                cout << "-3 патрона" << endl;
                if (Randint(1, 100) > 80) {
                    cout << "-♥" << endl;
                    health--;
                }
                ammunition -= 3;
            // затрачивается 4 патрона (10%) и 1 сердечко (100%)
            } else {
                cout << "-4 патрона" << endl;
                cout << "-♥" << endl;
                health--;
                ammunition -= 4;
            }
        }

        // если сердечки закончились, то "game over"
        if (health <= minHealth) {
            cout << "Здоровье закончилось (осталось патронов: " << ammunition << " | здоровье: ";
            PrintHealth();
            cout << ")" << endl;

            sleep(3);
            health = minHealth;
            return false;
        }
    }
    delete randPatronsForPeople;
    cout << "Все нарушители устранены! (осталось патронов: " << ammunition << " | здоровье: ";
    PrintHealth();
    cout << ")" << endl;
    sleep(3);

    age += callStruct.timeDuration;
    cash += callStruct.cash;
    score += callStruct.score;

    cout << "\nВызов завершён успешно!" << endl;
    cout << "+ Полученный кэш: " << callStruct.cash << endl;
    cout << "+ Полученный счёт заслуги: " << callStruct.score << endl;
    cout << "+ Затраченно времени на вызов: " << callStruct.timeDuration << endl << endl;

    return true;
}


// передвинуть элементы массива вызовов (например, если есть 5 вызовов, и юзер выполнил 3й)
void RecollectCallList(Call* callList, int selectedCallIdx) {
    // помечаем вызов завершённым
    callList[selectedCallIdx].isOccupied = false;

    for (int i = 1; i < 9; ++i) {
        // проверка на наличие вызова на предыдущем месте в массиве
        if (!(callList[i-1].isOccupied)) {
            callList[i-1] = callList[i];
            callList[i].isOccupied = false;
        }
    }
}
