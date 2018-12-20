//
// Created by Nathan Nard on 12/17/18.
//

#ifndef CPP_HASH_TABLES_HPP
#define CPP_HASH_TABLES_HPP
#include <bits/stdc++.h>
#include "../common/common.hpp"


using namespace std;

namespace hash_tables{

    /*
     * https://www.hackerrank.com/challenges/ctci-ransom-note/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
     */
    void checkMagazine(vector<string> magazine, vector<string> note);

    /*
     * https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps&h_r=next-challenge&h_v=zen
     */
    string twoStrings(string s1, string s2);

    /*
     * https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
     */
    int sherlockAndAnagrams(string s);


    /*
     * I cheated on this one...
     * https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
     */
    long countTriplets(vector<long> arr, long r);

    /*
     * https://www.hackerrank.com/challenges/frequency-queries/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps&h_r=next-challenge&h_v=zen
     */
    vector<int> freqQuery(vector<vector<int>> queries);

}
#endif //CPP_HASH_TABLES_HPP
