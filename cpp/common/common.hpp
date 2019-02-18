//
// Created by Nathan Nard on 12/2/18.
//

#ifndef CPP_COMMON_HPP
#define CPP_COMMON_HPP

#include <bits/stdc++.h>

using namespace std;

namespace common{
    static vector<string> split_string(string input_string) {
        string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
            return x == y and x == ' ';
        });

        input_string.erase(new_end, input_string.end());

        while (input_string[input_string.length() - 1] == ' ') {
            input_string.pop_back();
        }

        vector<string> splits;
        char delimiter = ' ';

        size_t i = 0;
        size_t pos = input_string.find(delimiter);

        while (pos != string::npos) {
            splits.push_back(input_string.substr(i, pos - i));

            i = pos + 1;
            pos = input_string.find(delimiter, i);
        }

        splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

        return splits;
    }

    template<class IterableContainer>
    static void print_container(IterableContainer in){

        for (auto& i : in){
            cout << i << " ";
        }

        cout << endl;
    }

    template<class TwoDIterableContainer>
    static void print_2Dcontainer(TwoDIterableContainer in){

        for (auto& i : in){
            common::print_container(i);
        }

    }

    template<class PrintableObject>
    static void print_array(PrintableObject a[], int s){
        for (int i = 0; i < s; i++){
            cout << a[i] << " ";
        }

        cout << endl;
    }

    template<class PrintableObject>
    static void print_2Darray(PrintableObject** a, int I, int J){
        for (int i = 0; i < I; i++){
            print_array(a[i], J);
        }

        cout << endl;
    }

    // returns iterator pointing either to a position with value equal to query (no guarantees which one if duplicates)
    // or pointing to position where a value equal to query should be inserted to maintain sorted order.
    template<class Comparable, class RandomAccessIterableContainer>
    static typename RandomAccessIterableContainer::iterator binary_search(const Comparable& query, RandomAccessIterableContainer& in){

        typedef typename RandomAccessIterableContainer::iterator iterator;

        iterator result;
        iterator lower = in.begin();
        iterator upper = in.end();

        // empty condition
        if (in.size() ==0){
            return in.begin();
        }

        // lower boundary condition
        if (query < *lower ){
            return in.begin();
        }

        // upper boundary condition
        if (query > *(upper-1)){
            return in.end();
        }

        // middle
        result = lower + (upper - lower)/2;

        // keep moving upper and lower until next to each other.
        while ((upper - lower) != 1){

            if (query < *result){
                upper = result;
            } else if (query > *result){
                lower = result;
            } else{
                return result;
            }

            // update middle
            result = lower + (upper - lower)/2;
        }

        // decide if insert at lower or upper (they're next to each other)
        if (query > *lower) {
            result = upper;
        } else if (query < *upper) {
            result = lower;
        }

        return result;
    }

    template<class Iterator>
    static void swap(Iterator a, Iterator b){
        auto temp = *b;
        *b = *a;
        *a = temp;
    }

    template<class RandomAccessIterator>
    static RandomAccessIterator partition(RandomAccessIterator& left, RandomAccessIterator& right){

        //assuming left is the pivot point
        auto pivot = *left;

        RandomAccessIterator i = left+1;

        // place elements smaller than pivot to the left side
        for (auto j = left + 1; j <= right; j++){
            if (*j < pivot){
                swap(i++, j);
            }
        }

        // i now points to 1 position past where the pivot needs to be located
        // put pivot at i's last position to put pivot in rightful place.
        swap(left, i-1);

        return i - 1;

    }

    template<class RandomAccessIterator>
    static RandomAccessIterator rselect(int ithStatistic,
                                        RandomAccessIterator& begin,
                                        RandomAccessIterator& end){

        // base case
        if ((end - begin) == 0)
            return begin;

        // randomly pick pivot
        RandomAccessIterator pivot = begin + rand() % (end - begin);

        // switches first element with chosen pivot
        common::swap(pivot, begin);

        // partition returns index of new pivot, j
        RandomAccessIterator newPivot = partition(begin, end);


        // if the new pivot point is at the ithstatic, we're done
        if ( (newPivot - begin) == ithStatistic ){
            return pivot;

            // else check if newPivot is above the ithstatic...
        } else if ((newPivot - begin) > ithStatistic){

            // then check for ithstatistic in left half of array
            return rselect(ithStatistic, begin, newPivot);

            // else check for adjusted ithstatistic in right half of array
        } else {

            int adjustedIthStatistic = ithStatistic-(newPivot-begin)-1;
            RandomAccessIterator subBegin = newPivot+1;

            return rselect(adjustedIthStatistic, subBegin, end);
        }


    }

    template<typename T>
    vector<T> subVector(typename vector<T>::iterator begin, typename vector<T>::iterator end){
        vector<T> result;
        for (auto itr = begin; itr != end; itr++){
            result.insert(common::binary_search(*itr, result), *itr);
        }
        return result;
    }


}
#endif //CPP_COMMON_HPP
