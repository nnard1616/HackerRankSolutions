//
// Created by Nathan Nard on 2/16/19.
//

#ifndef CPP_HWK2_HPP
#define CPP_HWK2_HPP
#define N 10000
#define nbins 10
#define maxValue 1000

#include "../common/common.hpp"
#include <chrono>
#include <omp.h>

namespace cs484 {
    int question2_vanilla(int* C, int* D);

    int question2_parallel(int* C, int* D);

    string question3_serial(int *data);

    // Expected: {976 1077 948 994 991 1047 1025 957 1036 934}
    string question3_parallel(int *data);
    string question3_better_parallel(int *data);

    int* question4_answer(int* A);
    int* question4_naive(int *D, int size);


    int f(int n);


}

#endif //CPP_HWK2_HPP
