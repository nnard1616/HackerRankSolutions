cmake_minimum_required(VERSION 3.12)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(commonTest
               commonTest.cpp )

add_executable(cs484Test cs484Test.cpp)

target_link_libraries(commonTest gtest gtest_main )
target_link_libraries(commonTest cppStatic)
target_link_libraries(cs484Test gtest gtest_main )
target_link_libraries(cs484Test cppStatic)