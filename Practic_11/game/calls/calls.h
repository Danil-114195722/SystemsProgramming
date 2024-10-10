using namespace std;


// структура с информацией о вызове
struct Call {
    bool isOccupied; // флаг занятости ячейки (для массива вызовов)
    string place; // место
    string desc; // описание
    int people; // кол-во человек
    int peopleDanger; // опасность человека(людей) [от 1 до 3, где 1 - пьяный(ые), 2 - сумасшедший(ие), 3 - вооружённый(ые)]
    int danger; // опасность (от 1 до 10)
    int score; // получаемый счёт заслуги при успехе выполнения вызова
    int cash; // получаемое кол-во денег при успехе выполнения вызова
    float timeDuration; // затрачиваемое время на вызов (часть от года)
};

void GetRandomCall(Call* emptyCall);

bool PerformCall(struct Call callStruct);

void RecollectCallList(Call* callList, int selectedCallIdx);
