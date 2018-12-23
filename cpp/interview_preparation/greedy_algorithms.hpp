//
// Created by Nathan Nard on 12/21/18.
//

#ifndef CPP_GREEDY_ALGORITHMS_HPP
#define CPP_GREEDY_ALGORITHMS_HPP
#include <bits/stdc++.h>
#include "../common/common.hpp"
#include "../interview_preparation/string_manipulation.hpp"

using namespace std;

namespace greedy_algorithms{

    /* Minimum Absolute Difference in an Array
     * https://www.hackerrank.com/challenges/minimum-absolute-difference-in-an-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
     */
    int minimumAbsoluteDifference(vector<int> arr);

    /* Luck Balance
     * https://www.hackerrank.com/challenges/luck-balance/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
     */
    int luckBalance(int k, vector<vector<int>> contests);

    /* Greedy Florist
     * https://www.hackerrank.com/challenges/greedy-florist/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms&h_r=next-challenge&h_v=zen
     */
    int getMinimumCost(int k, vector<int> c);

    /* Max Min
     * https://www.hackerrank.com/challenges/angry-children/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
     */
    int maxMin(int k, vector<int> arr);

    /* Reverse Shuffle Merge
     * https://www.hackerrank.com/challenges/reverse-shuffle-merge/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=greedy-algorithms
     */
    string reverseShuffleMerge(string s);



}
#endif //CPP_GREEDY_ALGORITHMS_HPP
