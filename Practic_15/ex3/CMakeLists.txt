# Проверка версии CMake (если версия меньше, то будет ошибка)
cmake_minimum_required(VERSION 3.2)


# Название проекта
project(ex3)


# Установка переменной со списком исходников для исполняемого файла
set(SOURCE_EXE main.cpp)

# Установка переменной со списком исходников для библиотеки
set(SOURCE_LIB Animal.cpp)

# Создание статической библиотеки с именем module
add_library(classes STATIC ${SOURCE_LIB})
# Создает исполняемый файл с именем app
add_executable(app ${SOURCE_EXE})

# Линковка программы с библиотекой
target_link_libraries(app classes)

