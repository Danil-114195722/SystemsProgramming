# Проверка версии CMake (если версия меньше, то будет ошибка)
cmake_minimum_required(VERSION 3.2)


# Название проекта
project(classes)


# Установка переменной со списком исходников для класса Human, Child, Adult
set(SOURCE_LIB ./human/Human.cpp ./human/Child.cpp ./human/Adult.cpp)
# Создание статической библиотеки для класса Human
add_library(human STATIC ${SOURCE_LIB})

# Установка переменной со списком исходников для класса Car, Truck, PassangerCar
set(SOURCE_LIB ./car/Car.cpp ./car/Truck.cpp ./car/PassangerCar.cpp)
# Создание статической библиотеки для класса Car
add_library(car STATIC ${SOURCE_LIB})

# Установка переменной со списком исходников для класса Animal, Wild, Pet
set(SOURCE_LIB ./animal/Animal.cpp ./animal/Wild.cpp ./animal/Pet.cpp)
# Создание статической библиотеки для класса Animal
add_library(animal STATIC ${SOURCE_LIB})

# Установка переменной со списком исходников для валидаторов
set(SOURCE_LIB ./validators/validators.cpp)
# Создание статической библиотеки для валидаторов
add_library(validators STATIC ${SOURCE_LIB})


# Установка переменной со списком исходников для исполняемого файла
set(SOURCE_EXE main.cpp)
# Создает исполняемый файл с именем app
add_executable(app ${SOURCE_EXE})


# Линковка программы с библиотеками
target_link_libraries(app human car animal validators)
