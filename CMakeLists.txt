cmake_minimum_required(VERSION 3.20)
project (Clion_codigos)

set(CMAKE_CXX_STANDARD 14)

add_executable(books class/1.main.cpp class/1.book.cpp)
add_executable(pets class/2.pet.cpp class/2.pet_class.cpp)
add_executable(struct_employee structs/3.empleados.cpp)
add_executable(gym structs/4.gym_activity.cpp)
add_executable(file ./archivos/dateProduct.cpp)
add_executable(file1 ./archivos/dateProduct1.cpp)