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