cmake_minimum_required(VERSION 3.10)
project (DatabaseLab)
add_executable(first src/1/1.cpp)
target_link_libraries(first pqxx)