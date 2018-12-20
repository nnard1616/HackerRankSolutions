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

    auto b = expenditure.begin();
    auto e = expenditure.begin()+d;
    vector<int> window = common::subVector<int>(b, e);
    while (e != expenditure.end()){

        if (d % 2 == 0){
            median = (window[d/2] + window[d/2-1])/2.0;
        } else{
            median = window[d/2];
        }

        if (*e >= 2*median){
            result++;
        }
        
        window.erase(common::binary_search(*b, window));
        window.insert(common::binary_search(*e, window), *e);
        b++;
        e++;
    }

    return result;
}

