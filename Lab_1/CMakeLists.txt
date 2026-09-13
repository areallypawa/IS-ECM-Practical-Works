project(Lab_1)

# Добавьте источник в исполняемый файл этого проекта.
add_executable(Lab_1 
    main.cpp 
    utils.cpp utils.h
    bitwise_logic.cpp bitwise_logic.h
    menu.cpp menu.h
    my_vector.h
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Lab_1 PROPERTY CXX_STANDARD 20)
endif()
