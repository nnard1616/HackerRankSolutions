#include <bits/stdc++.h>
#include "common/common.hpp"
#include "interview_preparation/arrays.hpp"
#include "interview_preparation/hash_tables.hpp"
#include "Google_Application/practice.hpp"
#include "interview_preparation/sorting.hpp"

using namespace std;



int main() {

    deque<int> a{5,6,2,1,2,9,4,5};
    vector<Player> v{Player(100, "amy"),
                     Player(100, "david"),
                     Player(50, "heraldo"),
                     Player(75, "aakansha"),
                     Player(150, "aleksa")};

    deque<int> b;

    b.push_back(4);
    b.push_back(5);

    b.pop_front();

    common::print_container(b);
    cout << a[1] << endl;
    return 0;

}