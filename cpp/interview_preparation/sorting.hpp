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
}





#endif //CPP_SORTING_HPP
