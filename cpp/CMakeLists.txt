cmake_minimum_required(VERSION 3.12)
project(cpp)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

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
               Custom_Datastructures/Priority_Deque.hpp interview_preparation/string_manipulation.cpp interview_preparation/string_manipulation.hpp interview_preparation/greedy_algorithms.cpp interview_preparation/greedy_algorithms.hpp interview_preparation/search.cpp interview_preparation/search.hpp cs484/hwk2.cpp cs484/hwk2.hpp)

add_library(cppStatic STATIC
            interview_preparation/arrays.cpp
            interview_preparation/arrays.hpp
            common/common.hpp
            interview_preparation/hash_tables.cpp
            interview_preparation/hash_tables.hpp
            interview_preparation/sorting.hpp
            interview_preparation/sorting.cpp
            Custom_Datastructures/Priority_Deque.hpp interview_preparation/string_manipulation.cpp interview_preparation/string_manipulation.hpp interview_preparation/greedy_algorithms.cpp interview_preparation/greedy_algorithms.hpp interview_preparation/search.cpp interview_preparation/search.hpp cs484/hwk2.cpp cs484/hwk2.hpp)

enable_testing()
add_subdirectory(unitTests)