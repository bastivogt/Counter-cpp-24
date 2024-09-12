cmake_minimum_required(VERSION 3.0)

project(counter_oop_example)

add_executable(counter_oop_example main.cpp classes/Counter.cpp classes/Counter2.cpp)

install(TARGETS counter_oop_example RUNTIME DESTINATION bin)
