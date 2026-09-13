# CMakeList.txt: проект CMake для IS-ECM-Practical-Works; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
project(Lab-1)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (IS-ECM-Practical-Works "IS-ECM-Practical-Works.cpp" "IS-ECM-Practical-Works.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET IS-ECM-Practical-Works PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
