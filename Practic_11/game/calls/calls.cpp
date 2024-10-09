#include <iostream>
#include <cmath>
#include "../services/services.h"
// #include <map>

using namespace std;


// список мест по возрастанию опасности
string placesMap[10] = {
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


// структура с информацией о вызове
struct Call {
    string place; // место
    string desc; // описание
    int people; // кол-во человек
    int peopleDanger; // опасность человека(людей) [от 1 до 3, где 1 - пьяный(ые), 2 - сумасшедший(ие), 3 - вооружённый(ые)]
    int danger; // опасность (от 1 до 10)
    int score; // получаемый счёт заслуги при успехе выполнения вызова
    int cash; // получаемое кол-во денег при успехе выполнения вызова
    float timeDuration; // затрачиваемое время на вызов (часть от года)
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
    // получение случайного id для случайного места
    int* randPlaceIdx = new int;
    *randPlaceIdx = Randint(0, 9);

    // получение случайного места
    string* randPlace = new string;
    *randPlace = placesMap[Randint(0, 9)];

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
    *callScore = (*callDanger) * (*randPeople) + Randint(0, 30);

    // расчёт денег за успешное выполнение задачи
    int* callCash = new int;
    *callCash = (*callDanger) + Randint(0, 20);

    // расчёт времени на выполнение задачи
    float* callTimeDuration = new float;
    *callTimeDuration = *callDanger / 10.0;

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
void PerformCall(Call* emptyCall) {

}