//
// Created by nathan on 10/22/21.
//

#include "dynamic_programming.hpp"

int dynamic_programming::maxSubsetSum(vector<int> arr) {
    int result = 0 ;
    int n_2 = arr[0];
    int n_1 = max(arr[0], arr[1]);
    int temp;

    for (int i = 2; i < arr.size(); i++) {
        temp = n_2;
        n_2 = n_1;
        n_1 = max(arr[i], n_1);
        n_1 = max(temp + arr[i], n_1);
    }

    result = n_1;



    return result;
}

string dynamic_programming::abbreviation(string a, string b) {
    string result = "YES";
    int scan = 0;
    int i,j;

    int count = 0;


    for (i = 0; i < b.size(); i++) {

        for (j = scan; j < a.size(); j++) {
            scan++;
            if (b[i] == a[j] || b[i] == toupper(a[j])) {
                count++;
                break;
            }
            if (isupper(a[j]) && b[i] != a[j]) {
                return "NO";
            }
        }
    }
    return (count == b.size()) ? "YES" : "NO";
}


string dynamic_programming::abbreviation2(string a, string b) {
    string result = "YES";
    int scan = 0;
    int i,j;
    string constructor = "";
    int i_mem, j_mem;

    for (i = 0; i < b.size(); i++) {

        if ( scan < a.size()) {
            for (j = scan; j < a.size(); j++) {
                scan++;
                if (b[i] == a[j] || b[i] == toupper(a[j])) {
                    if (isupper(a[j])) {
                        i_mem = i;
                        j_mem = j;
                    }
                    constructor.push_back(b[i]);
                    break;
                }
                if (isupper(a[j]) && b[i] != a[j]) {
                    if (i - i_mem > 1) {
                        i = i_mem;
                        j = j_mem;
                        scan = j_mem;
                    } else {
                        return "NO";
                    }
                }
            }
        } else {
            constructor.push_back(b[i]);
        }
    }

    if ( scan < a.size()) {
        for (j = scan; j < a.size(); j++) {
            if (isupper(a[j])) {
                return "NO";
            }
        }
    }
    return (constructor == b) ? "YES" : "NO";

}



bool dynamic_programming::abbreviation_recursion(const char* a, const char* b, const char* a_rend, const char* b_rend, map<pair<const char*, const char*>, bool> &memo) {
    pair<const char*, const char*> p = pair<const char*, const char*>(a, b);
    try {
        return memo.at(p);
    } catch (out_of_range &e) {

        if (a == a_rend && b == b_rend) {
            memo[p] = true;
            return true;
        }

        if (a == a_rend && b != b_rend) {
            memo[p] = false;
            return false;
        }

        if (isupper(*a) && b == b_rend) {
            memo[p] = false;
            return false;

        }

        if (islower(*a) && b == b_rend) {
            memo[p] = abbreviation_recursion(a - 1, b, a_rend, b_rend, memo);
            return memo[p];
        }

        if (*a == *b) {
            memo[p] = abbreviation_recursion(a - 1, b - 1, a_rend, b_rend, memo);
            return memo[p];
        }

        if (toupper(*a) == *b) {
            bool cond1 = abbreviation_recursion(a - 1, b - 1, a_rend, b_rend, memo);
            bool cond2 = abbreviation_recursion(a - 1, b, a_rend, b_rend, memo);
            memo[p] = (cond1 || cond2);
            return memo[p];
        }

        if (isupper(*a) && *a != *b) {
            memo[p] = false;
            return memo[p];
        }

        if (islower(*a) && toupper(*a) != *b) {
            memo[p] = abbreviation_recursion(a - 1, b, a_rend, b_rend, memo);
            return memo[p];
        }
    }

    return false;
}

//https://www.hackerrank.com/challenges/abbr/forum/comments/309236
string dynamic_programming::abbreviation_recursion2(const char* a, const char* b, const char* a_rend, const char* b_rend, map<pair<const char* , const char*>, string> &memo ) {
    if ( a == a_rend && b == b_rend ) {
        return "YES";
    }

    if ( a == a_rend && b != b_rend ) {
        return "NO";
    }

    if ( isupper(*a) && b == b_rend ) {
        return "NO";
    }

    if ( islower(*a) && b == b_rend ) {
        return abbreviation_recursion2(a-1, b, a_rend, b_rend, memo);
    }

    if ( *a == *b ) {
        return abbreviation_recursion2(a-1, b-1, a_rend, b_rend, memo);
    }

    if ( toupper(*a) == *b ) {
        string cond1 = abbreviation_recursion2(a-1, b-1, a_rend, b_rend, memo);
        string cond2 = abbreviation_recursion2(a-1, b, a_rend, b_rend, memo);
        return (cond1 == "YES" || cond2 == "YES") ? "YES" : "NO";
    }

    if ( isupper(*a) && *a != *b ) {
        return "NO";
    }

    if ( islower(*a) && toupper(*a) != *b ) {
        return abbreviation_recursion2(a-1, b, a_rend, b_rend, memo);
    }

    return "ERROR";
}

string dynamic_programming::abbreviation3(string a, string b) {
    map<pair<const char*, const char*>, bool> memo;



    const char* a_rbegin = a.c_str() + a.length() - 1;
    const char* a_rend = a_rbegin - a.length();
    const char* b_rbegin = b.c_str() + b.length() - 1;
    const char* b_rend = b_rbegin - b.length();

    return abbreviation_recursion(a_rbegin, b_rbegin, a_rend, b_rend, memo) ? "YES" : "NO";
}

string dynamic_programming::test_this(std::string::reverse_iterator a) {

    return "hey";
}

//https://www.hackerrank.com/challenges/abbr/forum/comments/725201
string dynamic_programming::abbreviation4(string a, string b) {
    bool memo[a.length()+1][b.length()+1];

    memo[0][0] = true;
    for (int i = 1; i < b.length() + 1; i++) {
        memo[0][i] = false;
    }

    for (int i = 1; i < a.length() + 1; i++ ) {
        if (islower(a[i-1])) {
            memo[i][0] = memo[i-1][0];
        } else {
            memo[i][0] = false;
        }
    }

    for (int i = 1; i < a.length() + 1; i++ ) {
        for (int j = 1; j < b.length() + 1 ; j++ ) {
            memo[i][j] = false;
            if (isupper(a[i-1]) && a[i-1] == b[j-1]) {
                memo[i][j] = memo[i-1][j-1];
            }
            if (islower(a[i-1])) {
                if (toupper(a[i - 1]) == b[j - 1]) {
                    memo[i][j] = memo[i - 1][j - 1] || memo[i - 1][j];
                } else {
                    memo[i][j] = memo[i - 1][j];
                }
            }
        }
    }
    return memo[a.length()][b.length()] ? "YES" : "NO";
}

long dynamic_programming::candies(int n, vector<int> arr) {
    long memo[n];
    memo[0] = 0;

    if (arr.empty()) {
        return 0;
    }

    for (int i = 0; i < n; i++) {
        memo[i] = 1;

        if (i != 0 ) {
            if ( arr[i-1] < arr[i]) {
                memo[i] = memo[i-1] + 1;
            }

            if ( arr[i-1] > arr[i]) {
                memo[i-1]++;
            }
        }
        memo[i] = memo[0] + 1;
    }


    return 0;
}
