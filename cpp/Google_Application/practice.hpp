//
// Created by Nathan Nard on 12/17/18.
//

#ifndef CPP_PRACTICE_HPP
#define CPP_PRACTICE_HPP
#include <bits/stdc++.h>
#include "../common/common.hpp"

using namespace std;
namespace google_application {

    string practiceSolution1(string &S, int K) {
        string result = "";

        int count = 0;

        // iterate from back to front, every K non '-' elements insert '-'
        for (auto itr = S.rbegin(); itr != S.rend(); itr++) {

            if (*itr == '-') {
                continue;
            }

            // determine if we need to insert '-'
            if ((count + 1) % K == 0) {
                result = (char)toupper(*itr) + result;

                // avoid adding '-' at start of string
                if (itr + 1 != S.rend()) {
                    result = "-" + result;
                }

            } else {
                result = (char)toupper(*itr) + result;
            }

            count++;
        }

        return result;
    }

    int solution1(vector<int> &A) {
        unordered_map<int, int> valueToOriginalIndex;
        vector<int> sortedArray = A;
        sort(A.begin(), A.end());
        int result = 0;

        // populate value to index map
        for (int i = 0; i < A.size(); i++){
            valueToOriginalIndex[A[i]] = i;
        }


        // go through all possible starting points
        for (int j = 0; j < A.size(); j++){

            int k = j;
            int jumpCount = 0;

            while (k != A.size()-1){

                jumpCount++;

                // odd jump
                if (jumpCount % 2 == 1){ //odd jump

                    auto position = common::binary_search(A[k], sortedArray);

                    while ( position != sortedArray.end()){

                        if (valueToOriginalIndex[*position] > k){
                            k = valueToOriginalIndex[*position];
                            break;
                        }

                        position++;
                    }

                    if (position == sortedArray.end()){
                        break; // move on to next starting position
                    }
                } else { // even jump

                    auto position = common::binary_search(A[k], sortedArray);

                    while ( position != sortedArray.begin()-1){

                        if (valueToOriginalIndex[*position] > k){
                            k = valueToOriginalIndex[*position];
                            break;
                        }

                        position--;
                    }

                    if (position == sortedArray.begin()-1){
                        break; // move on to next starting position
                    }
                }

                if (k == A.size() -1){
                    result++;
                }
            }
        }
        return result;
    }


    int solution2(vector<int> &S, vector<int> &E) {
        // write your code in C++14 (g++ 6.2.0)
        unordered_map<int, int> timeToGuestArrivals;
        unordered_map<int, int> timeToGuestDepartures;
        int minTime = 1;
        int maxTime = 1000;

        int result = INT32_MIN;
        int concurrentCount = 0;

        for (int i = 0; i < S.size(); i++){
            timeToGuestArrivals[S[i]]++;
            timeToGuestDepartures[E[i]]++;
        }


        for (int time = minTime; time <= maxTime; time++){
            concurrentCount += timeToGuestArrivals[time];
            concurrentCount -= timeToGuestDepartures[time];
            result = max(result, concurrentCount);
        }

        return result;
    }
}
#endif //CPP_PRACTICE_HPP
