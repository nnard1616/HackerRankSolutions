#include <bits/stdc++.h>
#include <omp.h>
#include "common/common.hpp"
#include "interview_preparation/arrays.hpp"
#include "interview_preparation/hash_tables.hpp"
#include "Google_Application/practice.hpp"
#include "interview_preparation/sorting.hpp"
#include "interview_preparation/string_manipulation.hpp"
#include "interview_preparation/greedy_algorithms.hpp"
#include "interview_preparation/search.hpp"
#include "interview_preparation/dynamic_programming.hpp"
#include "interview_preparation/stacks_and_queues.hpp"
#include "cs484/hwk2.hpp"

#define SIZE 10000000
#define IND(row,col,n) ((row)*n+(col))

using namespace std;
using namespace chrono;

void add1(float* a, float* b, float* c){
    for (int i = 0; i < SIZE; i++ ){
        c[i] += a[i] + b[i];
    }
}

void add2(float * __restrict__ a, float * __restrict__ b, float * __restrict__ c){
    for (int i = 0; i < SIZE; i++ ){
        c[i] += a[i] + b[i];
    }
}

int convert2dTo1d(int q, int r, int n){
    return q*n+r;
}

void multiply_tiled(int* A, int* B, int* C, int n, int tile_size) {
    // TODO: implement this function.
    for (int i = 0; i < n; i+= tile_size){
        for (int j = 0; j < n; j+= tile_size){
            for(int k = 0; k < n; k += tile_size) {
                for (int p = 0; p < tile_size; p++) {
                    for (int q = 0; q < tile_size; q++) {
                        for (int r = 0; r < tile_size; r++) {
                            C[IND(i+p,j+q,n)] += A[IND(i+p,k+r,n)] * B[IND(k+r,j+q,n)];
                        }
                    }
                }
            }
        }
    }
}

void multiply_transpose(int* A, int* B_T, int* C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[IND(i,j,n)] += A[IND(i,k,n)] * B_T[IND(j,k,n)];
            }
        }
    }
}


int dot_product(int* A, int* B, int n) {
    int res = 0;
    for (int i = 0; i < n; i++){
        res += A[i]*B[i];
    }
    return res;
}

void matrix_multiply(int** A, int** B, int** C, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                cout << A[i][k] << " * " << B[k][j] << endl;
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transpose_basic(double* A, double* B, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[IND(i,j,n)] = A[IND(j,i,n)];
        }
    }
}

int test_openmp(){

    #pragma omp parallel for
    for(int i=0;i<10;i++){
        printf("%i\n",i);
    }
    return 0;
}

void testRestructuring(){
    int a[] = {1,2,3,4};
    int b[] = {5,6,7,8};
    int c[] = {9,10,11,12};
    int d[] = {13,14,15,16};

    for (int i = 0; i < 3; i++) {
        int t1;


        t1 = d[i] - b[i];
        a[i + 1] = t1 * t1;
    }


    for (int i = 0; i < 3; i++) {
        int t;

        t = a[i] + b[i];
        c[i] = t + t;


    }

    // 1 64 64 64
    common::print_array(a, 4);

    // 12 140 142 12
    common::print_array(c, 4);

}



int main() {

    int a[] = {1,2,3,4,5};
    vector<int> av (a, a+5);
    string s = "{{}(";




    auto start = chrono::high_resolution_clock::now();

    cout << stacks_and_queues::largestRectangle(av) << endl;

    auto end = chrono::high_resolution_clock::now();


    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Run time: " << duration.count() << " ms" << endl;

//    string b = "asdf";
//    const char* b_begin = b.c_str();
//    const char* b_rbegin = b.c_str() + b.length() - 1;
//    const char* b_rend = b_rbegin - b.length();
//
//    bool m[b.length()+1][b.length()+1];
//    m[2][2] = false;
//    m[2][2] = 253;
//    cout << (m[2][2]) << endl;
}