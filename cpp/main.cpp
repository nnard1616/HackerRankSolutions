#include <bits/stdc++.h>
#include "common/common.hpp"
#include "interview_preparation/arrays.hpp"
#include "interview_preparation/hash_tables.hpp"
#include "Google_Application/practice.hpp"
#include "interview_preparation/sorting.hpp"

using namespace std;



int main() {

    vector<int> a{10, 20, 30, 40, 70, 10, 10, 10, 10, 10};
    vector<Player> v{Player(100, "amy"),
                     Player(100, "david"),
                     Player(50, "heraldo"),
                     Player(75, "aakansha"),
                     Player(150, "aleksa")};


    int b = sorting::activityNotifications(a, 3);
    cout << b << endl;
    return 0;

}