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

// Attempt 2
//string greedy_algorithms::reverseShuffleMerge(string s) {
//            string result;
//
//            int charsCount[26]{0};
//            int leftOver[26]{0};
//            int resultCharsCount[26]{0};
//
//            for (auto& c : s){
//                charsCount[c - 'a']++;
//                leftOver[c - 'a']++;
//            }
//
//            bool canAffordToSkip;
//            bool somethingBetterAhead;
//            bool cantTakeAnyMore;
//
//            int count = 0;
//
//            for (auto itr = s.rbegin(); itr != s.rend(); itr++){
//                char theCharacter = *itr;
//
//                int a = resultCharsCount[theCharacter - 'a'];
//                int b = charsCount[theCharacter - 'a']/2;
//                cantTakeAnyMore      = ( a == b);
//                canAffordToSkip      = (leftOver[theCharacter - 'a']-1 >= charsCount[theCharacter - 'a']/2);
//                somethingBetterAhead = false;
//
//        for (int i = 0; i < theCharacter - 'a'; i++) {
//            if (charsCount[i] != 0) {
//                if (leftOver[i] >= charsCount[i] / 2) {
//                    somethingBetterAhead = true;
//                    break;
//                }
//            }
//        }
//
//        if ((!canAffordToSkip || !somethingBetterAhead) && !cantTakeAnyMore){
//            result = theCharacter + result;
//            resultCharsCount[theCharacter - 'a']++;
//            count++;
//        }
//
//        leftOver[theCharacter - 'a']--;
//
//        if (count == s.size()/2){
//            break;
//        }
//    }
//
//    reverse(result.begin(), result.end());
//
//    return result;
//}

//string greedy_algorithms::reverseShuffleMerge(string s) {
//    string result;
//
//    int charsCount[26]{0}; // total letter counts of s.
//    int requiredCharsForA[26]{0}; // required letter counts for A
//    int leftOver[26]{0}; //keeps track of letter counts left to be examined
//    int currentCharsForA[26]{0};
//
//
//
//    // accumulate
//    for (auto& c : s){
//        charsCount[c - 'a']++;
//        leftOver[c - 'a']++;
//    }
//
//    // divide by 2
//    for (int i = 0; i < 26; i++){
//        requiredCharsForA[i] = charsCount[i]/2;
//    }
//
//    int count = 0;
//    for (auto itr = s.rbegin(); itr != s.rend(); itr++){
//        if (count == 47){
//            cout << "here" << endl;
//        }
//        char theCharacter = *itr;
//        cout << "The character: " << theCharacter << " is located at: " << distance(s.rbegin(), itr) << endl;
//        cout << "'" << theCharacter << "' characters collected so far: " << currentCharsForA[theCharacter -'a'] << " out of: " << requiredCharsForA[theCharacter - 'a'] << " required." << endl;
//        cout << "How many '" << theCharacter << "' characters are left to see: " << leftOver[theCharacter - 'a']-1 << endl;
//
//        bool canLetterRequirementBeFulfilledLater = (leftOver[theCharacter - 'a'] - 1 >= requiredCharsForA[theCharacter - 'a']);
//
//        if (canLetterRequirementBeFulfilledLater){
//            // we're able to skip if we want.
//
//            bool isThereSomethingBetterAhead = false;
//
//
//            for (int i = 0; i < theCharacter - 'a'; i++) {
//                if (charsCount[i] != 0) {
//                    if (leftOver[i] >= requiredCharsForA[i] && currentCharsForA[i] != requiredCharsForA[i]) {
//                        isThereSomethingBetterAhead = true;
//                        break;
//                    }
//                }
//            }
//
//            if (!isThereSomethingBetterAhead){
//                cout << "We have a good letter: " << theCharacter << ", results of adding: " << endl;
//                currentCharsForA[theCharacter - 'a']++;
//                result+=theCharacter;
//                cout << "'" << theCharacter << "' characters collected so far: " << currentCharsForA[theCharacter -'a'] << " out of: " << requiredCharsForA[theCharacter - 'a'] << " required." << endl;
//
//            }
//
//
//        } else{
//
//
//            if (currentCharsForA[theCharacter - 'a'] != requiredCharsForA[theCharacter - 'a']) {
//                cout << "We are forced to take the letter: " << theCharacter << ", results of adding: " << endl;
//                currentCharsForA[theCharacter - 'a']++;
//                result += theCharacter;
//                cout << "'" << theCharacter << "' characters collected so far: " << currentCharsForA[theCharacter -'a'] << " out of: " << requiredCharsForA[theCharacter - 'a'] << " required." << endl;
//
//            }
//
//        }
//
//
//        cout << endl;
//        count++;
//        leftOver[theCharacter - 'a']--;
//    }
//
//    return result;
//}


string greedy_algorithms::reverseShuffleMerge(string s) {
    string result;

    int charsCount[26]{0}; // total letter counts of s.
    int leftOver[26]{0}; //keeps track of letter counts left to be examined
    int currentCharsForA[26]{0};
    int requiredCharsForA[26]{0}; // required letter counts for A
    vector<queue<int>> forcedLocations(26, queue<int>());



    // accumulate
    int count = 0;
    for (auto& c : s){
        charsCount[c - 'a']++;
        leftOver[c - 'a']++;
        forcedLocations[c - 'a'].push(s.size() - count - 1);
        count++;
    }

    for (int i = 0; i < 26; i++){
        count = 0;
        while (count < charsCount[i]/2){
            forcedLocations[i].pop();
            count++;
        }
        requiredCharsForA[i] /= 2;
    }

//    count = 0;
    for (auto itr = s.rbegin(); itr != s.rend(); itr++) {
        char theCharacter = *itr;
        int howManyOfTheCharacterAreLeftToSee    = leftOver[theCharacter - 'a'] - 1;
        int howManyOfTheCharacterAreRequiredForA = requiredCharsForA[theCharacter - 'a'];

        bool canLetterRequirementBeFulfilledLater = (howManyOfTheCharacterAreLeftToSee >= howManyOfTheCharacterAreRequiredForA);

        bool isTheCharacterTheSmallestAvailable = true;

        for (int i = 0; i < theCharacter - 'a'; i++){
            if (currentCharsForA[i] < requiredCharsForA[i]){
                isTheCharacterTheSmallestAvailable = false;
            }
        }

        bool isThereSomethingBetterUpToTheNextForcedAdd = false;

        int nextForcedAdd = INT32_MAX;
        for (int i = 0; i < 26; i++){
            nextForcedAdd = min(nextForcedAdd, forcedLocations[i].front());
        }

    }



    return result;
}

