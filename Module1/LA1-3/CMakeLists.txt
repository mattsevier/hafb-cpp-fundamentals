# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(LA1-3 LANGUAGES CXX)

# require C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create a Static Library
add_library(my_function 
  STATIC
    my_function.h
    my_function.cpp
  )




# Note: In windows, the executable name will be: main.exe
add_executable(main_name main.cpp)

target_link_libraries(main_name my_function) # Link Library
