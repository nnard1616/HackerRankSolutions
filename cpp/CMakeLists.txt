cmake_minimum_required(VERSION 3.2)
project(cpp)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -D_DEBUG")
endif()

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        main.cpp
        interview_preparation/arrays.cpp
        interview_preparation/hash_tables.cpp
        interview_preparation/sorting.cpp
        interview_preparation/string_manipulation.cpp
        interview_preparation/greedy_algorithms.cpp
        interview_preparation/search.cpp
        cs484/hwk2.cpp
        interview_preparation/dynamic_programming.cpp
        interview_preparation/stacks_and_queues.cpp

)

set(HEADER_FILES
        interview_preparation/arrays.hpp
        common/common.hpp
        Google_Application/practice.hpp
        interview_preparation/hash_tables.hpp
        interview_preparation/sorting.hpp
        Custom_Datastructures/Priority_Deque.hpp
        interview_preparation/string_manipulation.hpp
        interview_preparation/greedy_algorithms.hpp
        interview_preparation/search.hpp
        cs484/hwk2.hpp
        interview_preparation/dynamic_programming.hpp
        interview_preparation/stacks_and_queues.hpp
)

add_executable(cpp ${SOURCE_FILES} interview_preparation/stacks_and_queues.cpp interview_preparation/stacks_and_queues.hpp)

add_library(cppStatic STATIC
            ${SOURCE_FILES})

enable_testing()
add_subdirectory(unitTests)