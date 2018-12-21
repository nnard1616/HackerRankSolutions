//
// Created by Nathan Nard on 12/19/18.
//

#include "sorting.hpp"


void sorting::countSwaps(vector<int> a) {
    int swaps = 0;

    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < a.size() -1; j++){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swaps++;
            }
        }
    }

    printf("Array is sorted in %d swaps.\n", (swaps));
    printf("First Element: %d\n", (a[0]));
    printf("Last Element: %d\n", (a[a.size()-1]));
}

int sorting::maximumToys(vector<int> prices, int k) {
    int result=0;

    sort(prices.begin(), prices.end());

    int i = 0;
    while (k >= prices[i]){

        k -= prices[i];

        i++; //invariant
    }

    result = i;

    return result;
}

bool sorting::comparator(Player a, Player b) {
    bool result;

    if (a.score == b.score){
        result = a.name < b.name;
    } else {
        result = a.score > b.score;
    }

    return result;
}


int sorting::activityNotifications(vector<int> expenditure, int d) {
    int result = 0;
    double median;

    auto startOfWindow = expenditure.begin();
    auto endOfWindow = expenditure.begin()+d;

    // window is [startOfWindow, endOfWindow), right bound excluded.
    vector<int> window = common::subVector<int>(startOfWindow, endOfWindow);

    // slide window along array.
    // endOfWindow points to the next transaction to be added to the window.
    while (endOfWindow != expenditure.end()){

        if (d % 2 == 0){
            // even median
            median = (window[d/2] + window[d/2-1])/2.0;
        } else{
            // odd median
            median = window[d/2];
        }

        if (*endOfWindow >= 2*median){
            result++;
        }

        // update window
        window.erase(common::binary_search(*startOfWindow, window));
        window.insert(common::binary_search(*endOfWindow, window), *endOfWindow);
        startOfWindow++;
        endOfWindow++;
    }

    return result;
}




