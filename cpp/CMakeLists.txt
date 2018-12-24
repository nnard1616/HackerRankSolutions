cmake_minimum_required(VERSION 3.12)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp
               main.cpp
               interview_preparation/arrays.cpp
               interview_preparation/arrays.hpp
               common/common.hpp
               Google_Application/practice.hpp
               interview_preparation/hash_tables.cpp
               interview_preparation/hash_tables.hpp
               interview_preparation/sorting.hpp
               interview_preparation/sorting.cpp
               Custom_Datastructures/Priority_Deque.hpp interview_preparation/string_manipulation.cpp interview_preparation/string_manipulation.hpp interview_preparation/greedy_algorithms.cpp interview_preparation/greedy_algorithms.hpp interview_preparation/search.cpp interview_preparation/search.hpp)

add_library(cppStatic STATIC
            interview_preparation/arrays.cpp
            interview_preparation/arrays.hpp
            common/common.hpp
            interview_preparation/hash_tables.cpp
            interview_preparation/hash_tables.hpp
            interview_preparation/sorting.hpp
            interview_preparation/sorting.cpp
            Custom_Datastructures/Priority_Deque.hpp interview_preparation/string_manipulation.cpp interview_preparation/string_manipulation.hpp interview_preparation/greedy_algorithms.cpp interview_preparation/greedy_algorithms.hpp interview_preparation/search.cpp interview_preparation/search.hpp)

enable_testing()
add_subdirectory(unitTests)