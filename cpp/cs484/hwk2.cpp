//
// Created by Nathan Nard on 2/16/19.
//

#include "hwk2.hpp"



int cs484::question2_vanilla(int* C, int*D){

    int k = 0;
    float x = 999999.0;

    int i,j;

    auto start = chrono::high_resolution_clock::now();
    for (i = 0; i < N; i++) {
        k += 4;
        for (j = k; j < N; j++) {
            C[i] += D[j] * 3;
        }
        if (C[i] < x) {
            x = C[i];
        }
    }
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Vanilla run time: " << duration.count() << " ms" << endl;
    return x;
}

int cs484::question2_parallel(int* C, int*D){
    int k = 0;
    float x = 999999.0;

    int i,j;

    auto start = chrono::high_resolution_clock::now();
    #pragma omp parallel private(i,j,k)
    {
        int id = omp_get_thread_num();
        int p = omp_get_num_threads();

        int sub1 = (N - 4) / 4;
        int mystart1 = (sub1*id)/p;
        int myend1   = (sub1*(id+1))/p;

        int sub2 = N - sub1;
        int mystart2 = (sub2*id)/p + sub1;
        int myend2   = (sub2*(id+1))/p + sub1;

        //account for 0 modulo
        if (id == (p-1)) {
            myend1 = sub1;
            myend2 = N;
        }

        for (i = mystart1; i < myend2; ((i+1)==myend1) ? i=mystart2 : i++) {
            k = 4*i+4;
            for (j = k; j < N; j++) {
                C[i] += D[j] * 3;
            }
            if (C[i] < x){
                x = C[i];
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();


    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << "Parallel run time: " << duration.count() << " ms" << endl;
    return x;
}

string cs484::question3_better_parallel(int *data) {

    int max_bin_size = 0;
    int *hist = (int *) malloc(sizeof(int)*nbins);


    auto start = chrono::high_resolution_clock::now();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        int bin = f(data[i]);
        #pragma omp atomic
        hist[bin] += 1;
    }

    #pragma omp parallel for reduction(max:max_bin_size)
    for (int i = 0; i < nbins; i++) {
        max_bin_size = max(hist[i], max_bin_size);
    }

    auto end = chrono::high_resolution_clock::now();
    cout << "Max: " << max_bin_size << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Better Parallel run time: " << duration.count() << " us" << endl;
    ostringstream ss;
    for (int i = 0; i < nbins; i++){
        ss << hist[i] << " ";
    }

    return ss.str();
}

string cs484::question3_parallel(int *data) {

    int max_bin_size = 0;
    int *hist = (int *) malloc(sizeof(int)*nbins);


    auto start = chrono::high_resolution_clock::now();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        int bin = f(data[i]);
        hist[bin] += 1;
        #pragma omp critical
        {
            if (hist[bin] > max_bin_size) {
                max_bin_size = hist[bin];
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "Max: " << max_bin_size << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Parallel run time: " << duration.count() << " us" << endl;
    ostringstream ss;
    for (int i = 0; i < nbins; i++){
        ss << hist[i] << " ";
    }

    return ss.str();
}

string cs484::question3_serial(int *data) {
    int max_bin_size = 0;
    int *hist = (int *) malloc(sizeof(int)*nbins);

    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        int bin = f(data[i]);
        hist[bin] += 1;
    }

    for (int i = 0; i < nbins; i++) {
        max_bin_size = max(hist[i], max_bin_size);
    }

    auto end = chrono::high_resolution_clock::now();

    cout << "Max: " << max_bin_size << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Serial run time: " << duration.count() << " us" << endl;
    ostringstream ss;
    for (int i = 0; i < nbins; i++){
        ss << hist[i] << " ";
    }

    return ss.str();
}

int cs484::f(int n) {
    return n/(maxValue/nbins);
}

int* cs484::question4_answer(int* A) {
    int num_threads = omp_get_max_threads();
    int n = N; // N is a macro
    int* B = (int*)malloc(sizeof(int)*N);
    int* oddCnt = new int[num_threads] {0};
    int* evenCnt = new int[num_threads] {0};

    auto start = chrono::high_resolution_clock::now();
    #pragma omp parallel shared(A, B, oddCnt, evenCnt, num_threads, n)
{
    /* a) Compute start and end indices for each thread */
    int id = omp_get_thread_num();

    int mystart = (id*n)/num_threads;
    int myend   = ((id+1)*n)/num_threads;

    if (id == num_threads-1) myend = n;


    /* b) Count how many odd and even numbers there are in each thread’s region, update
    oddCnt and evenCnt appropriately */

    for (int i = mystart; i < myend; i++){
        if (A[i] % 2 == 0)
            evenCnt[id]++;
        else
            oddCnt[id]++;
    }

    /* c) Compute prefix sums of oddCnt and evenCnt arrays (done by one thread only). */

    #pragma omp barrier
    #pragma omp single
    for (int i = 1; i < num_threads; i++){
        oddCnt[i] += oddCnt[i-1];
        evenCnt[i] += evenCnt[i-1];
    }

    /* d) Each thread then iterates through own local region again and, for each odd and
    even number, determine what position in array B it must go to (using oddCnt and
    evenCnt and any additional variables you might have declared) and update B. */
    int evenStart = oddCnt[num_threads-1];
    int evenIndex = (id == 0) ? evenStart : evenCnt[id-1]+evenStart;
    int oddIndex  = (id == 0) ? 0 : oddCnt[id-1];

    for (int i = mystart; i < myend; i++){
        if (A[i] % 2 == 0){
            B[evenIndex] = A[i];
            evenIndex++;
        } else {
            B[oddIndex] = A[i];
            oddIndex++;
        }
    }
}
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Parallel run time: " << duration.count() << " us" << endl;
    return B;
}

int* cs484::question4_naive(int *D, int size) {
    int* P = new int[size];

    auto start = chrono::high_resolution_clock::now();
    int j = 0;
    for (int i = 0; i < size; i++){
        if (D[i] % 2 != 0){
            P[j] = D[i];
            j++;
        }
    }

    for (int i = 0; i < size; i++){
        if (D[i] % 2 == 0){
            P[j] = D[i];
            j++;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "Serial run time: " << duration.count() << " us" << endl;
    return P;
}
