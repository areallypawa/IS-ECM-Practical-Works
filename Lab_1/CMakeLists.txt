cmake_minimum_required(VERSION 3.10)

project(Lab_1)

# Добавьте источник в исполняемый файл этого проекта.
add_executable(Lab_1 
    main.cpp
    src/bitwise_logic/bitwise_logic.cpp
    src/bitwise_logic/bitwise_logic.h
    src/menu/menu.cpp
    src/menu/menu.h
    src/utils/utils.cpp
    src/utils/utils.h
    ../MyVector/my_vector.h
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab_1 PROPERTY CXX_STANDARD 20)
endif()