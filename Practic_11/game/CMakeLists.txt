# Проверка версии CMake (если версия меньше, то будет ошибка)
cmake_minimum_required(VERSION 3.2)


# Название проекта, версия и язык (C++)
project(game VERSION 1.0 LANGUAGES CXX)


# Установка переменной со списком исходников для исполняемого файла
set(SOURCE_EXE main.cpp)

# Установка переменной со списком исходников для библиотеки
set(SOURCE_LIB
	./main_vars/main_vars.cpp
	./main_vars/printing.cpp
	
	./calls/calls.cpp
	./calls/printing.cpp
	
	./location/location.cpp
	./hospital/hospital.cpp
	./shop/shop.cpp
	./office/office.cpp

	./services/services.cpp
)

# Создает исполняемый файл с именем app
add_executable(app ${SOURCE_EXE})
# Создание статической библиотеки с именем modules
add_library(modules STATIC ${SOURCE_LIB})

# Линковка программы с библиотекой
target_link_libraries(app modules)
