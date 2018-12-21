//
// Created by Nathan Nard on 12/20/18.
//

#ifndef CPP_STRING_MANIPULATION_HPP
#define CPP_STRING_MANIPULATION_HPP
#include <bits/stdc++.h>
#include "../common/common.hpp"
using namespace std;

namespace string_manipulation{

    /* Strings: Making Anagrams
     * https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
     */
    int makeAnagram(string a, string b);


    /* Alternating Characters
     * https://www.hackerrank.com/challenges/alternating-characters/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
     */
    int alternatingCharacters(string s);

    /* Sherlock and the Valid String
     * https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings&h_r=next-challenge&h_v=zen
     */
    string isValid(string s);

    /* Special Palindrome Again
     * https://www.hackerrank.com/challenges/special-palindrome-again/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
     */
    long substrCount(int n, string s);

    /* Common Child
     * https://www.hackerrank.com/challenges/common-child/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
     * https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
     */
    int commonChild(string s1, string s2);

}

#endif //CPP_STRING_MANIPULATION_HPP
