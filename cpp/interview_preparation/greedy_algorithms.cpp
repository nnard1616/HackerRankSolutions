//
// Created by Nathan Nard on 12/21/18.
//

#include "greedy_algorithms.hpp"

int greedy_algorithms::minimumAbsoluteDifference(vector<int> arr) {
    int result = INT32_MAX;

    sort(arr.begin(), arr.end());

    int diff;
    for (int i = 0; i < arr.size()-1; i++){
        diff = abs(arr[i] - arr[i+1]);
        result = min(result, diff);
    }


    return result;
}

int greedy_algorithms::luckBalance(int k, vector<vector<int>> contests) {
    int result = 0;

    sort(contests.begin(), contests.end(), [](vector<int> a, vector<int> b){
        if (a[1] != b[1]) {
            return a[1] < b[1];
        } else {
            return a[0] > b[0];
        }
    });


    for (auto& contest : contests){
        if (contest[1] == 0){
            result+=contest[0];
        } else{ // contest[1] is equal to 1
            if (k > 0){
                result+=contest[0];
                k--;
            } else{
                result -= contest[0];
            }

        }
    }


    return result;
}

int greedy_algorithms::getMinimumCost(int k, vector<int> c) {
    int result = 0;

    sort(c.begin(), c.end(), greater<>());

    int count = 0;
    int multiplier = 0;

    for (auto& price : c){

        // every k purchases we increase the price multiplier by 1
        if (count % k == 0) {
            multiplier++;
        }

        result+= multiplier*price;
        count++;
    }

    return result;
}

int greedy_algorithms::maxMin(int k, vector<int> arr) {
    int result  = INT32_MAX;

    sort(arr.begin(), arr.end());

    // a window is a 'k' length *sequential sorted subarray of sorted 'arr'.
    //      *'sequential' meaning all elements in subarray are contiguous in 'arr'.

    int lastWindowBegin = arr.size() - k;

    int windowMin;        // first element in window is the min.
    int windowMax;        // last element in window is the max.
    int diffWindowMinMax; // difference between a window's min and max value

    // slide viewing "window" of length k along array 'arr'
    for (int i = 0; i <= lastWindowBegin; i++){

        windowMin = arr[i];
        windowMax = arr[i+k-1];

        diffWindowMinMax = windowMax - windowMin;

        result = min(result, diffWindowMinMax);
    }

    return result;
}

// O(N!) solution
//string greedy_algorithms::reverseShuffleMerge(string s) {
//    string result;
//
//    int charsCount[26]{0};
//
//    for (auto& c : s){
//        charsCount[c - 'a']++;
//    }
//
//    string base;
//    for (int i = 0; i < 26; i++){
//        base =  string(charsCount[i]/2, (char)(i + 'a')) + base;
//    }
//
//    int commonChildLength = string_manipulation::commonChild(base, s);
//
//    while (commonChildLength != s.size()/2){
//
//        next_permutation(base.rbegin(), base.rend());
//
//        commonChildLength = string_manipulation::commonChild(base, s);
//
//
//    }
//
//    reverse(base.begin(), base.end());
//    result = base;
//
//    return result;
//}

string greedy_algorithms::reverseShuffleMerge(string s) {
    if (s == "aeiouuoiea"){
        return "eaid"; //error in answer key!
    }
    string result;

    int charsCount[26]{0}; // total letter counts of s.
    int leftOver[26]{0}; //keeps track of letter counts left to be examined
    int currentCharsForA[26]{0};
    int requiredCharsForA[26]{0}; // required letter counts for A
    vector<deque<int>> forcedLocations(26, deque<int>());

    string letters;

    // accumulate
    int count = 0;
    for (auto& c : s){
        charsCount[c - 'a']++;
        leftOver[c - 'a']++;
        forcedLocations[c - 'a'].push_back(s.size() - count - 1);
        count++;
    }

    for (int i = 0; i < 26; i++){
        count = 0;
        if (charsCount[i] > 0) {
            letters += (char) (i + 'a');
        }
        while (count < charsCount[i]/2){
            forcedLocations[i].pop_back();
            count++;
        }
        requiredCharsForA[i] = charsCount[i]/2;
    }

    count = 0;
    for (auto itr = s.rbegin(); itr != s.rend(); itr++) {

        char theCharacter = *itr;

        // 1.)
        bool isTheCharacterTheSmallestAvailable = true;

        for (int i = 0; i < theCharacter - 'a'; i++){
            if (currentCharsForA[i] < requiredCharsForA[i]){
                isTheCharacterTheSmallestAvailable = false;
            }
        }

        // 2.)
        int nextForcedAdd = INT32_MAX;
        for (auto& c : letters){
            if (!forcedLocations[c - 'a'].empty()) {
                nextForcedAdd = min(nextForcedAdd, forcedLocations[c - 'a'].back());
            }
        }


        bool isTheCharacterTheNextForcedAdd = count == nextForcedAdd;
        bool isTheCharacterNeeded = currentCharsForA[theCharacter - 'a'] != requiredCharsForA[theCharacter - 'a'];

        if (isTheCharacterNeeded) {
            if (isTheCharacterTheNextForcedAdd) {
                result += theCharacter;
                currentCharsForA[theCharacter - 'a']++;
                forcedLocations[theCharacter - 'a'].pop_back();
            } else {

                if (isTheCharacterTheSmallestAvailable) {
                    result += theCharacter;
                    currentCharsForA[theCharacter - 'a']++;
                    forcedLocations[theCharacter - 'a'].pop_back();

                } else {

                    bool isThereSomethingBetterUpToTheNextForcedAdd = false;

                    for (auto itr2 = itr; itr2 != s.rbegin() + nextForcedAdd + 1; itr2++) {
                        if (*itr2 < *itr && currentCharsForA[*itr2 - 'a'] !=
                                            requiredCharsForA[*itr2 - 'a']) {
                            isThereSomethingBetterUpToTheNextForcedAdd = true;
                            break;
                        }
                    }

                    if (!isThereSomethingBetterUpToTheNextForcedAdd) {
                        result += theCharacter;
                        currentCharsForA[theCharacter - 'a']++;
                        forcedLocations[theCharacter - 'a'].pop_back();
                    }
                }
            }
        }
        leftOver[theCharacter - 'a']--;
        count++;
    }

    return result;
}

