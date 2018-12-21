//
// Created by Nathan Nard on 12/20/18.
//

#include "string_manipulation.hpp"

int string_manipulation::makeAnagram(string a, string b) {
    int result = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;

    string common;


    while (i != a.size() && j != b.size()){
        if (a[i] == b[j]){
            common += a[i];
            i++;
            j++;
            continue;
        }

        if (a[i] > b[j]){
            j++;
            continue;
        }

        if (a[i] < b[j]){
            i++;
            continue;
        }
    }

    result += (a.size() - common.size()) + (b.size() - common.size());


    return result;
}

int string_manipulation::alternatingCharacters(string s) {
    int result = 0;

    for (auto itr = s.begin(); itr != s.end(); itr++){
        if (*itr == *(itr+1)){
            s.erase(itr);
            itr--;
            result++;
        }
    }

    return result;
}

string string_manipulation::isValid(string s) {
    string result = "YES";

    int charsCount[26]{0};

    for (auto& c : s){
        charsCount[c - 'a']++;
    }

    int count = charsCount[s[0] - 'a'];
    bool justOneDeleted = false;

    for (auto& charCount : charsCount){
        if (charCount != 0) {
            if (charCount != count) {
                if ( (abs(charCount - count) == 1 || charCount ==1) && !justOneDeleted){
                    justOneDeleted = true;
                    continue;
                }
                result = "NO";
                break;
            }
        }
    }

    return result;
}

// O(n^2)
long string_manipulation::substrCount(int n, string s) {
    long result = (long)n;

    int spread;

    for (auto itr = s.begin(); itr != s.end(); itr++){

        spread = 1;
        while (itr+spread != s.end() ){

            if (*(itr+spread) != *(itr)){
                break;
            } else{
                // prevent double counting of odd length substrings
                if (spread % 2 == 1)
                    result++;
            }

            spread++;
        }

        spread = 1;
        char sim = *(itr+spread);
        while (itr+spread != s.end() && itr-spread != s.begin()-1){

            if (*(itr+spread) != sim || sim != *(itr-spread)){
                break;
            } else{
                result++;
            }

            spread++;
        }
    }

    return result;
}

int string_manipulation::commonChild(string s1, string s2) {
    int result = 0;

    s1 = "0" + s1;
    s2 = "0" + s2;


    vector<vector<int>> mem(s1.size(), vector<int>(s2.size()));

    for (int i = 1; i < s1.size(); i++){
        for (int j = 1; j < s2.size(); j++){
            if (s1[i] == s2[j]){
                mem[i][j] = mem[i-1][j-1] + 1;
            } else{
                mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
            }
        }
    }

    result = mem[s1.size()-1][s2.size()-1];

    return result;
}
