cmake_minimum_required(VERSION 3.10)
project (DatabaseLab)
add_executable(first src/1/1.cpp)
add_executable(second src/2/2.cpp)
add_executable(third src/3/3.cpp)
add_executable(fourth src/4/4.cpp)
target_link_libraries(first pqxx)
target_link_libraries(second pqxx)
target_link_libraries(third pqxx)
target_link_libraries(fourth pqxx)