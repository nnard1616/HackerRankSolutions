#include <bits/stdc++.h>
#include "common/common.hpp"
#include "interview_preparation/arrays.hpp"
#include "interview_preparation/hash_tables.hpp"
#include "Google_Application/practice.hpp"
#include "interview_preparation/sorting.hpp"
#include "interview_preparation/string_manipulation.hpp"
#include "interview_preparation/greedy_algorithms.hpp"

using namespace std;



int main() {

    vector<int> a{-59, -36, -13, 1, -53, -92, -2, -96, -54, 75};
    queue<int> b;

    vector<vector<int>> c{vector<int>{5,1},
                          vector<int>{2,1},
                          vector<int>{1,1},
                          vector<int>{8,1},
                          vector<int>{10,0},
                          vector<int>{5,0}};

    b.push(5);
    b.push(6);
    cout << b.front() << " " << b.back() << endl;

//    cout << greedy_algorithms::reverseShuffleMerge("djjcddjggbiigjhfghehhbgdigjicafgjcehhfgifadihiajgciagicdahcbajjbhifjiaajigdgdfhdiijjgaiejgegbbiigida") << endl;

    // should be: aaaaabccigicgjihidfiejfijgidgbhhehgfhjgiibggjddjjd
    // was actua: aaaaabcciicjiidigfhejgfijgidgbhhehgfhjgiibggjddjjd
    //            aaaaabciicjiidigfhecjgfijgidgbhhehgfhjgiibggjddjjd

    return 0;

}