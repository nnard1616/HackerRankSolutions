//
// Created by nathan on 10/22/21.
//

#ifndef CPP_DYNAMIC_PROGRAMMING_HPP
#define CPP_DYNAMIC_PROGRAMMING_HPP
#include <bits/stdc++.h>
#include "../common/common.hpp"

using namespace std;

namespace dynamic_programming{
    /**
     *
     * @param arr
     * @return
     */
    int maxSubsetSum(vector<int> arr);

    /**
     *
     */
    string abbreviation(string a, string b);

    string abbreviation2(string a, string b);

    string abbreviation3(string a, string b);

    string test_this (std::string::reverse_iterator a);

    string abbreviation_recursion(const char *a, const char *b, const char *a_rend, const char *b_rend,
                                  map<pair<const char *, const char *>, string> &memo);

    string abbreviation_recursion2(const char *a, const char *b, const char *a_rend, const char *b_rend,
                                   map<pair<const char *, const char *>, string> &memo);

    bool abbreviation_recursion(const char *a, const char *b, const char *a_rend, const char *b_rend,
                                  map<pair<const char *, const char *>, bool> &memo);
    bool abbreviation_recursion(const char *a, const char *b, const char *a_rend, const char *b_rend,
                                map<const char *, bool> &memo);

    bool abbreviation_recursion(const char *a, const char *b, const char *a_rend, const char *b_rend,
                                map<const char *, bool> &memo, map<const char *, bool> &memo2);

    string abbreviation4(string a, string b);
}
#endif //CPP_DYNAMIC_PROGRAMMING_HPP
