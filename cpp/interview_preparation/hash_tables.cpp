//
// Created by Nathan Nard on 12/17/18.
//

#include "hash_tables.hpp"



void hash_tables::checkMagazine(vector<string> magazine, vector<string> note) {

    map<string, int> hash;

    for (auto& m : magazine){
        hash[m]++;
    }

    for (auto& n : note){
        try{
            hash.at(n)--;
            if (hash[n] < 0) {
                cout << "No" << endl;
                return;
            }
        } catch (out_of_range& ex){
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;

}

string hash_tables::twoStrings(string s1, string s2) {
    string result = "NO";

    map<char, int> chars;

    for (auto& c : s1){
        chars[c]++;
    }

    for (auto& c : s2){
        try{
            chars.at(c);
            result = "YES";
            break;
        } catch (out_of_range& ex){
            ;
        }
    }

    return result;
}

int hash_tables::sherlockAndAnagrams(string s) {

    map<string, int> substringCounts;

    string substr;

    for (int substrSize = 1; substrSize < s.size(); substrSize++){
        for (int i = 0; i <= s.size()-substrSize; i++){
            substr = s.substr(i, substrSize);
            sort(substr.begin(), substr.end());
            substringCounts[substr]++;
        }
    }

    int result = 0;
    int count;

    for (auto& pair : substringCounts){

        count = pair.second;
        if (count > 1 ){
            result+= (count*(count-1))/2;
        }
    }

    return result;
}


long hash_tables::countTriplets(vector<long> arr, long r) {
    long result = 0;

    unordered_map<long, long> m2; // nums that singlet(s) are waiting for to make sortedEven doublet
    unordered_map<long, long> m3; // nums that doublet(s) are waiting for to make sortedEven triplet



    for (long n : arr){

        if (m3.count(n)){ // if true, then we have triplet(s)!
            result += m3[n];
        }

        if (m2.count(n)){ // if true, we have doublet(s)!
            m3[n*r] += m2[n];
        }

        m2[n*r]++;
    }


    return result;
}

vector<int> hash_tables::freqQuery(vector<vector<int>> queries) {
    vector<int> result;


    // keeps track of how many elements are in data structure
    // eg: 1, 1, 2, 2, 3 --> (1, 2); (2, 2); (3, 1)  (two ones, two twos, one three)
    unordered_map<int, int> elemCount;

    // keeps track of element frequencies are present
    // eg: 1, 1, 2, 2, 3 --> (2, 2); (1, 1)  (two pairs and one single)
    unordered_map<int, int> freqCount;

    for (auto& q : queries){

        int option = q[0];
        int arg    = q[1];

        switch(option){
            case 1: { //insert elem into data structure

                // decrement frequency count if nonzero
                if (freqCount.count(elemCount[arg]))
                    freqCount[elemCount[arg]]--;

                // increment elem Count due to elem insertion
                elemCount[arg]++;

                // increment new frequency count
                freqCount[elemCount[arg]]++;

                break;
            }
            case 2: { // delete elem from data structure, if present

                // check if elem is present
                if (elemCount[arg] > 0){

                    // decrement frequency count if nonzero
                    if (freqCount.count(elemCount[arg]))
                        freqCount[elemCount[arg]]--;

                    // decrement elem count due to element removal
                    elemCount[arg]--;

                    // increment new frequency count
                    freqCount[elemCount[arg]]++;
                }

                break;
            }
            case 3: { // if there's at least one element with
                      // sortedEven frequency equal to arg, out 1, 0 otherwise

                result.push_back((int)(freqCount[arg] > 0));
                break;
            }
            default:
                throw invalid_argument("Shouldn't have come here!");
        }

    }

    return result;
}

