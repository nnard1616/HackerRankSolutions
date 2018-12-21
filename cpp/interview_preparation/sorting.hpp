//
// Created by Nathan Nard on 12/19/18.
//

#ifndef CPP_SORTING_HPP
#define CPP_SORTING_HPP


#include <bits/stdc++.h>
#include <ostream>
#include "../common/common.hpp"

using namespace std;

struct Player{
    Player(int score, string name){
        this->score = score;
        this->name  = name;
    }
    int score;
    string name;

    friend ostream &operator<<(ostream &os, const Player &player) {
        os << player.name << " " << player.score << endl;
        return os;
    }
};

namespace sorting{

    static long COUNT = 0;

    /*
     * Bubble Sort
     * https://www.hackerrank.com/challenges/ctci-bubble-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
     */
    void countSwaps(vector<int> a);

    /*
     * Mark and Toys
     * https://www.hackerrank.com/challenges/mark-and-toys/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting&h_r=next-challenge&h_v=zen
     */
    int maximumToys(vector<int> prices, int k);

    /*
     * Comparator
     * https://www.hackerrank.com/challenges/ctci-comparator-sorting/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
     */
    bool comparator(Player a, Player b);

    /*
     * Fraudulent Activity Notifications
     * https://www.hackerrank.com/challenges/fraudulent-activity-notifications/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen&h_r=next-challenge&h_v=zen
     */
    int activityNotifications(vector<int> expenditure, int d);

    template<class T>
    vector<T> merge (vector<T> arr1, vector<T> arr2){
        vector<T> merged;
        int i = 0, j = 0, remainingInLeft;
        int mergedSize = arr1.size()+arr2.size();
        merged.resize(mergedSize);

        for (int k = 0; k < mergedSize; k++){

            // check if ran out of stuff in left side, then just fill in rest of right
            if ( i == arr1.size()){
                merged[k] = arr2[j];
                j++;
                continue;
            }

            // check if ran out of stuff in right side, then just fill in res of left.
            if ( j == arr2.size()){
                merged[k] = arr1[i];
                i++;
                continue;
            }

            if (arr1[i] <= arr2[j]){
                merged[k] = arr1[i];
                i++;
            } else {
                merged[k] = arr2[j];
                j++;
                remainingInLeft = arr1.size() - i;
                sorting::COUNT += (long)remainingInLeft;
            }
        }
        return merged;
    }

    template<class T>
    vector<T> mergeSort (vector<T> arr){
        //base case
        if (arr.size() <= 1){
            return arr;
        }

        auto halfPoint = arr.begin() + arr.size()/2;

        vector<T> left(arr.begin(), halfPoint), right(halfPoint, arr.end());

        left = mergeSort(left);
        right = mergeSort(right);

        return merge(left, right);
    }


    /*
     * Merge Sort: Counting Inversions
     * https://www.hackerrank.com/challenges/ctci-merge-sort/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=sorting
     */
    template<class T>
    long countInversions(vector<T> arr) {
        COUNT = 0;


        arr = mergeSort(arr);

        common::print_container(arr);

        return COUNT;
    }
}





#endif //CPP_SORTING_HPP
