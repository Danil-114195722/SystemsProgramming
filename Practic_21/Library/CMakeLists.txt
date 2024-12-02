# Проверка версии CMake (если версия меньше, то будет ошибка)
cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Название проекта
project(library)

# библиотека literature
add_library(literature
	./Literature/ILiterature.cpp
	./Literature/Book.cpp
	./Literature/Magazine.cpp
	./Literature/Newspaper.cpp
)

# библиотека persons
add_library(persons
	./Persons/IPerson.cpp
	./Persons/Employee.cpp
)

# библиотека visitors
add_library(visitors
	./Persons/Visitors/IVisitor.cpp
	./Persons/Visitors/Guest.cpp
	./Persons/Visitors/Client.cpp
)

# библиотека library
add_library(library
	./Library/Library.cpp
)

# исполняемый файл с именем app
add_executable(app
	main.cpp
)

# Линковка программы с библиотеками
target_link_libraries(app literature persons visitors library)
